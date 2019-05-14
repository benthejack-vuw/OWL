#include "OWL.h"

OWL o;

void setup() {
  // put your setup code here, to run once:
  o.connect(115200);
  
}

void loop() {
  // put your main code here, to run repeatedly:
  
  o.sendCommand("get_hours", " ");
  OWLCommand hour_response = o.awaitReply();
  int Hours = hour_response.data.toInt();
  
  o.sendCommand("get_minutes", " ");
  OWLCommand  minute_response = o.awaitReply();
  int Minutes = minute_response.data.toInt();
 
  o.sendCommand("get_seconds", " ");
  OWLCommand  second_response = o.awaitReply();
  int Seconds = second_response.data.toInt();
  
  o.sendCommand("get_millis", " ");
  OWLCommand  millis_response = o.awaitReply(); 
  int Millis = millis_response.data.toInt();
  
//o.sendCommand("println", "The time is: "+String(hour_response.data)+":"+String(minute_response.data)+":"+String(second_response.data));
o.sendCommand("println", "The time is: "+String(Hours)+":"+String(Minutes)+":"+String(Seconds)+":"+String(Millis));

if (Seconds > 18 && Seconds < 23){
digitalWrite(LED_BUILTIN, HIGH);
}
else {
digitalWrite(LED_BUILTIN, LOW);
}
}
