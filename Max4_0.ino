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
long rdmTpsBuzz = (45*1000);
long rdmTpsMelodyRdm = (25*1000);
long rdmTpsHorn = (60*1000);
long rdmTpsMotor = (10*1000);
/*long rdmTpsLed = (3*1000);
long rdmTpsBuzz = (15*1000);
long rdmTpsMelodyRdm = (25*1000);
long rdmTpsHorn = (30*1000);
long rdmTpsMotor = (10*1000);*/

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
  
  //blinkLedInt(4, 25);

  int notes[] = {NOTE_D3};
  int tempo[] = {100};
  //int notes[] = {566, 357, 395, 639, 780, 439, 395, 395, 395, 780};
  //int tempo[] = {150, 150, 150, 150, 150, 150, 150, 150, 150, 800};

  int duration = sizeof(notes)/sizeof(int);
  playMelody(notes, duration, tempo, 1);

  /*blinkAllLed(1, 20);
  playMelody(notes, duration*1.3, tempo, 1);
  blinkAllLed(1, 2);
  playMelody(notes, duration*1.1, tempo, 2);
  blinkAllLed(1, 2);
  int notes2[] = {NOTE_B3};
  playMelody(notes2, duration*1.3, tempo, 3);
  blinkAllLed(1, 2);*/

  delay(2000);
  //tempo[] = {500};
  //toneAll(notes, duration*1.5, tempo);

  //turnTest();
  turn(1, 4);
  
  //btnEtat = LOW; // Initialisation de l'état du bouton comme "relaché"
  digitalWrite(led,LOW);
  //attachInterrupt(0, pushButton, RISING); // ou LOW
  
  /*for(int i = 0; i < 1000; i++){
    playRandomMelody(4);
    //playHorn();
    delay(3000);
  }*/
  
}

void loop() {
  nbLoop++;
  //Serial.println(nbLoop);
  
  rythm = getPotValue();
  
  if((nbLoop % 50000) == 0){
      delay(1000);
      blinkLedInt(4, 25);
      delay(1000);
      //nbLoop = 0;
  }
  
  if((millis() - tempsRdmLed) > rdmTpsLed){
      rdmTpsLed = (random(1,7))*30*1000/rythm;
      tempsRdmLed = millis();
      blinkLed(random(1,5), random(1,5), random(2,20));
  }

  if((millis() - tempsRdmMotor) > rdmTpsMotor){
      rdmTpsMotor = ((random(1,6))*30*1000)/rythm;
      tempsRdmMotor = millis();
      turn(random(1,3), random(1,20));
  }
  
  if((millis() - tempsRdmHorn) > rdmTpsHorn){
      rdmTpsHorn = (random(2,20)*45*1000)/rythm;
      tempsRdmHorn = millis();
      int rdmHorn = random(1,12);
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
        default :
          playHornDown();
      }
  }

  if((millis() - tempsRdmMelodyRdm) > rdmTpsMelodyRdm){ // RENOMMER 'FULLRANDOM'
      rdmTpsMelodyRdm = (random(1,10)*20*1000)/rythm;
      tempsRdmMelodyRdm = millis();
      playRandomMelody(4);
  }

  if((millis() - tempsRdmBuzz) > rdmTpsBuzz){
      rdmTpsBuzz = random(2,15)*50*1000/rythm;
      tempsRdmBuzz = millis();
      
      //int rdm = 13;
      int rdm = random(30);
      int speaker = random(1,7);
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
