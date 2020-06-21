#include "PokemonEggHatching.h"
#include "Descriptors.h"
#include "Joystick.h"

void PokemonEggHatching::boxHatch(const int boxes) {
  for (int i = 0; i < 20; i++) {
    while (general.PressOneButton(general.B_BUTTON, 100, 50) == true);   
  }

  partySwap(1);
  
  for (int j = 0; j < 20; j++) {
    while (general.PressOneButton(general.B_BUTTON, 100, 100) == true);
  }

  for (int k = 0; k < 5; k++) {
    boxHatchPath();
  }
  
  for (int l = 0; l < 5; l++) {
    eggHatchSequence();
    //while (general.LeftJoystick(general.RIGHT, general.STICK_DOWN, 200, 100) == true);
  }

  partySwap(2);

  
  boxHatchPath();
}

void PokemonEggHatching::boxHatchPath() {
  while (general.LeftJoystick(general.LEFT, general.STICK_CENTER, 1000, 50) == true);
  while (general.LeftJoystick(general.LEFT, general.DOWN, 100, 50) == true);
  while (general.LeftJoystick(general.STICK_CENTER, general.DOWN, 100, 50) == true);
  while (general.LeftJoystick(general.RIGHT, general.DOWN, 100, 50) == true);
  for (int i = 0; i < 16; i++) {
     while (general.LeftJoystickOneButton(general.RIGHT, general.STICK_CENTER, general.B_BUTTON, 1000, 0) == true); 
  }
  while (general.LeftJoystick(general.RIGHT, general.STICK_CENTER, 150, 50) == true);
  while (general.LeftJoystick(general.RIGHT, general.DOWN, 150, 50) == true);
  while (general.LeftJoystick(general.LEFT, general.DOWN, 3000, 50) == true);
  for (int j = 0; j < 4; j++) {
    while (general.LeftJoystickOneButton(general.LEFT, general.STICK_CENTER, general.B_BUTTON, 2700, 0) == true);
    while (general.LeftJoystick(general.LEFT, general.STICK_CENTER, 100, 0) == true);
  }
}


void PokemonEggHatching::partySwap(int column) {
  while (general.PressOneButton(general.X_BUTTON, 100, 1200) == true);
  while (general.PressOneButton(general.A_BUTTON, 100, 2000) == true);
  while (general.PressOneButton(general.RB_BUTTON, 100, 2000) == true);
  while (general.LeftJoystick(general.LEFT, general.STICK_CENTER, 100, 100) == true);
  for (int i = 0; i < 5; i++) {
    while (general.PressOneButton(general.A_BUTTON, 100, 500) == true);   
    while (general.PressOneButton(general.A_BUTTON, 100, 500) == true);
    for (int j = 0; j < column; j++) {
      while (general.LeftJoystick(general.RIGHT, general.STICK_CENTER, 100, 200) == true);
    }
    while (general.PressOneButton(general.A_BUTTON, 100, 300) == true);
    while (general.LeftJoystick(general.STICK_CENTER, general.DOWN, 100, 100) == true);   
    for (int j = 0; j < column; j++) {
      while (general.LeftJoystick(general.LEFT, general.STICK_CENTER, 100, 200) == true);
    }
  }
  for (int l = 0; l < 10; l++) {
    while (general.PressOneButton(general.B_BUTTON, 100, 200) == true); 
  }
}

void PokemonEggHatching::circleCW(int numberOfCircles) {
  for (int i = 0; i < numberOfCircles; i++) {
    while (general.LeftJoystick(general.STICK_CENTER, general.UP, 100, 1) == true);
    while (general.LeftJoystick(general.RIGHT, general.UP, 100, 1) == true);
    while (general.LeftJoystick(general.RIGHT, general.STICK_CENTER, 100, 1) == true);
    while (general.LeftJoystick(general.RIGHT, general.DOWN, 100, 1) == true);
    while (general.LeftJoystick(general.STICK_CENTER, general.DOWN, 100, 1) == true);
    while (general.LeftJoystick(general.LEFT, general.DOWN, 100, 1) == true);
    while (general.LeftJoystick(general.LEFT, general.STICK_CENTER, 100, 1) == true);
    while (general.LeftJoystick(general.LEFT, general.UP, 100, 1) == true);
  }
  return;
}

void PokemonEggHatching::eggHatch(const int eggSteps) {
  general.Nothing(1000);
  returnToDaycare();
  getEgg(1);
  while (general.LeftJoystick(general.LEFT, general.STICK_CENTER, 800, 500) == true);
  if (eggSteps == 2560) {
    circleCW(44);
    while (general.LeftJoystick(general.STICK_CENTER, general.DOWN, 1000, 100) == true);
    eggHatchSequence();
  }
  else if (eggSteps == 3840) {
    circleCW(67);
    while (general.LeftJoystick(general.STICK_CENTER, general.DOWN, 1000, 100) == true);
    eggHatchSequence();
  }
  else if ((eggSteps == 5120) || (eggSteps == 6400)) {
    if (eggSteps == 5120) {
      circleCW(44);      
    }
    else {
      circleCW(58);
    }

    returnToDaycare();
    getEgg(2);
    while (general.LeftJoystick(general.LEFT, general.STICK_CENTER, 800, 500) == true); 
    if (eggSteps == 5120) {
      circleCW(35);  
    }
    else {
      circleCW(48);
    }
    while (general.LeftJoystick(general.STICK_CENTER, general.DOWN, 1000, 100) == true);
    eggHatchSequence();
    returnToDaycare();
    while (general.LeftJoystick(general.LEFT, general.STICK_CENTER, 800, 500) == true); 
    if (eggSteps == 5120) {
      circleCW(50);  
    }
    else {
      circleCW(68);
    }
    while (general.LeftJoystick(general.STICK_CENTER, general.DOWN, 1000, 100) == true);
    eggHatchSequence();
  }
  else if (eggSteps == 7680) {
    circleCW(44);
    returnToDaycare();
    getEgg(2);
    while (general.LeftJoystick(general.LEFT, general.STICK_CENTER, 800, 500) == true);
    circleCW(44);
    while (general.LeftJoystick(general.STICK_CENTER, general.DOWN, 1000, 100) == true);    
    returnToDaycare();
    getEgg(3);
    while (general.LeftJoystick(general.LEFT, general.STICK_CENTER, 800, 500) == true);
    circleCW(42);
    while (general.LeftJoystick(general.STICK_CENTER, general.DOWN, 1000, 100) == true);    
    eggHatchSequence();
    returnToDaycare();
    while (general.LeftJoystick(general.LEFT, general.STICK_CENTER, 800, 500) == true);
    circleCW(44);
    while (general.LeftJoystick(general.STICK_CENTER, general.DOWN, 1000, 100) == true);    
    eggHatchSequence();
    returnToDaycare();
    while (general.LeftJoystick(general.LEFT, general.STICK_CENTER, 800, 500) == true);
    circleCW(50);
    while (general.LeftJoystick(general.STICK_CENTER, general.DOWN, 1000, 100) == true);    
    eggHatchSequence();
  }
  else if (eggSteps == 8960) {
    circleCW(44);
    returnToDaycare();
    getEgg(2);
    while (general.LeftJoystick(general.LEFT, general.STICK_CENTER, 800, 500) == true);
    circleCW(44);
    while (general.LeftJoystick(general.STICK_CENTER, general.DOWN, 1000, 100) == true);    
    returnToDaycare();
    getEgg(3);
    while (general.LeftJoystick(general.LEFT, general.STICK_CENTER, 800, 500) == true);
    circleCW(50);
    while (general.LeftJoystick(general.STICK_CENTER, general.DOWN, 1000, 100) == true);
    eggHatchSequence(); 
    returnToDaycare();
    while (general.LeftJoystick(general.LEFT, general.STICK_CENTER, 800, 500) == true);
    circleCW(52);
    while (general.LeftJoystick(general.STICK_CENTER, general.DOWN, 1000, 100) == true);    
    eggHatchSequence();
    returnToDaycare();
    while (general.LeftJoystick(general.LEFT, general.STICK_CENTER, 800, 500) == true);
    circleCW(48);
    while (general.LeftJoystick(general.STICK_CENTER, general.DOWN, 1000, 100) == true);    
    eggHatchSequence();
    returnToDaycare();
  }
  else if (eggSteps == 10240) {
    circleCW(44);
    returnToDaycare();
    getEgg(2);
    while (general.LeftJoystick(general.LEFT, general.STICK_CENTER, 800, 500) == true);
    circleCW(44);
    while (general.LeftJoystick(general.STICK_CENTER, general.DOWN, 1000, 100) == true);    
    returnToDaycare();
    getEgg(3);
    while (general.LeftJoystick(general.LEFT, general.STICK_CENTER, 800, 500) == true);
    circleCW(44);
    while (general.LeftJoystick(general.STICK_CENTER, general.DOWN, 1000, 100) == true);    
    returnToDaycare();
    getEgg(4);
    while (general.LeftJoystick(general.LEFT, general.STICK_CENTER, 800, 500) == true);
    circleCW(30);
    while (general.LeftJoystick(general.STICK_CENTER, general.DOWN, 1000, 100) == true);
    eggHatchSequence(); 
    returnToDaycare();
    while (general.LeftJoystick(general.LEFT, general.STICK_CENTER, 800, 500) == true);
    circleCW(52);
    while (general.LeftJoystick(general.STICK_CENTER, general.DOWN, 1000, 100) == true);    
    eggHatchSequence();
    returnToDaycare();
    while (general.LeftJoystick(general.LEFT, general.STICK_CENTER, 800, 500) == true);
    circleCW(48);
    while (general.LeftJoystick(general.STICK_CENTER, general.DOWN, 1000, 100) == true);    
    eggHatchSequence();
    returnToDaycare();
    while (general.LeftJoystick(general.LEFT, general.STICK_CENTER, 800, 500) == true);
    circleCW(48);
    while (general.LeftJoystick(general.STICK_CENTER, general.DOWN, 1000, 100) == true);    
    eggHatchSequence();
    returnToDaycare();
  }
  return;
}

void PokemonEggHatching::eggCollect() {
  while (general.PressOneButton(general.B_BUTTON, 100, 100) == true); 
  while (general.PressOneButton(general.B_BUTTON, 100, 100) == true); 
  while (general.PressOneButton(general.B_BUTTON, 100, 100) == true);
  while (general.LeftJoystick(general.RIGHT, general.UP, 4000, 100) == true);
  depositEgg();
  while (general.LeftJoystick(general.LEFT, general.DOWN, 1500, 100) == true); 
  circleCW(40);
  while (general.LeftJoystick(general.STICK_CENTER, general.UP, 300, 100) == true);
}

void PokemonEggHatching::depositEgg() {
  while (general.PressOneButton(general.A_BUTTON, 100, 1000) == true);
  while (general.PressOneButton(general.A_BUTTON, 100, 500) == true);
  
  // Exits before pokemon are taken back if egg is not available
  for (int i = 0; i < 25; i++) {
    while (general.PressOneButton(general.B_BUTTON, 150, 150) == true);   
  }
}

void PokemonEggHatching::eggHatchSequence() {
  while (general.PressOneButton(general.B_BUTTON, 300, 3000) == true);
  while (general.PressOneButton(general.B_BUTTON, 300, 3000) == true);
  while (general.PressOneButton(general.B_BUTTON, 300, 3000) == true);
  while (general.PressOneButton(general.B_BUTTON, 300, 3000) == true);
  while (general.PressOneButton(general.B_BUTTON, 300, 3000) == true);
  while (general.PressOneButton(general.B_BUTTON, 300, 3000) == true);  
  return;
}

void PokemonEggHatching::getEgg(int eggNumber) {
  while (general.PressOneButton(general.A_BUTTON, 100, 1000) == true);
  while (general.PressOneButton(general.A_BUTTON, 100, 500) == true);
  
  // Exits before pokemon are taken back if egg is not available
  while (general.PressOneButton(general.B_BUTTON, 150, 150) == true);
  while (general.PressOneButton(general.B_BUTTON, 150, 150) == true);
  while (general.PressOneButton(general.B_BUTTON, 150, 150) == true);
  while (general.LeftJoystick(general.LEFT, general.DOWN, 300, 1) == true);

  while (general.PressOneButton(general.A_BUTTON, 150, 1500) == true);
  while (general.PressOneButton(general.A_BUTTON, 100, 1000) == true);
  while (general.PressOneButton(general.A_BUTTON, 100, 1000) == true);
  while (general.PressOneButton(general.A_BUTTON, 100, 1000) == true);
  while (general.PressOneButton(general.A_BUTTON, 100, 1500) == true);

  // Change egg slot based on egg number
  for (int i = 0; i < eggNumber; i++) {
    if (i != 0) { while(general.LeftJoystick(general.STICK_CENTER, general.DOWN, 100, 300) == true); }
  }

  while (general.PressOneButton(general.A_BUTTON, 100, 2500) == true);
  while (general.PressOneButton(general.B_BUTTON, 100, 2500) == true);
  while (general.PressOneButton(general.B_BUTTON, 100, 2500) == true);
  return;
}

void PokemonEggHatching::returnToDaycare() {
  while (general.LeftJoystick(general.STICK_CENTER, general.UP, 1000, 100) == true);
  while (general.LeftJoystick(general.RIGHT, general.UP, 5000, 100) == true);
}

