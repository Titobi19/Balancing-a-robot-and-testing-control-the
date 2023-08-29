int in1 = 3;
int in2 = 4;
int in3 = 5;
int in4 = 6;
int enb = 7;
int ena = A0;
#include <MPU6050_tockn.h>
#include <Wire.h>
MPU6050 mpu6050(Wire);

void setup() {
  pinMode (ena, OUTPUT);
  pinMode (in1, OUTPUT);
  pinMode (in2, OUTPUT);
  pinMode(in3,OUTPUT);
  pinMode(in4,OUTPUT);
  piinMoe(enb,OUTPUT);
  Serial.begin(9600);
  Wire.begin();
  mpu6050.begin();
  mpu6050.calcGyroOffsets(true);
}

void loop() {
  getAngle();
  analogWrite(ena,135);
  gofoward();
  delay(500);
  reverse();
  delay(500);
}
void gofoward() {
  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);
  digitalWrite(in3,LOW);
  digitalWrite(in4,HIGH);
}
void reverse() {
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
   digitalWrite(in3,HIGH);
  digitalWrite(in4,LOW);
}
void getAngle() {
  mpu6050.update();
  Serial.print("angleX : ");
  Serial.print(mpu6050.getAngleX());
  Serial.print("\tangleY : ");
  Serial.println(mpu6050.getAngleY());
  analogWrite(ena, 130);
}
//if (getAngle
