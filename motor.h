// Motor
const int motor = A0;

void turn(int repeat, int tempo){
  for(repeat; repeat > 0; repeat--){
    digitalWrite(motor, HIGH);
    delay(tempo*20);
    digitalWrite(motor, LOW);
    delay(tempo*50);
  }
}


void turnTest(){
  for(int i = 0; i < 10; i++){
    digitalWrite(motor, HIGH);
    delay(100);
    digitalWrite(motor, LOW);
    delay(800);
  }
}

