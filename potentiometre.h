// Button
const int pinPot = A3;
float rythm = 1.0;
float rythmB = 1.0;

float getPotValue(){
  int sensorValue = analogRead(pinPot);
  //float volt = sensorValue * (100.0 / 1023.0);
  float volt = sensorValue * (20.0 / 1023.0);
  //Serial.println(volt);
  rythm = volt;
  if(rythm < 1) rythm = 1;
  else if(rythm > 18) rythm = 100;
  //else if (rythm > 8 ) rythm = rythm*rythm;
  //else if (rythm > 20 ) rythm = rythm*2;
  Serial.println(rythm);
  return rythm;
}

