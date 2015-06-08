// Buzzer
const int buzzer = 8;

// Horn
const int horn = 5;

// buzzMaxon
const int buzzMaxon = A1;

void playMelody(int melodyNotes[], int n, int melodyTempo[], int modeSpeaker){
  int speaker = modeSpeaker;
  //int rdmTempo = 1.5;
  for(int i = 0; i < n; i++){
    if(modeSpeaker > 3) speaker = random(1,4);
    if(speaker == 1){
      speaker = buzzer;
      digitalWrite(led, HIGH);
    }
    else if(speaker == 2){
      speaker = buzzMaxon;
      digitalWrite(ledMaxon, HIGH);
      delay(50);
    }
    else if(speaker == 3){
      speaker = horn;
      digitalWrite(ledInt, HIGH);
      delay(50);
    }
    int rdmTempo = random(0,5);
    rdmTempo = (rdmTempo*0.05)+1;
    tone(speaker, melodyNotes[i], melodyTempo[i] * rdmTempo);
    //int pauseBetweenNotes = melodyTempo[i];
    int pauseBetweenNotes = melodyTempo[i] * 1.3;
    int p2 = pauseBetweenNotes / 2;
    delay(p2);
    delay(p2);
    if(speaker == buzzer) digitalWrite(led,LOW);
    else if(speaker == buzzMaxon) digitalWrite(ledMaxon,LOW);
    else if(speaker == horn) digitalWrite(ledInt,LOW);
  }
}

void toneAll(int melodyNotes[], int n, int melodyTempo[]){
  for(int i = 0; i < n; i++){
    digitalWrite(led,HIGH);
    
    tone(horn, melodyNotes[i], melodyTempo[i]);

    int pauseBetweenNotes = melodyTempo[i] * 1.3;
    int p2 = pauseBetweenNotes / 2;
    delay(p2);
    digitalWrite(led,LOW);
    delay(p2);
  }
}

void playHornWarning(){
  digitalWrite(ledInt, HIGH);
  int freqTempo = 30;
  for(int i = freqTempo; i < 160; i++){
    if(i > 30 && i < 50) {
      tone(horn, i, 1000);
      delay(i*1.1);
      freqTempo = i;
    }
    else if(i > 50) {
      tone(horn, i, 500);
      delay(i*0.5);
      freqTempo = i;
    }
  }
  for(int i = 0; i < 10; i++){
      tone(horn, freqTempo);
  }
  for(int j = freqTempo; j > 0; j--){
    if(j > 50) {
      tone(horn, j, 1000);
      delay(j*0.3);
    }
    else if(j > 30 && j < 50) {
      tone(horn, j, 1000);
      delay(j*0.5);
    }
  }
  noTone(horn);
  digitalWrite(ledInt, LOW);
}
void playHorn(){
  digitalWrite(ledInt, HIGH);
  int freqTempo = 600;
  for(int i = freqTempo; i < 2000; i++){
    if(i > 600 && i < 1000) {
      tone(horn, i, 1000);
      delay(i*0.0005);
      freqTempo = i;
    }
    else if(i > 1000) {
      tone(horn, i, 1000);
      delay(i*0.001);
      freqTempo = i;
    }
  }
  noTone(horn);
  delay(1200);
  tone(horn, freqTempo, 1000);
  delay(800);
  noTone(horn);
  digitalWrite(ledInt, LOW);
}

void playHornBombing(int repeat){
  digitalWrite(ledInt, HIGH);
  int freqTempo = 5000;
  for(int i = freqTempo; i > 3500; i--){
    tone(horn, i, 500);
    delay(i*0.0004);
  }
  for(repeat; repeat > 0; repeat--){
    freqTempo = 700;
    for(int i = freqTempo; i > 30; i--){
      tone(horn, i, 500);
      delay(i*0.001);
    }
  }
    digitalWrite(ledInt, LOW);
    noTone(horn);
    delay(500);
}

void playHornOvni(){
  digitalWrite(ledInt, HIGH);
  int freqTempo = 1300;
  for(int i = freqTempo; i < 2500; i++){
    tone(horn, i, 500);
    delay(i*0.0008);
    freqTempo = i;
  }
  digitalWrite(ledInt, LOW);
  for(int i = freqTempo; i > 1200; i--){
    tone(horn, i, 500);
    delay(i*0.0004);
  }
  freqTempo = 500;
  for(int i = freqTempo; i < 1300; i++){
    tone(horn, i, 500);
    delay(i*0.0001);
  }
  noTone(horn);
  delay(500);
}

void playHornWhistle(){
  digitalWrite(ledInt, HIGH);
  int freqTempo = 2200;
  for(int i = freqTempo; i < 2800; i++){
    tone(horn, i, 500);
    delay(i*0.0002);
    freqTempo = i;
  }
  digitalWrite(ledInt, LOW);
  for(int i = freqTempo; i > 1200; i--){
    tone(horn, i, 500);
    delay(i*0.0004);
  }
  noTone(horn);
  delay(500);
}

void playHornSiren(int repeat){
  for(repeat; repeat > 0; repeat--){
    digitalWrite(ledInt, HIGH);
    int freqTempo = 2000;
    for(int i = freqTempo; i < 2500; i++){
      tone(horn, i, 500);
      delay(i*0.0002);
      freqTempo = i;
    }
    digitalWrite(ledInt, LOW);
    for(int i = freqTempo; i > 1500; i--){
      tone(horn, i, 500);
      delay(i*0.0004);
    }
    noTone(horn);
  }
  delay(500);
}

void playHornFire(int repeat){
  for(repeat; repeat > 0; repeat--){
    digitalWrite(ledInt, HIGH);
    int freqTempo = 800;
    for(int i = freqTempo; i < 1000; i++){
      tone(horn, i, 500);
      delay(i*0.0007);
      freqTempo = i;
    }
    digitalWrite(ledInt, LOW);
    for(int i = freqTempo; i > 400; i--){
      tone(horn, i, 500);
      delay(i*0.0007);
    }
    noTone(horn);
  }
  delay(500);
}

void playHornDown(){
  digitalWrite(ledInt, HIGH);
  int freqTempo = 30;
  for(int i = freqTempo; i > 20; i--){
    tone(horn, i, 500);
    delay(100);
  }
  noTone(horn);
  delay(1000);
  tone(horn, 33, 500);
  delay(300);
  noTone(horn);
  digitalWrite(ledInt, LOW);
  delay(500);
}

void playHornOff(){
  digitalWrite(ledInt, HIGH);
  int freqTempo = 500;
  for(int i = 0; i < 3; i++){
      tone(horn, freqTempo, 1000);
      delay(200);
      noTone(horn);
      delay(100);
  }
  for(int i = freqTempo; i > 0;i--){
    tone(horn, i, 500);
    delay(i*0.004);
  }
  noTone(horn);
  digitalWrite(ledInt, LOW);
}

void playHornDoUp(int repeat){
  for(repeat; repeat > 0; repeat--){
    digitalWrite(ledInt, HIGH);
    int freqTempo = 300;
    for(int i = freqTempo; i < 1000; i++){
      if(i > 300 && i < 500) {
        tone(horn, i, 1000);
        delay(i*0.0001);
        freqTempo = i;
      }
      else if(i > 500) {
        tone(horn, i, 500);
        delay(i*0.001);
        freqTempo = i;
      }
    }
    noTone(horn);
    digitalWrite(ledInt, LOW);
  }
}


void playRandomMelody(int modeSpeaker){
  int speaker = modeSpeaker;
  int duration = random(1,13);
  for(duration; duration > 0; duration--){
    int note = random(1,90);
    switch (note) {
      case 1 : note = 31;
      break;
      case 2 : note = 33;
      break;
      case 3 : note =  35;
      break;
      case 4 : note = 37;
      break;
      case 5 : note = 39;
      break;
      case 6 : note = 41;
      break;
      case 7 : note = 44;
      break;
      case 8 : note = 46;
      break;
      case 9 : note = 49;
      break;
      case 10 : note = 52;
      break;
      case 11 : note = 55;
      break;
      case 12 : note = 58;
      break;
      case 13 : note = 62;
      break;
      case 14 : note = 65;
      break;
      case 15 : note = 69;
      break;
      case 16 : note = 73;
      break;
      case 17 : note = 78;
      break;
      case 18 : note = 82;
      break;
      case 19 : note = 87;
      break;
      case 20 : note = 93;
      break;
      case 21 : note = 98;
      break;
      case 22 : note = 104;
      break;
      case 23 : note = 110;
      break;
      case 24 : note = 117;
      break;
      case 25 : note = 123;
      break;
      case 26 : note = 131;
      break;
      case 27 : note = 139;
      break;
      case 28 : note = 147;
      break;
      case 29 : note = 156;
      break;
      case 30 : note = 165;
      break;
      case 31 : note = 175;
      break;
      case 32 : note = 185;
      break;
      case 33 : note = 196;
      break;
      case 34 : note = 208;
      break;
      case 35 : note = 220;
      break;
      case 36 : note = 233;
      break;
      case 37 : note = 247;
      break;
      case 38 : note = 262;
      break;
      case 39 : note = 277;
      break;
      case 40 : note = 294;
      break;
      case 41 : note = 311;
      break;
      case 42 : note = 330;
      break;
      case 43 : note = 349;
      break;
      case 44 : note = 370;
      break;
      case 45 : note = 392;
      break;
      case 46 : note = 415;
      break;
      case 47 : note = 440;
      break;
      case 48 : note = 466;
      break;
      case 49 : note = 494;
      break;
      case 50 : note = 523;
      break;
      case 51 : note = 554;
      break;
      case 52 : note = 587;
      break;
      case 53 : note = 622;
      break;
      case 54 : note = 659;
      break;
      case 55 : note = 698;
      break;
      case 56 : note = 740;
      break;
      case 57 : note = 784;
      break;
      case 58 : note = 831;
      break;
      case 59 : note = 880;
      break;
      case 60 : note = 932;
      break;
      case 61 : note = 988;
      break;
      case 62 : note = 1047;
      break;
      case 63 : note = 1109;
      break;
      case 64 : note = 1175;
      break;
      case 65 : note = 1245;
      break;
      case 66 : note = 1319;
      break;
      case 67 : note = 1397;
      break;
      case 68 : note = 1480;
      break;
      case 69 : note = 1568;
      break;
      case 70 : note = 1661;
      break;
      case 71 : note = 1760;
      break;
      case 72 : note = 1865;
      break;
      case 73 : note = 1976;
      break;
      case 74 : note = 2093;
      break;
      case 75 : note = 2217;
      break;
      case 76 : note = 2349;
      break;
      case 77 : note = 2489;
      break;
      case 78 : note = 2637;
      break;
      case 79 : note = 2794;
      break;
      case 80 : note = 2960;
      break;
      case 81 : note = 3136;
      break;
      case 82 : note = 3322;
      break;
      case 83 : note = 3520;
      break;
      case 84 : note = 3729;
      break;
      case 85 : note = 3951;
      break;
      case 86 : note = 4186;
      break;
      case 87 : note = 4435;
      break;
      case 88 : note = 4699;
      break;
      case 89 : note = 4978;
      break;
      default: note = 4978;
      break;
   }
   if(modeSpeaker > 3) speaker = random(1,4);
   if(speaker == 1){
     speaker = buzzer;
     digitalWrite(led, HIGH);
   }
   else if(speaker == 2){
     speaker = buzzMaxon;
     digitalWrite(ledMaxon, HIGH);
   }
   else if(speaker == 3){
     speaker = horn;
     digitalWrite(ledInt, HIGH);
   }
   int tempo = random(20,500);
   note = random(50,800);
   tone(speaker, note, tempo);
   //int pauseBetweenNotes = tempo * 1.3;
   //int p2 = pauseBetweenNotes / 2;
   //delay(p2);
   delay(random(1,20)*10);
   if(speaker == buzzer) digitalWrite(led, LOW);
   else if(speaker == buzzMaxon) digitalWrite(ledMaxon, LOW);
   else if(speaker == horn) digitalWrite(ledInt, LOW);
   //delay(random(0,3)*100);
   }
}



