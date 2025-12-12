# OG Star Tracker : Wireless Control Hardware (Rev 2.0)

This simple PCB and firmware intends to make it easier to control the OG Star Tracker. If you have any suggestions/ideas about new features or would like to contribute, post in the OG star tracker [discord server](https://discord.com/invite/dyFKm79gKJ) or message me (Discord: jahh#8924).
If you like this work, feel free to connect with me on [Github](https://github.com/jugal2001) or [Linkedin](https://www.linkedin.com/in/jugaljesing/).

## Table of Contents
- [Compiling](compiling.md)
- [Wifi Config](wifi_config.md)


## Firmware

The firmware for the PCB is provided in this repository and can be compiled and flashed with the given [instructions](compiling.md).
Upon turning on the tracker will create an access point with the following default credentials that you can use to connect and control it:

```
SSID: OG Star Tracker
Password: password123
```

After a successful connection you can open **tracker.local** in your browser using your phone or desktop. The tracker hosts its own interface for convenient controlling.

You can set your own wifi configuration following [this tutorial](wifi_config.md).

[API](API.md)

## App

If the webserver is not enough there is a app available to improve the accessibility even further.
Check out https://github.com/OndraGejdos/OG-star-tracker-App for more details.

## Contributing

When contributing to the project please make sure to follow the [coding style](docs/coding-style.md) prior creating a pull request.
With this we can make sure to keep a clean and tidy codespace.
