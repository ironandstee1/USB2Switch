#ifndef _SimpleScripting_H_
#define _SimpleScripting_H_

#include "LUFAConfig.h"
#include <LUFA.h>
#include "Joystick.h"
#include "Descriptors.h"
#include "General.h"

using namespace std;

namespace simple {
  General general;
  unsigned long afterDelay = 50; // Choose the ms delay after inputs occur
  
  void Left(unsigned long timeHeld) {
    while (general.LeftJoystick(general.LEFT, general.STICK_CENTER, timeHeld, afterDelay) == true);
  }

  void Right(unsigned long timeHeld) {
    while (general.LeftJoystick(general.LEFT, general.STICK_CENTER, timeHeld, afterDelay) == true);
  }

  void Up(unsigned long timeHeld) {
    while (general.LeftJoystick(general.STICK_CENTER, general.UP, timeHeld, afterDelay) == true);
  }

  void Down(unsigned long timeHeld) {
    while (general.LeftJoystick(general.STICK_CENTER, general.DOWN, timeHeld, afterDelay) == true);
  }

  void A(unsigned long timeHeld) {
    while (general.PressOneButton(general.A_BUTTON, timeHeld, afterDelay));   
  }

  void B(unsigned long timeHeld) {
    while (general.PressOneButton(general.B_BUTTON, timeHeld, afterDelay));   
  }

  void X(unsigned long timeHeld) {
    while (general.PressOneButton(general.X_BUTTON, timeHeld, afterDelay));   
  }

  void Y(unsigned long timeHeld) {
    while (general.PressOneButton(general.Y_BUTTON, timeHeld, afterDelay));   
  }

  void ZL(unsigned long timeHeld) {
    while (general.PressOneButton(general.ZL_BUTTON, timeHeld, afterDelay));   
  }
  
  void ZR(unsigned long timeHeld) {
    while (general.PressOneButton(general.ZR_BUTTON, timeHeld, afterDelay));   
  }

  void LB(unsigned long timeHeld) {
    while (general.PressOneButton(general.LB_BUTTON, timeHeld, afterDelay));   
  }
  
  void RB(unsigned long timeHeld) {
    while (general.PressOneButton(general.RB_BUTTON, timeHeld, afterDelay));   
  }

  void Home(unsigned long timeHeld) {
    while (general.PressOneButton(general.HOME_BUTTON, timeHeld, afterDelay));   
  }

  void Capture(unsigned long timeHeld) {
    while (general.PressOneButton(general.CAPTURE_BUTTON, timeHeld, afterDelay));   
  }

  void Nothing(unsigned long timeHeld) {
    while (general.Nothing(timeHeld));
  }
}



#endif
