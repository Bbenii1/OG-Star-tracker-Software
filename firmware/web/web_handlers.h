#ifndef WEB_HANDLERS_H
#define WEB_HANDLERS_H

#include <WebServer.h>

// Forward declarations
class Intervalometer;
class Axis;
enum Languages : int;

// Web server handler functions
void handleRoot();
void handleOn();
void handleOff();
void handleSlewRequest();
void handleSlewOff();
void handleSetLanguage();
void handleSetCurrent();
void handleGotoRA();
void handleGetPresetExposureSettings();
void handleAbortCapture();
void handleAbortGoToRA();
void handleStatusRequest();
void handleVersion();
void handleInterfaceVersion();
void handleGetWifiSettings();
void handleSetWifiSettings();

// Setup function
void setupWireless();

#endif // WEB_HANDLERS_H

