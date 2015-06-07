// Button
const int pinPot = A3;
float rythm = 1.0;

float getPotValue(){
  int sensorValue = analogRead(pinPot);
  float volt = sensorValue * (5.0 / 1023.0);
  //Serial.println(volt);
  rythm = volt*2;
  if(rythm < 1) rythm = 1;
  else if (rythm > 8 ) rythm = rythm*rythm;
  //else if (rythm > 20 ) rythm = rythm*2;
  Serial.println(rythm);
  return rythm;
}

