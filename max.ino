/*  --> MAX 4.0 : linked to Odi */

#include "Arduino.h"
#include "notes.h"
#include "led.h"
#include "buzzer.h"
#include "motor.h"
#include "potentiometre.h"
#include "functions.h"
#include "serialParser.h"

String msg;

void setup() {
  Serial.begin(9600);   //Serial.begin(115200);
  Serial.println("Max initialization...");

  pinMode(pinPot, INPUT); // Button
  pinMode(led, OUTPUT); // Led
  pinMode(ledInt, OUTPUT); // Led Intérieure ?
  pinMode(ledMaxon, OUTPUT); // Led Maxon
  pinMode(buzzer, OUTPUT); // Buzz
  pinMode(buzzMaxon, OUTPUT); // Buzz Maxon
  pinMode(motor, OUTPUT); // Motor

  int notes[] = {NOTE_D3};
  int tempo[] = {100};
  int duration = sizeof(notes) / sizeof(int);
  playMelody(notes, duration, tempo, 1);
  delay(500);
  playMelody(notes, duration, tempo, 2);

  //playHornDoUp(2);//3
  Serial.println("Max ready");
}

void loop() {

  msg = Serial.readStringUntil("\n");
  //Serial.println("." + msg);
  msg.trim();
  if(msg.length() > 0){
    parseSerialToAction(msg); 
  }

}


