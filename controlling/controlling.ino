// For controlling you may use the following code

#include <Servo.h>  // include servo library
Servo servo;
int throttlePin = 0;
int throttle = 47;
int throttleMax = 60;
 
void setup()
{
  servo.attach(9); // attach servo to pin (only 9 or 10 possible)
}
 
void loop()
{
  //int throttle = analogRead(throttlePin); // read from pot
  //throttle = map(throttle, 0, 1023, 0, 179);
  //servo.write(throttle); // throttle value define the speed of esc

//  servo.write(47);


  if(throttle < throttleMax){
    servo.write(throttle);
    throttle++;
    delay(500);
  }
}
