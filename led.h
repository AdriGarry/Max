// Led
const int led = 13;
const int ledInt = 10;
const int ledMaxon = A2;


void blinkLed(int ledTo, int repeat, int tempo){
  int blinkLed = ledTo;
  for(repeat; repeat > 0; repeat--){
    if(ledTo > 2) blinkLed = random(1,3);
    if(blinkLed == 1) blinkLed = 13;
    else blinkLed = A2;
    digitalWrite(blinkLed,HIGH);
    delay(tempo*15);
    digitalWrite(blinkLed,LOW);
    digitalWrite(ledInt,HIGH);
    delay(tempo*20);
    digitalWrite(ledInt,LOW);
    delay(tempo*5);
  }
}

void blinkLedInt(int repeat, int tempo){
  for(repeat; repeat > 0; repeat--){
    digitalWrite(ledInt,HIGH);
    delay(tempo*30);
    digitalWrite(ledInt,LOW);
    delay(tempo*30);
  }  
}

void blinkAllLed(int repeat, int tempo){
  for(repeat; repeat > 0; repeat--){
    digitalWrite(led,HIGH);
    digitalWrite(ledMaxon,HIGH);
    delay(tempo*30);
    digitalWrite(led,LOW);
    digitalWrite(ledInt,HIGH);
    digitalWrite(ledMaxon,LOW);
    delay(tempo*30);
    digitalWrite(ledInt,LOW);
  }
}

