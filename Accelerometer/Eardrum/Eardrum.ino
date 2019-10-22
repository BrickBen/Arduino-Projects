 // MPU-6050 Short Example Sketch
// By Arduino User JohnChi
// August 17, 2014
// Public Domain
/*
 * VCC 5V
 * SCL -> A5
 * SDA -> A4
 * INT -> DIGL2
 */

#include<Wire.h>
const int MPU_addr=0x68;  // I2C address of the MPU-6050
int16_t AcX,AcY,AcZ,GyX,GyY,GyZ;
int timeCounter = 0;
int X;
int Y;
int Z;
int sen = 50;
void setup(){
  delay(200);
  Wire.begin();
  Wire.beginTransmission(MPU_addr);
  Wire.write(0x6B);  // PWR_MGMT_1 register
  Wire.write(0);     // set to zero (wakes up the MPU-6050)
  Wire.endTransmission(true);
  Serial.begin(9600);
  pinMode(3, OUTPUT);
  digitalWrite(3, HIGH);
  digitalWrite(3, LOW);
  digitalWrite(3, HIGH);
}
void loop(){
  Wire.beginTransmission(MPU_addr);
  Wire.write(0x3B);  // starting with register 0x3B (ACCEL_XOUT_H)
  Wire.endTransmission(false);
  Wire.requestFrom(MPU_addr,14,true);  // request a total of 14 registers
  AcX=Wire.read()<<8|Wire.read();  // 0x3B (ACCEL_XOUT_H) & 0x3C (ACCEL_XOUT_L)
  AcY=Wire.read()<<8|Wire.read();  // 0x3D (ACCEL_YOUT_H) & 0x3E (ACCEL_YOUT_L)
  AcZ=Wire.read()<<8|Wire.read();  // 0x3F (ACCEL_ZOUT_H) & 0x40 (ACCEL_ZOUT_L)
  GyX=Wire.read()<<8|Wire.read();  // 0x43 (GYRO_XOUT_H) & 0x44 (GYRO_XOUT_L)
  GyY=Wire.read()<<8|Wire.read();  // 0x45 (GYRO_YOUT_H) & 0x46 (GYRO_YOUT_L)
  GyZ=Wire.read()<<8|Wire.read();  // 0x47 (GYRO_ZOUT_H) & 0x48 (GYRO_ZOUT_L)
  AcX = abs(floor(AcX/100));
  AcY = abs(floor(AcY/100));
  AcZ = abs(floor(AcZ/100));
  if(timeCounter == 0){
    X = AcX;
    Y = AcY;
    Z = AcZ;
  }
  if(abs(AcX - X) >= sen || abs(AcY - Y) >= sen || abs(AcZ - Z) >=sen){
    digitalWrite(3, LOW);
    delay(10000);
    digitalWrite(3, HIGH);
    delay(4000);
  }
  Serial.print("AcX = "); Serial.print(AcX);
  Serial.print(" | AcY = "); Serial.print(AcY);
  Serial.print(" | AcZ = "); Serial.print(AcZ);
  Serial.print(" | GyX = "); Serial.print(GyX);
  Serial.print(" | GyY = "); Serial.print(GyY);
  Serial.print(" | GyZ = "); Serial.println(GyZ);
  Serial.print("----" + X); Serial.print(", "+ Y); Serial.print(", " + Z);
  delay(100);
  timeCounter++;
}
