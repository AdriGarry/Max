// Serial Parser

void parseSerialToAction(String data) {
  //Serial.println(data);
    /*char *test = new char[msg.length() + 1];
  msg.toCharArray(test, msg.length() + 1);
  char *splitted = strtok(test, "-");
  while (splitted != NULL)
  {
    Serial.println(splitted);
    splitted = strtok (NULL, " ,.-");
  }*/

  String feedback;
  feedback = "";
  if(data == "blinkLed"){
    //blinkLed(int ledTo, int repeat, int tempo);
    Serial.println("blinkLed TO IMPLEMENT !");
  } else if(data == "blinkLedInt"){
    Serial.println("blinkLedInt TO IMPLEMENT !");
  } else if(data == "blinkAllLed"){
    blinkAllLed(5, 10);
    Serial.println("blinkAllLed TO IMPLEMENT !");
  } else if(data == "blinkRdmLed"){
    blinkRdmLed();
  } else if(data == "playOneMelody"){
    playOneMelody();
  } else if(data == "playRdmMelody"){
    playRdmMelody();
  } else if(data == "playRdmHorn"){
    playRdmHorn();
  } else if(data == "playHornWarning"){
    playHornWarning();
  } else if(data == "playHornDoUp"){
    playHornDoUp(random(1, 8));
  } else if(data == "playHorn"){
    playHorn();
  } else if(data == "playHornOff"){
    playHornOff();
  } else if(data == "playHornFire"){
    playHornFire(random(1, 5));
  } else if(data == "playHornWhistle"){
    playHornWhistle();
  } else if(data == "playHornOvni"){
    playHornOvni();
  } else if(data == "playHornBombing"){
    playHornBombing(random(1, 5));
  } else if(data == "playHornSiren"){
    playHornSiren(random(3, 7));
  } else if(data == "playHornDown"){
    playHornDown();
  } else if(data == "turnNose"){
    turnNose();
  }else{
    feedback = "no_action: ";
  }
  //if(feedback == NULL){
    //feedback = "NULL";
  //}
  feedback = feedback + data + "_end";
  Serial.println(feedback);
}


