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
  if(data == "blinkLed"){
    //blinkLed(int ledTo, int repeat, int tempo);
    Serial.println("blinkLed TO IMPLEMENT !");
    feedback = "blinkLedEnd";
  } else if(data == "blinkLedInt"){
    //blinkLedInt(int repeat, int tempo);
    Serial.println("blinkLedInt TO IMPLEMENT !");
    feedback = "blinkLedIntEnd";
  } else if(data == "blinkAllLed"){
    //blinkAllLed(int repeat, int tempo)
    Serial.println("blinkAllLed TO IMPLEMENT !");
    feedback = "blinkAllLedEnd";
  } else if(data == "blinkRdmLed"){
    feedback = blinkRdmLed();
  } else if(data == "playOneMelody"){
    feedback = playOneMelody();
  } else if(data == "playRdmHorn"){
    playRdmHorn();
  } else if(data == "playHornWarning"){
    playHornWarning();
  } else if(data == "playHornDoUp"){
    playHornDoUp(random(1, 8));
    feedback = "playHornDoUpEnd";
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
  }else{
    feedback = "no_action";
  }
  if(feedback == NULL){
    feedback = "end";
  }
  Serial.println(feedback);
}


