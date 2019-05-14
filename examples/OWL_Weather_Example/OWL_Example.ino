#include <OWL.h>

OWL o;

void setup() {
  // put your setup code here, to run once:
  o.connect(9600);
}

void loop() {
  // put your main code here, to run repeatedly:

  o.sendCommand("get_humidity", " ");
  OWLCommand response = o.awaitReply();
  o.sendCommand("println", "humidity is"+String(response.data));

  int humidity = response.data.toInt();

   /*if(humidity.data > 70){
    digitalWrite(13, HIGH);
  }*/

}
