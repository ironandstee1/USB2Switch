#include "ACNH.h"
#include "Descriptors.h"
#include "Joystick.h"

void ACNH::starFarm() {
  while (general.RightJoystick(128, 0, 500, 10));
  while (general.PressOneButton(general.A_BUTTON, 150, 150));
  return;
}

void ACNH::diySpam() {
  while (general.PressOneButton(general.A_BUTTON, 150, 150));
  return;
}

void ACNH::fruitFarm(int columnNumber, int rowNumber) {
  for (int i = 0; i < 5; i++) {
    while (general.LeftJoystick(128, 0, 600, 50));
  }
  while (general.LeftJoystick(128, 250, 600, 300));
  while (general.LeftJoystick(200, 128, 400, 300));  
  while (general.PressOneButton(general.A_BUTTON, 300, 2000));
  while (general.LeftJoystick(128, 200, 200, 300));
  for (int i = 0; i < rowNumber; i++) {
    for (int j = 0; j < columnNumber; j++) {
      while (general.LeftJoystick(128, 250, 600, 300));
      while (general.LeftJoystick(200, 128, 400, 300));  
      while (general.PressOneButton(general.A_BUTTON, 300, 2000));
      while (general.LeftJoystick(128, 200, 200, 300));
    }
    while (general.LeftJoystick(128, 250, 1200, 300));
    while (general.LeftJoystick(250, 128, 650, 300));
    while (general.Nothing(1000));
  }
  return;
}
