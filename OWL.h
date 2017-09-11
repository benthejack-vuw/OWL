class OWL{
public:
  bool connect(int baud);
  bool establishContact();
 
  void sendCommand(String command, String arg);
    
  int await_i();
  float await_f();
  String await_s();
};
