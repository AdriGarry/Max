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
    //feedback = "blinkLed_nd";
  } else if(data == "blinkLedInt"){
    //blinkLedInt(int repeat, int tempo);
    Serial.println("blinkLedInt TO IMPLEMENT !");
    //feedback = "blinkLedInt_end";
  } else if(data == "blinkAllLed"){
    //blinkAllLed(int repeat, int tempo)
    blinkAllLed(4, 20);
    Serial.println("blinkAllLed TO IMPLEMENT !");
    //feedback = "blinkAllLed_end";
  } else if(data == "blinkRdmLed"){
    blinkRdmLed();
    //feedback = "blinkRdmLed_end";
  } else if(data == "playOneMelody"){
    playOneMelody();
    //feedback = "playOneMelody_end";
  } else if(data == "playRdmMelody"){
    playRdmMelody();
    //feedback = "playRdmMelody_end";
  } else if(data == "playRdmHorn"){
    playRdmHorn();
    //feedback = "playRdmHorn_end";
  } else if(data == "playHornWarning"){
    playHornWarning();
  } else if(data == "playHornDoUp"){
    playHornDoUp(random(1, 8));
    //feedback = "playHornDoUp_end";
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
    //feedback = "turn_end";
  }else{
    feedback = "no_action: ";
  }
  //if(feedback == NULL){
    //feedback = "NULL";
  //}
  feedback = feedback + data + "_end";
  Serial.println(feedback);
}


