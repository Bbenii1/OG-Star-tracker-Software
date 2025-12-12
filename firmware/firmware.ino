#include <ArduinoJson.h>
#include <ESPmDNS.h>
#include <ErriezSerialTerminal.h>
#include <WebServer.h>
#include <WiFi.h>
#include <esp_wifi.h>
#include <freertos/FreeRTOS.h>
#include <string.h>

#include "axis.h"
#include "commands.h"
#include "common_strings.h"
#include "config.h"
#include "hardwaretimer.h"
#include "intervalometer.h"
#include "uart.h"
#include "i18n/web_languages.h"
#include "web/web_handlers.h"

SerialTerminal term(CLI_NEWLINE_CHAR, CLI_DELIMITER_CHAR);
WebServer server(WEBSERVER_PORT);
Languages language = EN;

void uartTask(void* pvParameters);
void consoleTask(void* pvParameters);
void webserverTask(void* pvParameters);
void intervalometerTask(void* pvParameters);


void setup()
{
    // Start the debug serial connection
    setup_uart(&Serial, 115200);

    // start UART task before any usage of print_out
    if (xTaskCreate(uartTask, "uart", 4096, NULL, 1, NULL))
    {
        print_out_tbl(TSK_CLEAR_SCREEN);
        print_out_tbl(TSK_START_UART);
    }

    print_out_tbl(HEAD_LINE);
    print_out_tbl(HEAD_LINE_TRACKER);
    print_out("***         Running on %d MHz         ***", getCpuFrequencyMhz());
    print_out_tbl(HEAD_LINE_VERSION);

    EEPROM.begin(512); // SIZE = 5 x presets = 5 x 32 bytes = 160 bytes
    uint8_t langNum = EEPROM.read(LANG_EEPROM_ADDR);

    if (langNum >= LANG_COUNT)
        language = static_cast<Languages>(0);
    else
        language = static_cast<Languages>(langNum);

    // Initialize the pins
    pinMode(INTERV_PIN, OUTPUT);
    pinMode(STATUS_LED, OUTPUT);
    pinMode(AXIS1_STEP, OUTPUT);
    pinMode(AXIS1_DIR, OUTPUT);
    pinMode(EN12_n, OUTPUT);
    digitalWrite(AXIS1_STEP, LOW);
    digitalWrite(EN12_n, LOW);
    // handleExposureSettings();

    // Initialize Wifi and web server
    setupWireless();

    // Initialize the console serial
    setup_terminal(&term);

    if (xTaskCreate(consoleTask, "console", 4096, NULL, 1, NULL))
        print_out_tbl(TSK_START_CONSOLE);

    if (xTaskCreate(intervalometerTask, "intervalometer", 4096, NULL, 1, NULL))
        print_out_tbl(TSK_START_INTERVALOMETER);
    if (xTaskCreatePinnedToCore(webserverTask, "webserver", 4096, NULL, 1, NULL, 0))
        print_out_tbl(TSK_START_WEBSERVER);

    ra_axis.begin();
}

void loop()
{
    int delay_ticks = 0;

    if (DEFAULT_ENABLE_TRACKING == 1)
    {
        ra_axis.startTracking(ra_axis.rate.tracking, ra_axis.direction.tracking);
    }

    for (;;)
    {
        if (ra_axis.slewActive)
        {
            // Blink status LED if mount is in slew mode
            digitalWrite(STATUS_LED, !digitalRead(STATUS_LED));
            delay_ticks = 150; // Delay for 150 ms
        }
        else
        {
            // Turn on status LED if sidereal tracking is ON
            digitalWrite(STATUS_LED, ra_axis.trackingActive ? HIGH : LOW);
            delay_ticks = 1000; // Delay for 1 second
        }
        vTaskDelay(delay_ticks);
    }
}

void webserverTask(void* pvParameters)
{
    for (;;)
    {
        server.handleClient();
        vTaskDelay(1);
    }
}

void intervalometerTask(void* pvParameters)
{
    intervalometer.readPresetsFromEEPROM();

    for (;;)
    {
        if (intervalometer.intervalometerActive)
            intervalometer.run();
        vTaskDelay(1);
    }
}

void uartTask(void* pvParameters)
{
    for (;;)
    {
        uart_task();
        vTaskDelay(1);
    }
}

void consoleTask(void* pvParameters)
{
    for (;;)
    {
        term.readSerial();
        vTaskDelay(1);
    }
}
