#include <Servo.h>

const int ldrPin = A0;
const int threshold = 500; // bisa diatur tergantung cahaya
const int servoPin = 9;

Servo tirai;

void setup() {
  Serial.begin(9600);
  tirai.attach(servoPin);
  tirai.write(0); // mulai dari tirai tertutup
}

void loop() {
  int ldrValue = analogRead(ldrPin);
  Serial.println(ldrValue); // untuk melihat nilai cahaya

  if (ldrValue > threshold) {
    tirai.write(90); // buka tirai
  } else {
    tirai.write(0);  // tutup tirai
  }

  delay(1000);
}
