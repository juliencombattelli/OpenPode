# Open-pode
Open-pode is a project for a fully open source hexapod whose mechanical part is 3D-printable.

## Videos
Some videos showing the project progress are available on our [Youtube channel](https://www.youtube.com/channel/UCUNnqteGSC3-gRxhA2PmjtQ).

## Authors
* Guillaume Sarthou (5th year at INSA school of Toulouse, France)
* Julien Combattelli (5th year at INSA school of Toulouse, France)

## Contacts
You can contact us using the following address : open.pode@gmail.com.

## Hardware
Open-pode uses a Raspberry Pi 3 board with a Raspbian OS. We support Dualshock 4 controller to drive the robot. Open-pode uses 18 servomotors (3 per leg). It is connected to the power grid since servomotors are low-cost ones (they consume a lot of current and so we cannot ship a battery). Each servomotor is driven with a PWM signal generated by two PCA9685 boards (one per side) which receive the pulse-width values from the Raspberry Pi via an I2C bus.

## Build
We support cmake build system to build Open-pode sources. You can either build Open-pode directly on the RPi or cross-compile from your computer using the appropriate cross-compiler:
* Windows : [Windows toolchain for RPi](http://gnutoolchains.com/raspberry/)
* Linux   : [Official toolchain for RPi](https://github.com/raspberrypi/tools/tree/master/arm-bcm2708/arm-rpi-4.9.3-linux-gnueabihf)

Then, you just have to follow these steps:
1. Clone the [Github repository](https://github.com/juliencombattelli/Open-pode) (`git clone https://github.com/juliencombattelli/Open-pode`)
2. Go into the folder and create a build folder (`cd Open-pode && mkdir build && cd build`)
3. Execute cmake to configure the build system (`cmake ..`)
4. Build the project using make (`make`)
5. Execute the open-pode executable in the build folder if your are on the RPi or scp the executable into it

## Contributing
If you find a bug or want to add a functionnality, feel free to create a Pull Request ;)

1. [Fork Open-pode on Github](https://github.com/juliencombattelli/Open-pode)
2. Create your feature branch (`git checkout -b my-new-feature`)
3. Add the changes your want to push (`git add my-file1 my-file2 ...`)
4. Commit your changes (`git commit -m 'Add some feature'`)
5. Push to the branch (`git push origin my-new-feature`)
6. Create a new Pull Request

For bugs and issues please use the [Github issue tracker](https://github.com/juliencombattelli/Open-pode/issues).

## Known bugs
#### Unable to connect the controller
Log into the RPi and enter the following command in a terminal:
```
cat ~/.cache/ds4drv.log
```
If this file contains the following message:
```
[info][bluetooth] Scanning for devices
[info][bluetooth] Found device <Adresse MAC de la manette>
[error][bluetooth] Unable to connect to detected device: Failed to set operational mode: [Errno 107] Transport endpoint is not connected
```
Then enter the command:
```
bluez-test-device remove <Adresse MAC de la manette>
```
And finally reboot the RPi.

## Todo
- [x] Implement 2D and 3D Vector struct
- [ ] Replace all C arrays with std::array
- [x] Implement circular movements
- [ ] Translate README into English
- [ ] Use Cmake as build system
- [ ] Design a 3D simulator for movement testing
- [ ] Use Yocto project to generate the Linux distro

## Improvments
- [ ] Optimise movements computing
- [ ] Use GLM for 3D math computing ?
- [ ] Parallelize the computation of the joints angles
