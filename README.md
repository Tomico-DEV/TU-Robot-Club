# TU-Robot-Club
An Arduino library for use in Triam Udom Suksa School's robotics club

# How to import (and update)
To import this library or any library into the Arduino IDE, follow these simple steps:

First, download the files 

[![Example Image](https://user-images.githubusercontent.com/19264/86286220-c29e8280-bbee-11ea-8793-fda3d7e3ab3b.png)](https://github.com/refined-github/refined-github/issues/3307)
- Unzip the downloaded .zip File
- Copy the unzipped folder and navigate to `Documents/Arduino/libraries` and paste it there. Rember to paste the FOLDER, the not FILES inside of it

To update, do these exact same steps and replace the old `ClubRobot` folder

And you're done! Now write `#include <ClubRobot.h>` on the top of your Arduino Sketch (code) and call `robotInit();` in `void setup()` and it should work!

# How to connect
The following is a list of how the Arduino should be connected to the DRV8833 motor driver
- IN1 -> digital 3
- IN2 -> digital 5
- IN3 -> digital 6
- IN4 -> digital 9

# List of available commands
All of the following are void functions

- `robotInit()` sets up pinMode
- `forward(int val)` makes both wheels spin in the forward direction at the speed given by the specified value
- `backward(int val)` makes both wheels spin in the backward direction at the speed given by the specified value
- `leftForward(int val)` makes the left wheel spin in the forward direction at the speed given by the specified value
- `rightForward(int val)` makes the right wheel spin in the forward direction at the speed given by the specified value
- `motorStop()` makes both wheels stop rotating
- `leftStop()` makes the left wheel stop rotating
- `rightStop()` makes the right wheel stop rotating
