// Button
const int pinPot = A3;
float rythm = 1.0;

float getPotValue(){
  int sensorValue = analogRead(pinPot);
  float rythm = sensorValue * (20.0 / 1023.0);
  if(rythm < 1) rythm = 1;
  else if(rythm > 18) rythm = 100;
  Serial.println(rythm);
  return rythm;
}

