# Make a smart irrigation system for your plants using the ESP8266

This repository contains a PlatformIO project for making an ESP8266-based irrigation system for your plants.
This repository is still at an early development stage. More information is hopefully added soon!

## Wiring
Next to the ESP8266 a capacitive moisture sensor, an ultrasonic sensor, a relais and a pump are needed.
The moisture sensor needs to be connected to pin A0, the ultrasonic sensor to pins D7 (trigger) and D6 (echo) and the relais to pin D5.

## TODOs
A few features that can still be implemented are listed below.
- Log humidity/water level data
- Send the ESP to sleep after one loop to allow using it on battery
- At a factory reset function (using a button so that you can disconnect from a WiFi without being in that network)

## Changelog

Please see [CHANGELOG](CHANGELOG.md) for more information what has changed recently.

## Contributing

Please see [CONTRIBUTING](CONTRIBUTING.md) for details.

## Security

If you discover any security related issues, please email [hello@lukasmu.com](mailto:hello@lukasmu.com) instead of using the issue tracker.

## Postcardware

You are free to use this project, but if it makes it to your production environment we highly appreciate you sending us a postcard from your hometown. The address is: Lukas Müller, Dirklangendwarsstraat 5, 2611HZ Delft, The Netherlands.

## Credits

Based on the awesome [ESP8266 IoT Framework](https://github.com/maakbaas/esp8266-iot-framework) by [Maakbaas](https://github.com/maakbaas). 
The documentation of the framework can be found at [https://github.com/maakbaas/esp8266-iot-framework#introduction](https://github.com/maakbaas/esp8266-iot-framework#introduction).

## License

The GNU General Public License (GNU GPL). Please see [LICENSE](LICENSE.md) for more information.