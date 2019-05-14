typedef struct{
  bool empty;
  String command;
  String data;
}OWLCommand;

class OWL{
public:
  bool connect(long baud);
  void statusPin(int pin);
  bool establishContact();
  void sendCommand(String command, String arg);
  bool isResponseQueued();
  OWLCommand awaitReply();
  OWLCommand pollSerial();
private:
  int _statusPin;
};
