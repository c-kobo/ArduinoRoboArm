//add the aervo library
#include <Servo.h>

//define our servos
Servo servoBoden;
Servo servoRechts;
Servo servoLinks;
Servo servoZange;
//define joystick pin (Analog)
int joy1X = 1;
int joy1Y = 0;
int joy2X = 4;
int joy2Y = 5;
//variable to read the values from the analog pins
int joyVal;
int joyValOld;
bool joy2Xcheck = false;
int currentVal;

void setup()
{ //attaches our servos on pins PWM 3-5
  servoBoden.attach(10);
  servoRechts.attach(6);
  servoLinks.attach(5);
  servoZange.attach(11);
  initialPosition(servoRechts, 14);
  initialPosition(servoLinks, 60);
  initialPosition(servoZange, 100);
  initialPosition(servoBoden, 100);
  Serial.begin(9600);
}

void initialPosition(Servo servo, int startPos)
{
  int currentPos = servo.read();
  int steps;
  if (currentPos < startPos)
  {
    steps = startPos - currentPos;
    for (int i = 1; i <= steps; i++)
    {
      servo.write(servo.read() + 4);
      delay(30);
    }
  }
  else
  {
    steps = currentPos - startPos;
    for (int i = 1; i <= steps; i++)
    {
      servo.write(servo.read() - 4);
      delay(30);
    }
  }
}

void loop()
{
  //bottom motor
  joyVal = analogRead(joy1X);
  joyVal = map(joyVal, 0, 1023, 0, 175); //servo value between 0-180
  if (joyVal < 70 || joyVal > 95)
  {
    currentVal = servoBoden.read();
    if (joyVal < 80 && currentVal > 4)
    {
      servoBoden.write(currentVal - 2);
    }
    if (joyVal > 95 && currentVal < 156)
    {
      servoBoden.write(currentVal + 2);
    }
    Serial.println(servoBoden.read());
    delay(20);
  }

  //right arm motor
  joyVal = analogRead(joy1Y);
  joyVal = map(joyVal, 0, 1023, 0, 160); //servo value between 0-180

  if (joyVal < 70 || joyVal > 80)
  {
    currentVal = servoRechts.read();
    if (joyVal < 70 && currentVal > 5)
    {
      servoRechts.write(currentVal - 1);
    }
    if (joyVal > 80 && currentVal < 100)
    {
      servoRechts.write(currentVal + 1);
    }
    // Serial.println(servoRechts.read());
    delay(20);
  }

  //left arm motor
  joyVal = analogRead(joy2Y);
  joyVal = map(joyVal, 0, 1023, 0, 160); //servo value between 0-180

  if (joyVal < 70 || joyVal > 80)
  {
    currentVal = servoLinks.read();
    if (joyVal < 70 && currentVal > 5)
    {
      servoLinks.write(currentVal - 1);
    }
    if (joyVal > 80 && currentVal < 160)
    {
      servoLinks.write(currentVal + 1);
    }
    // Serial.println(servoLinks.read());
    delay(20);
  }

  //grabber motor
  joyVal = analogRead(joy2X);
  joyVal = map(joyVal, 0, 1023, 0, 160); //servo value between 0-180

  if (joyVal < 50 || joyVal > 90)
  // Serial.println(joyVal);
  {
    currentVal = servoZange.read();
    if (joyVal < 120 && currentVal > 80)
    {
      servoZange.write(currentVal - 2);
    }
    if (joyVal > 130 && currentVal < 120)
    {
      servoZange.write(currentVal + 2);
      // Serial.println(servoZange.read());
    }
    // Serial.println(servoZange.read());
    delay(20);
  }
}
