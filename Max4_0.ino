/*
--> MAX 4.0 : Max + Horn + Maxon
--> AdriGarry 
--> 03/06/2015
*/
#include "Arduino.h"
#include "notes.h"
#include "led.h"
#include "buzzer.h"
#include "motor.h"
#include "potentiometre.h"

long nbLoop = 0;
long temps;
long tempsRdmLed;
long tempsRdmBuzz;
long tempsRdmHorn;
long tempsRdmMelodyRdm;
long tempsRdmMotor;
long rdmTpsLed = (13*1000);
long rdmTpsBuzz = (35*1000L);
long rdmTpsMelodyRdm = (25*1000);
long rdmTpsHorn = (30*1000);
long rdmTpsMotor = (20*1000);

void setup() {
  Serial.begin(9600);
  temps = millis();
  tempsRdmLed = millis();
  tempsRdmBuzz = millis();
  tempsRdmMelodyRdm = millis();
  tempsRdmHorn = millis();
  
  // Button
  pinMode(pinPot, INPUT);
  // Led
  pinMode(led, OUTPUT);
  pinMode(ledInt, OUTPUT);
  pinMode(ledMaxon, OUTPUT);
  // Buzz
  pinMode(buzzer, OUTPUT);
  pinMode(buzzMaxon, OUTPUT);
  // Motor
  pinMode(motor, OUTPUT);

  //delay(10*1000); // Retard lancement
  
  int notes[] = {NOTE_D3};
  int tempo[] = {100};
  int duration = sizeof(notes)/sizeof(int);
  playMelody(notes, duration, tempo, 1);
  delay(500);

  playMelody(notes, duration, tempo, 2);

 // playHornDoUp(random(1,8));
  playHornDoUp(3);

  for(int i = 1; i < 2; i++){
    //playHorn2(random(3,6));
    //playHornOvni();
    //playHornSiren(1);
    //playHornDoUp(1);
    delay(2000);
  }
}

void loop() {
  nbLoop++;
  //Serial.println(nbLoop);
  
  rythm = getPotValue();
  
  if((nbLoop % 50000) == 0){
      delay(1000);
      blinkLedInt(4, 25);
      delay(1000);
      nbLoop = 0;
  }
  
  if((millis() - tempsRdmLed) > rdmTpsLed){
      Serial.println("blinkLed");
      rdmTpsLed = random(1,7)*30*1000/rythm;
      tempsRdmLed = millis();
      blinkLed(random(1,5), random(1,5), random(2,20));
  }

  if((millis() - tempsRdmMotor) > rdmTpsMotor){
      Serial.println("turn");
      rdmTpsMotor = random(1,6)*30*1000/rythm;
      tempsRdmMotor = millis();
      turn(random(1,3), random(1,20));
  }
  
  if((millis() - tempsRdmHorn) > rdmTpsHorn){
      Serial.println("playHorn !!!!!!!!!!!!!!!!!");
      rdmTpsHorn = random(1,13)*40*1000/rythm;
      tempsRdmHorn = millis();
      int rdmHorn = random(1,11);
      switch(rdmHorn){
        case 1 :
          playHornWarning();
          break;
        case 2 :
          playHornDoUp(random(1,8));
          break;
        case 3 :
          playHorn();
          break;
        case 4 :
          playHornOff();
          break;
        case 5 :
          playHornFire(random(1,5));
          break;
        case 6 :
          playHornWhistle();
          break;
        case 7 :
          playHornOvni();
          break;
        case 8 :
          playHornBombing(random(1,5));
          break;
        case 9 :
          playHornSiren(random(3,7));
          break;
        default :
          playHornDown();
      }
  }

  if((millis() - tempsRdmMelodyRdm) > rdmTpsMelodyRdm){ // RENOMMER 'FULLRANDOM'
      Serial.println("playRandomMelody");
      rdmTpsMelodyRdm = random(1,13)*30*1000/rythm;
      tempsRdmMelodyRdm = millis();
      playRandomMelody(4);
  }

  if((millis() - tempsRdmBuzz) > rdmTpsBuzz){
      Serial.println("playMelody");
      rdmTpsBuzz = random(1,13)*30*1000/rythm;
      tempsRdmBuzz = millis();
      
      int rdm = random(30);
      //int rdm = -1;
      int speaker = random(1,3);
      // RANDOM DURATION *1.1 .. 1.4
      if(rdm == 0){
          int notes[] = {NOTE_C4, NOTE_G3,NOTE_G3, NOTE_A3, NOTE_G3,0, NOTE_B3, NOTE_C4};
          int tempo[] = {250, 125, 125, 250, 250, 500, 250, 250};
          int duration = sizeof(notes)/sizeof(int);
          playMelody(notes, duration, tempo, speaker);
      }
      else if(rdm == 1){
          int notes[] = {NOTE_C4, NOTE_GS7,NOTE_G3, NOTE_FS7};
          int tempo[] = {200, 200, 175, 400};
          int duration = sizeof(notes)/sizeof(int);
          playMelody(notes, duration, tempo, speaker);
      }
      else if(rdm == 2){
          int notes[] = {NOTE_FS5, NOTE_DS5,NOTE_E4, NOTE_FS7, NOTE_C8, NOTE_D7};
          int tempo[] = {75, 150, 200, 75, 200, 100};
          int duration = sizeof(notes)/sizeof(int);
          playMelody(notes, duration, tempo, speaker);
      }
      else if(rdm == 3){
          int notes[] = {NOTE_B0, NOTE_GS7,NOTE_G3, NOTE_FS7};
          int tempo[] = {150, 150, 150, 300};
          int duration = sizeof(notes)/sizeof(int);
          playMelody(notes, duration, tempo, speaker);
      }
      else if(rdm == 4){
          int notes[] = {NOTE_A4, NOTE_B3, NOTE_G4, NOTE_F5, NOTE_CS5, NOTE_CS5};
          int tempo[] = {200, 200, 100, 100, 400, 100};
          int duration = sizeof(notes)/sizeof(int);
          playMelody(notes, duration, tempo, speaker);
      }
      else if(rdm == 5){
          int notes[] = {NOTE_GS2, NOTE_B3, NOTE_C1};
          int tempo[] = {250, 150, 150, 500};
          int duration = sizeof(notes)/sizeof(int);
          playMelody(notes, duration, tempo, speaker);
      }
      else if(rdm == 6){
          int notes[] = {NOTE_C4, 0, NOTE_C4};
          int tempo[] = {600, 20, 120};
          int duration = sizeof(notes)/sizeof(int);
          playMelody(notes, duration, tempo, speaker);
      }
      else if(rdm == 7){
          int notes[] = {0,NOTE_C3, NOTE_B3, NOTE_F4};
          int tempo[] = {500, 200, 100, 100};
          int duration = sizeof(notes)/sizeof(int);
          playMelody(notes, duration, tempo, speaker);
      }
      else if(rdm == 8){
          int notes[] = {NOTE_B0, NOTE_B0, 0, NOTE_B0, NOTE_B0};
          int tempo[] = { 200, 200, 2000, 200, 200};
          int duration = sizeof(notes)/sizeof(int);
          playMelody(notes, duration, tempo, speaker);
      }
      else if(rdm == 9){
          int notes[] = {NOTE_AS2, NOTE_GS3, NOTE_AS2, NOTE_GS3, NOTE_CS4};
          int tempo[] = {200, 200, 200, 200, 80};
          int duration = sizeof(notes)/sizeof(int);
          playMelody(notes, duration, tempo, speaker);
      }
      else if(rdm == 10){
          int notes[] = {0, NOTE_C4};
          int tempo[] = {2000, 800};
          int duration = sizeof(notes)/sizeof(int);
          playMelody(notes, duration, tempo, speaker);
      }
      else if(rdm == 11){
          int notes[] = {NOTE_A7, NOTE_C8, NOTE_D8};
          int tempo[] = {200, 250, 600};
          int duration = sizeof(notes)/sizeof(int);
          playMelody(notes, duration, tempo, speaker);
      }
      else if(rdm == 12){
          int notes[] = {NOTE_C7, NOTE_CS5, NOTE_DS5};
          int tempo[] = {100, 250, 700};
          int duration = sizeof(notes)/sizeof(int);
          playMelody(notes, duration, tempo, speaker);
      }
      else if(rdm == 13){
          int notes[] = {566, 357, 395, 639, 780, 439, 395, 395, 395, 780};
          int tempo[] = {150, 150, 150, 150, 150, 150, 150, 150, 150, 800};
          int duration = sizeof(notes)/sizeof(int);
          playMelody(notes, duration, tempo, 1);
      }
      else if(rdm == 14){
          int notes[] = {NOTE_AS5, NOTE_GS2, NOTE_AS5, NOTE_GS2, NOTE_FS6};
          int tempo[] = {125, 200, 400, 125, 200};
          int duration = sizeof(notes)/sizeof(int);
          playMelody(notes, duration, tempo, speaker);
      }
      else if(rdm == 15){
          int notes[] = {NOTE_D3, NOTE_F6, NOTE_D3, NOTE_F6, NOTE_FS6};
          int tempo[] = {125, 125, 125, 125, 200};
          int duration = sizeof(notes)/sizeof(int);
          playMelody(notes, duration, tempo, speaker);
      }
      else if(rdm == 16){
          int notes[] = {NOTE_CS8, NOTE_DS8, NOTE_D8};
          int tempo[] = {800, 75, 75};
          int duration = sizeof(notes)/sizeof(int);
          playMelody(notes, duration, tempo, speaker);
      }
      else if(rdm == 17){
          int notes[] = {NOTE_AS7, NOTE_CS8, NOTE_GS6, 0, NOTE_G6, NOTE_D5, NOTE_A7};
          int tempo[] = {200, 150, 300, 1500, 200, 200, 200};
          int duration = sizeof(notes)/sizeof(int);
          playMelody(notes, duration, tempo, speaker);
      }
      else if(rdm == 18){
          int notes[] = {NOTE_FS7, NOTE_FS7, NOTE_FS7};
          int tempo[] = {200, 200, 200};
          int duration = sizeof(notes)/sizeof(int);
          playMelody(notes, duration, tempo, speaker);
      }
      else if(rdm == 19){
          int notes[] = {NOTE_AS7, NOTE_FS7, NOTE_AS7, NOTE_A5};
          int tempo[] = {200, 200, 200, 500};
          int duration = sizeof(notes)/sizeof(int);
          playMelody(notes, duration, tempo, speaker);
      }
       else if(rdm == 20){
          int notes[] = {NOTE_GS7, NOTE_AS6, NOTE_DS8};
          int tempo[] = {75, 75, 500};
          int duration = sizeof(notes)/sizeof(int);
          playMelody(notes, duration, tempo, speaker);
      }
       else if(rdm == 21){
          int notes[] = {NOTE_AS6, NOTE_DS8, NOTE_FS6, NOTE_GS7, NOTE_E6, NOTE_E6};
          int tempo[] = {100, 300, 100, 100, 200, 80};
          int duration = sizeof(notes)/sizeof(int);
          playMelody(notes, duration, tempo, speaker);
      }
       else if(rdm == 22){
          int notes[] = {NOTE_E6, NOTE_E6, NOTE_D4, NOTE_F3};
          int tempo[] = {40, 80, 200, 200};
          int duration = sizeof(notes)/sizeof(int);
          playMelody(notes, duration, tempo, speaker);
      }
       else if(rdm == 23){
          int notes[] = {NOTE_E6, NOTE_E6, NOTE_E6};
          int tempo[] = {400, 80, 80};
          int duration = sizeof(notes)/sizeof(int);
          playMelody(notes, duration, tempo, speaker);
      }
       else if(rdm == 24){
          int notes[] = {NOTE_AS7, NOTE_B6, NOTE_AS7, NOTE_A7, 0, NOTE_E3, NOTE_CS3};
          int tempo[] = {200, 80, 200, 80, 2000, 200, 200};
          int duration = sizeof(notes)/sizeof(int);
          playMelody(notes, duration, tempo, speaker);
      }
       else if(rdm == 25){
          int notes[] = {NOTE_G5, NOTE_G5, NOTE_G5};
          int tempo[] = {200, 200, 200};
          int duration = sizeof(notes)/sizeof(int);
          playMelody(notes, duration, tempo, speaker);
      }
       else if(rdm == 26){
          int notes[] = {NOTE_C4};
          int tempo[] = {1500};
          int duration = sizeof(notes)/sizeof(int);
          playMelody(notes, duration, tempo, speaker);
      }
      else{
          int notes[] = {NOTE_B0, NOTE_B0, 0, NOTE_B0, NOTE_B0};
          int tempo[] = { 200, 200, 2000, 200, 200};
          int duration = sizeof(notes)/sizeof(int);
          playMelody(notes, duration, tempo, 4);
      }
    }
}
