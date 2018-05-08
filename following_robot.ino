
// the motor driver variables
const int left1 = 2;
const int left2 = 3;
const int right1 = 4;
const int right2 = 5;

// the echo and trigger pins for the rangefinders
const int echoL = 12;
const int echoM = 11;
const int echoR = 10;

const int trigL = 9;
const int trigM = 8;
const int trigR = 7;


/*
 turns the bot to the left
*/
void forwardLeft() {
  // turn left for a bit
  digitalWrite(left1, HIGH);
  digitalWrite(left2, LOW);
  digitalWrite(right1, LOW);
  digitalWrite(right2, LOW);
}


/*
 turns the bot to the right
*/
void forwardRight() {
  // turn right for a bit
  digitalWrite(left1, LOW);
  digitalWrite(left2, LOW);
  digitalWrite(right1, HIGH);
  digitalWrite(right2, LOW);
}


void setup() {
  pinMode(left1, OUTPUT);
  pinMode(left2, OUTPUT);
  pinMode(right1, OUTPUT);
  pinMode(right2, OUTPUT);

  pinMode(trigL, OUTPUT);
  pinMode(trigM, OUTPUT);
  pinMode(trigR, OUTPUT);

  pinMode(echoL, INPUT);
  pinMode(echoM, INPUT);
  pinMode(echoR, INPUT);

  Serial.begin(9600);
}

void loop() {

  long rDuration, rCm; // used to calculate distance for right sensor
  long mDuration, mCm; // used to calculate distance for middle sensor
  long lDuration, lCm; // used to calculate distance for left sensor

////////////////////////////////////////////////////////////////////////////////
// the measuring stuff
// this stuff reads from the sensors
////////////////////////////////////////////////////////////////////////////////

  /*
   send a ping on the right sensor
  */
  digitalWrite(trigR, LOW); // pull it low for a clean ping
  delayMicroseconds(2);
  digitalWrite(trigR, HIGH); // send the ping
  delayMicroseconds(5);
  digitalWrite(trigR, LOW); // pull it low again

  // store the time it takes for the ping to return
  rDuration = pulseIn(echoR, HIGH);
  // convert the time it takes into centimeters
  rCm = microsecondsToCentimeters(rDuration);

  /*
   send a ping on the middle sensor
  */
  digitalWrite(trigM, LOW); // pull it low for a clean ping
  delayMicroseconds(2);
  digitalWrite(trigM, HIGH); // send the ping
  delayMicroseconds(5);
  digitalWrite(trigM, LOW); // pull it low again

  // store the time it takes for the ping to return
  mDuration = pulseIn(echoM, HIGH);
  // convert the time it takes into centimeters
  mCm = microsecondsToCentimeters(mDuration);

  /*
   send a ping on the left sensor
  */
  digitalWrite(trigL, LOW); // pull it low for a clean ping
  delayMicroseconds(2);
  digitalWrite(trigL, HIGH); // send the ping
  delayMicroseconds(5);
  digitalWrite(trigL, LOW); // pull it low again

  // store the time it takes for the ping to return
  lDuration = pulseIn(echoL, HIGH);
  // convert the time it takes into centimeters
  lCm = microsecondsToCentimeters(lDuration);


////////////////////////////////////////////////////////////////////////////////
//The following logic
////////////////////////////////////////////////////////////////////////////////

  if ((rCm > 6) and (rCm < 20)) { // ignore stuff closer than 1 cm and further than 100 cm.
    // turn left
    forwardRight();
    // send readings to the computer
    Serial.print(rCm);
    Serial.println("rCm");
  } else {
    // stop the robot
    digitalWrite(left1, LOW);
    digitalWrite(left2, LOW);
    digitalWrite(right1, LOW);
    digitalWrite(right2, LOW);
  }

  if ((mCm > 6) and (mCm < 20)) { // ignore stuff closer than 1 cm and further than 100 cm.
    // drive straight
    digitalWrite(left1, HIGH);
    digitalWrite(left2, LOW);
    digitalWrite(right1, HIGH);
    digitalWrite(right2, LOW);
    // send readings to the computer
    Serial.print(mCm);
    Serial.println("mCm");
  } else {
    // stop the robot
    digitalWrite(left1, LOW);
    digitalWrite(left2, LOW);
    digitalWrite(right1, LOW);
    digitalWrite(right2, LOW);
  }

  if ((lCm > 6) and (lCm < 20)) { // ignore stuff closer than 1 cm and further than 100 cm.
    // turn left
    forwardLeft();
    // send readings to the computer
    Serial.print(lCm);
    Serial.println("lCm");
  } else {
    // stop the robot
    digitalWrite(left1, LOW);
    digitalWrite(left2, LOW);
    digitalWrite(right1, LOW);
    digitalWrite(right2, LOW);
  }
}


/*
 function that converts the ping time reading to distance
*/
long microsecondsToCentimeters(long microseconds) {
  // The speed of sound is 340 m/s or 29 microseconds per centimeter.
  // The ping travels out and back, so to find the distance of the
  // object we take half of the distance traveled.
  return microseconds /29 / 2;
}
