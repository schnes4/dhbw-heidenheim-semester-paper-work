// For controlling you may use the following code

#include <Servo.h>  // include servo library
Servo esc;
int throttlePin = 0;
 
void setup()
{
  esc.attach(9);
}
 
void loop()
{
  int throttle = analogRead(throttlePin); // read from pot
  throttle = map(throttle, 0, 1023, 0, 179);
  esc.write(throttle); // throttle value define the speed of esc
}
