# A robot that follows things.

The bot has three ultrasonic rangefinders on the front, one pointing forward,
one to the left and one to the right, if something comes in the way of the
rangefinders the robot moves towards it.

**The following logic:**

* If the forward sensor sees something go forward.
* If the left sensor sees something turn left.
* If the right sensor sees something turn right.
* If none of the sensors see anything stop.

In the code I made the bot ignore things that are further away than 20 centimeters
as well as things that are closer than 6 centimeters, so if the bot drives up to
a wall or up to you it stops when it gets close and if something is far away
from it then it doesn't go to it.


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
* A caster.
* A robot chassis.
* Some standoffs to mount the Arduino and motor driver(optional, you can just
  tape them on to the chassis).
* Cardboard, to mount the three sensors to the front of the robot.
* Tape


Bend a cardboard strip in three places, and tape the sensors to it.
Then tape that to the front of the chassis, like this:

![sensor mount](https://aaalearn.mystagingwebsite.com/wp-content/uploads/2018/05/mounting_sensors.jpg)


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

**Diagram:**

![wiring](https://aaalearn.mystagingwebsite.com/wp-content/uploads/2018/05/follower_diagram.png)


##### Licensing:

All the photos and diagrams for this project are under the Creative Commons Attribution-ShareAlike 4.0 International License.
<a rel="license" href="http://creativecommons.org/licenses/by-sa/4.0/"><img alt="Creative Commons License" style="border-width:0" src="https://i.creativecommons.org/l/by-sa/4.0/88x31.png" /></a><br />This work is licensed under a <a rel="license" href="http://creativecommons.org/licenses/by-sa/4.0/">Creative Commons Attribution-ShareAlike 4.0 International License</a>.

All the code is under the MIT license: http://mit-license.org/
