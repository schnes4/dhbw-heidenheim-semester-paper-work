
#include <Servo.h>
#include <Wire.h>
#include "SPI.h"
#include "Adafruit_GFX.h"
#include "Adafruit_ILI9341.h"
#include "Adafruit_LSM9DS1.h"
#include "Adafruit_Sensor.h"

#define ESC 3

#define IR_LED 4
#define IR_SENS 5

#define TFT_DC 9
#define TFT_CS 10

Servo esc;

Adafruit_ILI9341 tft = Adafruit_ILI9341(TFT_CS, TFT_DC);
Adafruit_LSM9DS1 lsm = Adafruit_LSM9DS1();

long speed = 56;
long rounds = 0;
bool completeRound = false;

unsigned long time = 0;

long foobar = 0;

void setup()
{
  Serial.begin(19200);

  setupTFT();
  setupESC();
  setupLSM();
  setupIR();
}
 
void loop()
{
  if (Serial.available() > 0) {
    speed = Serial.parseInt();
    
    //tft.print("Change speed to: ");
    //tft.println(speed, DEC);
  }

  esc.write(speed);

  int sensor = digitalRead(IR_SENS);

//  if (sensor == 0 && completeRound == false) {
//    rounds++;
//    completeRound = true;
//  }
//  else if (sensor == 1 && completeRound == true) {
//    completeRound = false;
//  }
//
//  if (millis() > (time + 5000)) {
//    //tft.print("Current RPM: ");
//    //tft.println((rounds / 2) * 12);
//
//    rounds = 0;
//
//    time = millis();
//  }

  Serial.println(sensor);
//  Serial.print(" ");

//  lsm.read();  /* ask it to read in the data */ 
//
//  /* Get a new sensor event */ 
//  sensors_event_t a, m, g, temp;
//
//  lsm.getEvent(&a, &m, &g, &temp); 

//  Serial.print(a.acceleration.x);
//  Serial.print(" ");
//  Serial.print(a.acceleration.y);
//  Serial.print(" ");
//  Serial.println(a.acceleration.z);

//  if (millis() > (time + 24)) {
//    //Serial.println(rounds);
//    rounds = 0;
//    foobar++;
//    time = millis();
//
//    if (foobar == 1000 || foobar == 1001 || foobar == 1002) {
//        Serial.println(a.acceleration.x);
//        Serial.println(a.acceleration.y);
//        Serial.println(a.acceleration.z);
//        Serial.println("");
//    }
//  }
//  else {
//    rounds++; 
//  }
}

void setupESC() {
  esc.attach(ESC);
  esc.write(179);
  
  delay(1000);
  
  esc.write(0);
  
  delay(1000);
}

void setupIR() {
  pinMode(IR_LED, OUTPUT);
  pinMode(IR_SENS, INPUT);

  digitalWrite(IR_LED, HIGH);
}

void setupTFT() {
  tft.begin();

  //tft.fillScreen(ILI9341_BLACK);
  //tft.setTextColor(ILI9341_WHITE);
  tft.fillScreen(ILI9341_BLACK);
  tft.setTextSize(2);
  tft.setCursor(0, 0);
  tft.setRotation(3);

  // X-Axis
  tft.drawLine(0, 120, 340, 120, ILI9341_WHITE);
  // Y-Axis
  tft.drawLine(160, 0, 160, 240, ILI9341_WHITE);
}

void setupLSM() {
  lsm.begin();
  
  // Set the accelerometer range
  lsm.setupAccel(lsm.LSM9DS1_ACCELRANGE_2G);
  
  // Set the magnetometer sensitivity
  lsm.setupMag(lsm.LSM9DS1_MAGGAIN_4GAUSS);

  // Setup the gyroscope
  lsm.setupGyro(lsm.LSM9DS1_GYROSCALE_245DPS);
}

