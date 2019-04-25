//add the aervo library
#include <Servo.h>

//define our servos
Servo servoBoden;
Servo servoRechts;
Servo servoLinks;
Servo servoZange;
//define joystick pin (Analog)
int joy1X =1;
int joy1Y =0;
int joy2X =4;
int joy2Y =5;
//variable to read the values from the analog pins 
int joyVal;
int joyValOld;
bool joy2Xcheck =false;

void setup()
{ //attaches our servos on pins PWM 3-5
  servoBoden.attach(10);
  servoRechts.attach(6);
  servoLinks.attach(5);
  servoZange.attach(11);
  servoBoden.write(15);
  servoRechts.write(160);
  servoLinks.write(160);
  servoZange.write(100);  
   Serial.begin(9600);
}

void loop()
{
  //read the value of joystick (between 0-1023)
  joyVal = analogRead(joy1X);
  joyVal = map (joyVal, 0, 1023, 0, 180); //servo value between 0-180
    Serial.println(joyVal);
  if (joyVal < 90 || joyVal > 95){
    servoBoden.write(joyVal); //set the servo position according to the joystick value
    delay(300);
  }  
  
  joyVal = analogRead(joy1Y);
  joyVal = map (joyVal, 0, 1023, 10, 160);
  if (joyVal < 80 || joyVal > 90){
    servoRechts.write(joyVal); //set the servo position according to the joystick value
    delay(300);
  } 
  
//read the value of joystick (between 0-1023)
  joyVal = analogRead(joy2Y);
  joyVal = map (joyVal, 0, 1023, 10, 160); //servo value between 0-180
  if (joyVal < 80 || joyVal > 90){
    servoLinks.write(joyVal); //set the servo position according to the joystick value
    delay(300);
  }  
  //read the value of joystick (between 0-1023)
  joyVal = analogRead(joy2X);
  joyVal = map (joyVal, 0, 1023, 100, 160); //servo value between 0-180
  if (joyVal < 120 || joyVal > 140){
    servoZange.write(joyVal); //set the servo position according to the joystick value
    delay(300);
  }
  }
