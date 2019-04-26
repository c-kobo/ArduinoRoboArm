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
int currentVal;

void setup()
{ //attaches our servos on pins PWM 3-5
  servoBoden.attach(10);
  servoRechts.attach(6);
  servoLinks.attach(5);
  servoZange.attach(11);
  servoBoden.write(60);
  servoRechts.write(14);
  servoLinks.write(60); 
  servoZange.write(115);
   Serial.begin(9600);
}

void loop()
{
  //bottom motor
  joyVal = analogRead(joy1X);
  joyVal = map (joyVal, 0, 1023, 0, 175); //servo value between 0-180
  if (joyVal < 80 || joyVal > 95){
    currentVal = servoBoden.read();
    if (joyVal < 80 && currentVal > 5){
      servoBoden.write(currentVal - 5);
    }
        if (joyVal > 95 && currentVal < 155){
      servoBoden.write(currentVal + 5);
    }
    Serial.println(servoBoden.read());
     delay(30);
  }  

    //right arm motor
  joyVal = analogRead(joy1Y);
  joyVal = map (joyVal, 0, 1023, 0, 160); //servo value between 0-180

  if (joyVal < 70 || joyVal > 80){
    currentVal = servoRechts.read();
    if (joyVal < 70 && currentVal > 5){
      servoRechts.write(currentVal - 2);
    }
        if (joyVal > 80 && currentVal < 160){
      servoRechts.write(currentVal + 2);
    }
    // Serial.println(servoRechts.read());
    delay(30);
  } 
  
//   joyVal = analogRead(joy1Y);
//   joyVal = map (joyVal, 0, 1023, 10, 160);
//   if (joyVal < 80 || joyVal > 90){
//     servoRechts.write(joyVal); //set the servo position according to the joystick value
//     delay(300);
//   } 
  
// //read the value of joystick (between 0-1023)
//   joyVal = analogRead(joy2Y);
//   joyVal = map (joyVal, 0, 1023, 10, 160); //servo value between 0-180
//   if (joyVal < 80 || joyVal > 90){
//     servoLinks.write(joyVal); //set the servo position according to the joystick value
//     delay(300);
//   }  
//   //read the value of joystick (between 0-1023)
//   joyVal = analogRead(joy2X);
//   joyVal = map (joyVal, 0, 1023, 100, 160); //servo value between 0-180
//   if (joyVal < 120 || joyVal > 140){
//     servoZange.write(joyVal); //set the servo position according to the joystick value
//     delay(300);
//   }
  }
