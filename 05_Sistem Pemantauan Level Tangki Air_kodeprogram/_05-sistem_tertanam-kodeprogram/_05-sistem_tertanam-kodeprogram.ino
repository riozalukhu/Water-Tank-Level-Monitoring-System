#define BLYNK_TEMPLATE_ID "TMPLa2T9Nlus"
#define BLYNK_DEVICE_NAME "LED"
#define BLYNK_FIRMWARE_VERSION        "0.1.0"
#define BLYNK_PRINT Serial
#include "BlynkEdgent.h"
int pompa = 14;
int buz = 15;
int trig = 0;
int echo = 2;
BLYNK_WRITE(V2){
  int value3 = param.asInt();
  digitalWrite(pompa,value3);
}
BLYNK_WRITE(V5){
  int value4 = param.asInt();
}
void setup() {
  Serial.begin(115200);
  pinMode(pompa,OUTPUT);
  pinMode(buz,OUTPUT);
  pinMode(trig,OUTPUT);
  pinMode(echo,INPUT);
  BlynkEdgent.begin();
}
void loop() {
  digitalWrite(trig,LOW);
  delayMicroseconds(10);
  digitalWrite(trig,HIGH);
   delayMicroseconds(10);
  digitalWrite(trig,LOW);
  float t = pulseIn(echo,HIGH);
  float cm = t * 0.0343 / 2;
  Serial.println(cm);
  if(cm > 11.00){
    digitalWrite(buz,HIGH);
    delay(1000);
    digitalWrite(buz,HIGH);
    delay(1000);
    digitalWrite(pompa,LOW);
  }
  else if(cm > 15.00 ){
    digitalWrite(buz,HIGH);
    delay(500);
    digitalWrite(buz,HIGH);
    delay(500);
    digitalWrite(pompa,HIGH);
    if(cm == 2.00){
      digitalWrite(pompa,LOW);
    }
  }
  Blynk.virtualWrite(V5, cm);
  BlynkEdgent.run();
}

