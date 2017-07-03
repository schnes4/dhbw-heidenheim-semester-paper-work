#include "Adafruit_LSM9DS1.h"

Adafruit_LSM9DS1 lsm = Adafruit_LSM9DS1();

void setup() {
  Serial.begin(38400);
  
  // put your setup code here, to run once:
  lsm.begin();
  
  // Set the accelerometer range
  lsm.setupAccel(lsm.LSM9DS1_ACCELRANGE_4G);
  
  // Set the magnetometer sensitivity
  lsm.setupMag(lsm.LSM9DS1_MAGGAIN_4GAUSS);

  // Setup the gyroscope
  lsm.setupGyro(lsm.LSM9DS1_GYROSCALE_245DPS);
}

void loop() {
  // put your main code here, to run repeatedly:
  lsm.read();  /* ask it to read in the data */ 

  /* Get a new sensor event */ 
  sensors_event_t a, m, g, temp;

  lsm.getEvent(&a, &m, &g, &temp); 

  Serial.print(a.acceleration.x);
  Serial.print(" ");
  Serial.print(a.acceleration.y);
  Serial.print(" ");
  Serial.println(a.acceleration.z);
}
