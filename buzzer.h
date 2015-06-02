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
    }
    else if(speaker == 3) speaker = horn;
    int rdmTempo = random(0,4);
    rdmTempo = (rdmTempo*0.01)+1;
    tone(speaker, melodyNotes[i], melodyTempo[i]);
    int pauseBetweenNotes = melodyTempo[i] * rdmTempo;
    //int pauseBetweenNotes = melodyTempo[i] * 1.3;
    int p2 = pauseBetweenNotes / 2;
    delay(p2);
    if(speaker == buzzMaxon) digitalWrite(ledMaxon,LOW);
    else digitalWrite(led,LOW);
    delay(p2);
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
}
void playHorn(){
  digitalWrite(led, HIGH);
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
  digitalWrite(led, LOW);
}

void playHornOff(){
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
}

void playHornDoUp(){
  digitalWrite(led, HIGH);
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
  digitalWrite(led, LOW);
}

