#include "driver/uart.h"

#define LED 4
int btn, potenciometro=15, botao=19;

#define ledPWM 2
int freq = 5000;
int ledChannel = 0;
int resolution = 8;
int dutyCycle = 0;


void setup() {
  Serial.begin(500000);
  pinMode(LED, OUTPUT);
  pinMode(botao, INPUT);
  pinMode(potenciometro, INPUT);
  pinMode(ledPWM, OUTPUT);

  ledcSetup(ledChannel, freq, resolution);
  ledcAttachPin(ledPWM, ledChannel);
  ledcWrite(ledChannel, dutyCycle);
}
 
void loop() {
  
  dutyCycle = analogRead(potenciometro);
  dutyCycle = map(dutyCycle,0,4095,0,255);

  //Serial.print("Valor do potenciometro: ");
  Serial.println(dutyCycle);
  
  ledcWrite(ledChannel, dutyCycle);
  
btn = digitalRead(botao);
  if (btn == HIGH){
    Serial.write("No if");
    
    for(int i = 0; i<5; i++){
      digitalWrite(LED, HIGH);
      delay(300);
      digitalWrite(LED, LOW);
      delay(300);
      //Serial.print("no for i= ");
      //Serial.println(i);
    }
  }
/*
  Serial.write("VAI CORINTHIANS");
  Serial.println(1);
  Serial.flush();
  delay(300);
  */
  delay(600);
}