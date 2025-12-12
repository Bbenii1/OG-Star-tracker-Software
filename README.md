<p align="center" style="height: 100px">
  <img src="docs/og_logo.png"/>
</p>

> [!NOTE]  
> Fell free to try out my new hassle-free web based OG Star TrackerFirmware Flashing Tool by opening [this link](https://bbenii1.github.io/ogtracker-flash/).

# OG Star Tracker

OG Star Tracker is a mostly 3D printed star tracker which is cheaper than any competitor, but has the same features and can be controlled from it's self hosted web interface. It can be made as a diy project or you can [buy](https://ogstartech.com/shop/) it already assembled. The tracker can handle 400mm of focal length and up to 6kg of payload capacity if you upgrade to the heavy duty version. It is easily customizable and upgradable, for example you can add another axis to it, so you will be able to use it as a GO-TO tracker. The project is open source, therefore easy to make and contribute to. The project came true thanks to the founder [Ondrej Gejdos](https://github.com/OndraGejdos) and the amazing [community](https://discord.gg/Zj2jpAkn8b) that contributed to the project.

# What is this repository?

This is my restructured and simplified version of the [official repository](https://github.com/OG-star-tech/OG-star-tracker-). This repository only focuses on version 2 of the tracker, so if you would like to know more about version 1 of the tracker please go to the [official repository](https://github.com/OG-star-tech/OG-star-tracker-).

# How to build it?
There are a 3 options you can take when deciding how would you like to make the tracker.

### Preassembled kit
 If you like easy things and you don't want to fiddle with assembly then you can buy the [already assembled kit](https://ogstartech.com/product/og-star-tracker-v2-fully-build/) from the website.

### DIY kit
 You have the option to buy the [DIY kit](https://ogstartech.com/product/og-star-tracker-kit/) from the website with all of the parts included. You can easily assemble your tracker, the kit includes all of the parts that you will need. To your tracker assemble you can follow the included manual or the  [video guide](https://www.youtube.com/watch?v=8lNT1Yxl7aw).

### DIY on your own

You might have a 3D printer and you would like to print the parts for the tracker? Then do so! You can find the [3D files](https://www.printables.com/model/348574-og-star-tracker-v2) on Printables and download them from there. To assemble the tracker you will also need some additional parts. For those you can buy the [hardware kit](https://ogstartech.com/product/og-star-tracker-hw-kit/) that includes all the needed parts apart from the 3D printed ones, or you can buy them separately on your own using [the list of parts](ttps://docs.google.com/spreadsheets/d/1V04zjGSebJ5LQbSmzs-h86T6Z9E3HwVkMj2nuVYQzYs/edit?gid=0#gid=0) or the list below. To your tracker assemble you can follow the [video guide](https://www.youtube.com/watch?v=8lNT1Yxl7aw).

> [!WARNING]  
> If you buy the parts on your own separately, you will need the [V2 PCB](https://ogstartech.com/product/og-star-tracker-pcb-board/) to be able to use the tracker.


<details>
<summary>Parts for assembly</summary>

|Parts                           | Quantity |
|--------------------------------|----------|
| M3x6 socket bolt               |     2    |
| M3x8 socket bolt               |    40    |
| M3x16 socket bolt              |     4    |
| M3x20 socket bolt              |     8    |
| M3x40 socket bolt              |     4    |
| M5x20 Low profile socket bolt  |     1    |
| M5x25 socket bolt              |     1    |
| M5x50 Hex head                 |     2    |
| M5 ptfe washer                 |     1    |
| M3 threaded insert             |    60    |
| M5 threaded insert             |     5    |
| M3 nut                         |     3    |
| M5 nut                         |     3    |
| M5 self-tightening nuts        |     2    |
| ¼-20x1/2” UNC Hex head         |     2    |
| 3/8-16 threaded insert         |     1    |
| ¼-20 UNC to 3/8-20 UNC adapter |     2    |
| AXK 5070 needle bearing        |     2    |
| AS 5070 Axial bearing washer   |     4    |
| KU 5025 sleeve bearing         |     1    |
| 625 bearing                    |    10    |
| GT2 16 teeth pulley            |     3    |
| GT2 48 teeth pulley            |     2    |
| GT2 20 teeth idler             |     1    |
| GT2 120mm belt                 |     2    |
| GT2 400mm belt                 |     1    |
| 5x50mm shaft                   |     2    |
| M5x95mm rod                    |     1    |
| M5x135mm rod                   |     1    |
| Round bubble level 12x7mm      |     1    |
| PTFE based grease              |     1    |
| Round magnet 10x3mm            |     4    |
| Round magnet 5x5mm             |     2    |
| Stepper motor                  |     1    |
| [PCB](https://ogstartech.com/product/og-star-tracker-pcb-board/)   |     1    |


|Optional parts|
|-|
| Glue                           |     1    |
| Laser or polar scope           |
| 4mm hex key                    |
| 2.5mm hex key                  |
| 2mm hex key                    |
</details>

<br>

# Features
- Wirelessly Control the tracker from your phone/laptop by connecting to a webpage
- Supports AP (Access Point) and STA (Station) mode
 -- AP  : The ESP32 will create a wifi network which you can connect to
 -- STA : The ESP32 connects to an existing wifi network specified by you, Ex: phone hotspot. (Not fully tested)
- Integrated intervalometer which can control your camera shutter, no need to buy extra hardware. Exposures can be controlled via the webpage
  - Intervalometer Modes:
    - Long Exposure Still: Classic astro mode with tracking to get long exposures on the same target. Optional dithering.
    - Long Exposure Movie: Long exposures with tracking and dither plus at the end of a set of exposures the axis is rewound (a frame) and the next set started. This give the ability to create a movie          of the night sky moving over a terrestrial object when couple with a video making software.
    -  Day Time Lapse: Standard time lapse with exposure settings controlled by the camera.
    -  Day Time Lapse with Pan: Standard time lapse with exposure settings controlled by the camera plus a pan of X degrees in between every exposure.
- Presets : Up to 10 preset intervalometer settings can be saved for retrieval next session.
- Slewing supported at different speeds.

# Important links

Website - [ogstartech.com](https://ogstartech.com/) <br>
Discord - [Community](https://discord.gg/Zj2jpAkn8b) <br>
Printables - [printables.com](https://www.printables.com/model/348574-og-star-tracker-v2)

## License

This work is licensed under a
[Creative Commons Attribution-NonCommercial-ShareAlike 4.0 International License](http://creativecommons.org/licenses/by-nc-sa/4.0/)

[![CC-BY-NC-SA 4.0](https://i.creativecommons.org/l/by-nc-sa/4.0/88x31.png)](http://creativecommons.org/licenses/by-nc-sa/4.0/)
