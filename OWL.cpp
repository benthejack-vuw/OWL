#include <Arduino.h>
#include "OWL.h"

bool OWL::connect(int baud){
  Serial.begin(baud);
  while (!Serial) {
     // wait for serial port to connect. Needed for native USB port only
  }
  return establishContact();
}

void OWL::statusPin(int pin){
  _statusPin = pin;
  pinMode(_statusPin, OUTPUT);
}

bool OWL::establishContact(){
  long time = millis();
  String handshake = "";
  while(handshake != "arduinoServer"){
    while (Serial.available() <= 0) {
      Serial.println("arduino");   // send a capital C
      delay(200);
    }
    handshake = Serial.readStringUntil('\n');
  }
  return handshake == "arduinoServer";
}

void OWL::sendCommand(String command, String arg){
  Serial.println(command+"~"+arg+"|");
}

OWLCommand OWL::awaitReply(){
  bool toggle = false;

  while(!Serial.available()){
    if(_statusPin >= 0){
        digitalWrite(_statusPin, toggle);
        toggle = !toggle;
    }
    delay(200);
  }

  if(_statusPin >= 0){
    digitalWrite(_statusPin, LOW);
  }

  return pollSerial();
}

bool OWL::isResponseQueued(){
  return Serial.available();
}

OWLCommand OWL::pollSerial(){

  OWLCommand output_command = {true, "", ""};

  if(isResponseQueued()){
    String reply;
    while(Serial.available()){
        reply = Serial.readStringUntil('|');
        Serial.flush();
    }

    String command, data;
    int delimIndex = reply.indexOf('~');

    if(delimIndex >= 0){
      command = reply.substring(0, delimIndex);
      data    = reply.substring(delimIndex + 1);
    }else{
      command = "";
      data = reply;
    }

     output_command = {false, command, data};
  }

  return output_command;
}
