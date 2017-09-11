#include <Arduino.h>
#include "OWL.h"

bool OWL::connect(int baud){
  pinMode(13, OUTPUT);
  Serial.begin(baud);
  while (!Serial) {
    ; // wait for serial port to connect. Needed for native USB port only
  }
  return establishContact();
}

bool OWL::establishContact(){
  long time = millis();
  String handshake = "";
  while(handshake != "arduinoServer\n"){
    while (Serial.available() <= 0) {
      Serial.println("arduino");   // send a capital C
      delay(200);
    }
    handshake = Serial.readStringUntil("\n");
  }
  return handshake == "arduinoServer";
}

void OWL::sendCommand(String command, String arg){
  Serial.println(command+":"+arg);
}
