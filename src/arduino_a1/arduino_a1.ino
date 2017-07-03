#define ITR_PIN 7
#define IR_SENS 9

unsigned long time;
int falling = true;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(38400);

  pinMode(IR_SENS, INPUT);
  pinMode(ITR_PIN, OUTPUT);

  digitalWrite(ITR_PIN, LOW);
//  attachInterrupt(digitalPinToInterrupt(IR_SENS), ping, RISING);
}

void loop() {
  // put your main code here, to run repeatedly:
  int sensor = digitalRead(IR_SENS);
  
  if (sensor == LOW) {
    if (falling) {
      digitalWrite(ITR_PIN, HIGH);
      delay(5);
      digitalWrite(ITR_PIN, LOW);

      Serial.println(5);

      falling = false;
    }
  }
  else {
    falling = true;
  }

  Serial.println(sensor);
}

//void ping() {
//  Serial.println(5);
//}

