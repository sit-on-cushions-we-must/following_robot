# A robot that follows things.

The bot has three ultrasonic rangefinders on the front, one pointing forward,
one to the left and one to the right, if something comes in the way of the
rangefinders the robot moves towards it.

## Using the code
You will need the Arduino IDE to upload the code to your Arduino.

* Clone or download this repo.
* Open the `following_robot.ino` file in the Arduino IDE.
* Select your board from *tools>board*.
* Upload the code to the board by pressing the Upload button,
  it's the arrow in a circle, at the top left corner of the IDE.


## Building the robot

**Parts:**

* An Arduino.
* 3 ultrasonic rangefinders, I used the HC-SR04.
* A motor driver, I used an L293D.
* 2 DC motors.
* 2 wheels.
* A castor.
* A robot chassis.
* Some standoffs to mount the Arduino and motor driver(optional, you can just
  tape them on to the chassis).
* Cardboard, to mount the three sensors to the front of the robot.
* Tape


Bend a cardboard strip into three places, and tape the sensors to it, like this:
![sensor mount](https://aaalearn.mystagingwebsite.com/wp-content/uploads/2018/05/mounting_sensors.jpg)
Then tape that to the front of the chassis.

Then mount the Arduino and motor driver to the chassis with standoffs, or just tape
them onto it, if you have a metal chassis put a sheet of paper or something
under the Arduino and motor driver so they don't short out on the chassis.


## Wiring

| Arduino        | HC-SR04 rangefinders |
| :------------- | :------------------- |
| Digital pin12  | Left sensor Echo     |
| Digital pin11  | Middle sensor Echo   |
| Digital pin10  | Right sensor Echo    |
| Digital pin9   | Left sensor Trigger  |
| Digital pin8   | Middle sensor Trigger|
| Digital pin7   | Right sensor Trigger |
| GND            | GND                  |
| 5 volts        | PWR                  |


| Arduino        | L293D motor driver   |
| :------------- | :------------------- |
| Digital pin2   | Left motor pin1      |
| Digital pin3   | Left motor pin2      |
| Digital pin4   | Right motor pin1     |
| Digital pin9   | Right motor pin2     |
