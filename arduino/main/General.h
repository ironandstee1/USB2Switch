#ifndef _General_H_
#define _General_H_

#include "LUFAConfig.h"
#include <LUFA.h>
#include "Joystick.h"
#include "Descriptors.h"

using namespace std;

class General {

  public:
  
  General::General() {}

  /// Handles LUFA related USB tasks
  void handleUSB();

  /// Delay added to avoid startup issues
  void setupDelay();

  bool handshake();

  char getChar(String incomingMessage);

  String getString(char selectedChar);

  int getInteger(String incomingMessage);

  int getButton(char selectChar);

  void executeMemScript();

  bool PressOneButton(int button, unsigned long pressDuration, unsigned long waitDuration);
  bool PressTwoButtons(int buttonOne, int buttonTwo, unsigned long pressDuration, unsigned long waitDuration);
  bool LeftJoystick(int joystickXVal, int joystickYVal, unsigned long joystickDuration, unsigned long waitDuration);
  bool LeftJoystickOneButton(int joystickXVal, int joystickYVal, int button, unsigned long joystickDuration, unsigned long waitDuration);
  bool LeftJoystickTwoButtons(int joystickXVal, int joystickYVal, int buttonOne, int buttonTwo, unsigned long joystickDuration, unsigned long waitDuration);
  bool RightJoystick(int joystickXVal, int joystickYVal, unsigned long joystickDuration, unsigned long waitDuration);
  bool RightJoystickOneButton(int joystickXVal, int joystickYVal, int button, unsigned long joystickDuration, unsigned long waitDuration);
  bool RightJoystickTwoButtons(int joystickXVal, int joystickYVal, int buttonOne, int buttonTwo, unsigned long joystickDuration, unsigned long waitDuration);
  bool BothJoysticks(int leftJoystickXVal, int leftJoystickYVal, int rightJoystickXVal, int rightJoystickYVal, unsigned long joystickDuration, unsigned long waitDuration);
  bool BothJoysticksOneButton(int leftJoystickXVal, int leftJoystickYVal, int rightJoystickXVal, int rightJoystickYVal, int button, unsigned long joystickDuration, unsigned long waitDuration);
  bool BothJoysticksTwoButtons(int leftJoystickXVal, int leftJoystickYVal, int rightJoystickXVal, int rightJoystickYVal, int buttonOne, int buttonTwo, unsigned long joystickDuration, unsigned long waitDuration);
  bool Nothing(unsigned long waitDuration);
  
  int STICK_MIN = 0;
  int STICK_CENTER = 128;
  int STICK_MAX = 255;

  int UP = 0;
  int DOWN = 255;
  int RIGHT = 255;
  int LEFT = 0;

  int HALF_UP = 64;
  int HALF_DOWN = 192;
  int HALF_RIGHT = 192;
  int HALF_LEFT = 64;

  int Y_BUTTON = 0x01;
  int B_BUTTON = 0x02;
  int A_BUTTON = 0x04;
  int X_BUTTON = 0x08;
  int LB_BUTTON = 0x10;
  int RB_BUTTON = 0x20;
  int ZL_BUTTON = 0x40;
  int ZR_BUTTON = 0x80;
  int MINUS_BUTTON = 0x100;
  int PLUS_BUTTON = 0x200;
  int L_CLICK = 0x400;
  int R_CLICK = 0x800;
  int HOME_BUTTON = 0x1000;
  int CAPTURE_BUTTON = 0x2000;

  unsigned long previousMillis = 0; 
  unsigned long currentMillis = millis();

  private:

};

#endif










