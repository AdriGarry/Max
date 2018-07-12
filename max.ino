/*  --> MAX 4.0 : linked to Odi */

#include "Arduino.h"
#include "notes.h"
#include "led.h"
#include "buzzer.h"
#include "motor.h"
#include "potentiometre.h"
#include "api.h"
#include "serialParser.h"

long tempsAction;
long rdmTpsAction = 1800000L; // 900000 => 15min, 1800000 => 30min

void setup() {
  Serial.begin(115200);
  Serial.println("Max initialization...");

  pinMode(pinPot, INPUT); // Button
  pinMode(led, OUTPUT); // Led
  pinMode(ledInt, OUTPUT); // Led Intérieure ?
  pinMode(ledMaxon, OUTPUT); // Led Maxon
  pinMode(buzzer, OUTPUT); // Buzz
  pinMode(buzzMaxon, OUTPUT); // Buzz Maxon
  pinMode(motor, OUTPUT); // Motor

  int notes[] = {NOTE_D3};
  int tempo[] = {30};
  int duration = sizeof(notes) / sizeof(int);
  playMelody(notes, duration, tempo, 1);

  //playHornDoUp(1);
  //playHornDoUp(5);//3
  Serial.println("Max ready");
}

void loop() {

  String msg;
  if(Serial.available() > 0){
    msg = Serial.readStringUntil("\n");
    //Serial.println("." + msg);
    msg.trim();
    if(msg.length() > 0){
      parseSerialToAction(msg); 
    }
  }

  if((millis() - tempsAction) > rdmTpsAction){
    //Serial.println(millis());
    Serial.println("some random action from Max");
    tempsAction = millis();
  }
  
}


