#include "PokemonExtra.h"
#include "Descriptors.h"
#include "Joystick.h"

PokemonExtra::PokemonExtra() {
  day = 0;
  month = 0;
  year = 0;
}
  
void PokemonExtra::wattFarming() {
  while (general.PressOneButton(general.A_BUTTON, 150, 150));
  for (int i = 0; i < 15; i++) {
    while (general.PressOneButton(general.B_BUTTON, 150, 150));
  }
  if(day < 25) {
    dayChange();
    day++; 
  }
  else if (month < 12) {
    monthChange();
    month++;
    day = 0;
  }
  else {
    yearChange();
    month = 0;
    day = 0;
  }
  return;
}

void PokemonExtra::boxRelease(const int boxes) {
  releaseSetup();
  for (int i = 0; i < boxes; i++) {
    for (int j = 0; j < 5; j++) {
      for (int k = 0; k < 6; k++) {
        pokemonRelease(); 
        while (general.LeftJoystick(general.RIGHT, general.STICK_CENTER, 100, 200));
      }
      while (general.LeftJoystick(general.RIGHT, general.STICK_CENTER, 100, 200));
      while (general.LeftJoystick(general.STICK_CENTER, general.DOWN, 200, 200));   
    }
    while (general.LeftJoystick(general.STICK_CENTER, general.DOWN, 100, 200));
    while (general.LeftJoystick(general.RIGHT, general.STICK_CENTER, 100, 200));
    while (general.LeftJoystick(general.STICK_CENTER, general.DOWN, 100, 200));
  }
  while (general.PressOneButton(general.X_BUTTON, 200, 900000));
  while (general.PressOneButton(general.X_BUTTON, 200, 900000));
  while (general.PressOneButton(general.X_BUTTON, 200, 900000));
  while (general.PressOneButton(general.X_BUTTON, 200, 900000));
  while (general.PressOneButton(general.X_BUTTON, 200, 900000));
  return;
}

void PokemonExtra::dayChange() {
  toDateTimeSettings();
  while (general.LeftJoystick(general.RIGHT, general.STICK_CENTER, 200, 400));
  while (general.LeftJoystick(general.STICK_CENTER, general.UP, 200, 100));
  while (general.LeftJoystick(general.RIGHT, general.STICK_CENTER, 1000, 200));
  while (general.PressOneButton(general.A_BUTTON, 200, 500));
  while (general.PressOneButton(general.HOME_BUTTON, 200, 1000));
  while (general.PressOneButton(general.A_BUTTON, 200, 2000));
  return;
}

void PokemonExtra::diggerBrothers() {
  while (general.PressOneButton(general.A_BUTTON, 150, 150));
  return;
}

void PokemonExtra::fossilPokemon(String fossilName, const int fossilAmount) {
  for (int i = 0; i < 12; i++) {
    while (general.PressOneButton(general.B_BUTTON, 200, 100));  
  }
  
  for (int j = 0; j < fossilAmount; j++) {
    while (general.PressOneButton(general.A_BUTTON, 200, 1000));
    while (general.PressOneButton(general.A_BUTTON, 200, 1000));
    if ((fossilName == "Arctozolt") || (fossilName == "Dracozolt")) {
      while (general.PressOneButton(general.A_BUTTON, 200, 1000));
      if (fossilName == "Dracozolt") {
        while (general.PressOneButton(general.A_BUTTON, 200, 1000));
      }
      else {
        while (general.LeftJoystick(general.STICK_CENTER, general.DOWN, 100, 200));
        while (general.PressOneButton(general.A_BUTTON, 200, 1000));
      }
    }
    else {
      while (general.LeftJoystick(general.STICK_CENTER, general.DOWN, 100, 200));
      while (general.PressOneButton(general.A_BUTTON, 200, 1000));
      if(fossilName == "Dracovish") {
        while (general.PressOneButton(general.A_BUTTON, 200, 1000));
      }
      else {
        while (general.LeftJoystick(general.STICK_CENTER, general.DOWN, 100, 200));
        while (general.PressOneButton(general.A_BUTTON, 200, 1000));
      }
    }
    while (general.PressOneButton(general.A_BUTTON, 200, 1000));
    for (int k = 0; k < 12; k++) {
      while (general.PressOneButton(general.B_BUTTON, 200, 100));      
    }
  }
  for (int l = 0; l < 90000; l++) {
    while (general.PressOneButton(general.B_BUTTON, 200, 10000));      
  }
  return;
}

void PokemonExtra::stowOnSideBargain() {
  for (int i = 0; i < 6; i++) {
    while (general.PressOneButton(general.A_BUTTON, 150, 1200));   
  }
  for (int j = 0; j < 13; j++) {
    while (general.PressOneButton(general.B_BUTTON, 150, 150));
  }
  if(day < 25) {
    dayChange();
    day++; 
  }
  else if (month < 12) {
    monthChange();
    month++;
    day = 0;
  }
  else {
    yearChange();
    month = 0;
    day = 0;
  }
  return;
}

void PokemonExtra::berryFarm() {
  for (int i = 0; i < 6; i++) {
    while (general.PressOneButton(general.A_BUTTON, 150, 1000));   
  }
  for (int j = 0; j < 25; j++) {
    while (general.PressOneButton(general.B_BUTTON, 150, 150));
  }
  if(day < 25) {
    dayChange();
    day++; 
  }
  else if (month < 12) {
    monthChange();
    month++;
    day = 0;
  }
  else {
    yearChange();
    month = 0;
    day = 0;
  }
  return;
}

void PokemonExtra::lottoFarm() {
  for (int i = 0; i < 2; i++) {
    while (general.PressOneButton(general.B_BUTTON, 150, 150));
  }
  for (int j = 0; j < 2; j++) {
    while (general.PressOneButton(general.A_BUTTON, 150, 1000));   
  }   
  while (general.LeftJoystick(general.STICK_CENTER, general.DOWN, 100, 200));
  for (int k = 0; k < 8; k++) {
    while (general.PressOneButton(general.A_BUTTON, 150, 500)); 
  }
  for (int l = 0; l < 35; l++) {
    while (general.PressOneButton(general.B_BUTTON, 150, 150));
  }
  if(day < 25) {
    dayChange();
    day++; 
  }
  else if (month < 12) {
    monthChange();
    month++;
    day = 0;
  }
  else {
    yearChange();
    month = 0;
    day = 0;
  }
  return;
}

void PokemonExtra::evTrain(String firstEV, String secondEV) {

  int firstEVCounter = 0;
  int secondEVCounter = 0;
  int switchEV = 0;
  
  if(firstEV == "hp") {
    firstEVCounter = 5;
  }
  else if (firstEV == "attack"){
    firstEVCounter = 4;
  }
  else if (firstEV == "defense"){
    firstEVCounter = 3;
  }
  else if (firstEV == "spatk"){
    firstEVCounter = 2;
  }
  else if (firstEV == "spdef"){
    firstEVCounter = 1;
  }
  else {
    firstEVCounter = 0;
  }
  
  if(secondEV == "hp") {
    secondEVCounter = 5;
  }
  else if (secondEV == "attack"){
    secondEVCounter = 4;
  }
  else if (secondEV == "defense"){
    secondEVCounter = 3;
  }
  else if (secondEV == "spatk"){
    secondEVCounter = 2;
  }
  else if (secondEV == "spdef"){
    secondEVCounter = 1;
  }
  else {
    secondEVCounter = 0;
  }
  
  for (int i = 0; i < 5; i++) {
    while (general.PressOneButton(general.B_BUTTON, 150, 150));
  }
  while (general.LeftJoystick(general.STICK_CENTER, general.UP, 300, 200));
  for (int j = 0; j < 2; j++) {
    while (general.PressOneButton(general.A_BUTTON, 150, 1000));   
  }   
  while (general.LeftJoystick(general.STICK_CENTER, general.DOWN, 100, 200));
  while (general.LeftJoystick(general.STICK_CENTER, general.DOWN, 100, 200));
  while (general.PressOneButton(general.A_BUTTON, 150, 2500));
  while (general.PressOneButton(general.A_BUTTON, 150, 400));
  while (general.PressOneButton(general.A_BUTTON, 150, 400));
  for (int i = 0; i < 12; i++) {
    while (general.LeftJoystick(general.STICK_CENTER, general.DOWN, 2700, 300));
    if (i < 6) {
      switchEV = firstEVCounter;
    }
    else {
      switchEV = secondEVCounter;
    }
    for (int j = 0; j < switchEV; j++) {
      while (general.LeftJoystick(general.STICK_CENTER, general.UP, 100, 200));     
    }
    while (general.PressOneButton(general.A_BUTTON, 150, 800));
    while (general.PressOneButton(general.A_BUTTON, 150, 800));
    while (general.PressOneButton(general.A_BUTTON, 150, 800));
    while (general.PressOneButton(general.A_BUTTON, 150, 800));
    while (general.PressOneButton(general.Y_BUTTON, 150, 100));
    for (int k = 0; k < 5; k++) {
      while (general.PressOneButton(general.A_BUTTON, 150, 100));
      while (general.LeftJoystick(general.RIGHT, general.STICK_CENTER, 150, 100));  
    }
    while (general.LeftJoystick(general.LEFT, general.STICK_CENTER, 150, 100)); 
    while (general.LeftJoystick(general.STICK_CENTER, general.DOWN, 150, 100));
    for (int l = 0; l < 5; l++) {
      while (general.PressOneButton(general.A_BUTTON, 150, 100));
      while (general.LeftJoystick(general.LEFT, general.STICK_CENTER, 150, 100));  
    }
    while (general.PressOneButton(general.X_BUTTON, 2, 2500));
    while (general.PressOneButton(general.A_BUTTON, 150, 1200));
    while (general.LeftJoystick(general.STICK_CENTER, general.DOWN, 150, 100));
    while (general.PressOneButton(general.A_BUTTON, 150, 6000));
    while (general.PressOneButton(general.A_BUTTON, 150, 5000));
    dayChange();
    while (general.PressOneButton(general.A_BUTTON, 150, 300));
    while (general.PressOneButton(general.A_BUTTON, 150, 5000));
    for (int l = 0; l < 35; l++) {
      while (general.PressOneButton(general.B_BUTTON, 150, 300));      
    }
    for (int j = 0; j < 2; j++) {
      while (general.PressOneButton(general.A_BUTTON, 150, 1000));   
    }   
    while (general.LeftJoystick(general.STICK_CENTER, general.DOWN, 100, 200));
    while (general.LeftJoystick(general.STICK_CENTER, general.DOWN, 100, 200));
    while (general.PressOneButton(general.A_BUTTON, 150, 2500));
    while (general.PressOneButton(general.A_BUTTON, 150, 400));
    while (general.PressOneButton(general.A_BUTTON, 150, 400));
  }
  while (general.PressOneButton(general.X_BUTTON, 150, 900000));
  return;
}

void PokemonExtra::pokeJobs() {
  
  for (int i = 0; i < 5; i++) {
    while (general.PressOneButton(general.B_BUTTON, 150, 150));
  }
  while (general.LeftJoystick(general.STICK_CENTER, general.UP, 300, 200));
  for (int j = 0; j < 2; j++) {
    while (general.PressOneButton(general.A_BUTTON, 150, 1000));   
  }   
  while (general.LeftJoystick(general.STICK_CENTER, general.DOWN, 100, 200));
  while (general.LeftJoystick(general.STICK_CENTER, general.DOWN, 100, 200));
  while (general.PressOneButton(general.A_BUTTON, 150, 2500));
  while (general.PressOneButton(general.A_BUTTON, 150, 400));
  while (general.PressOneButton(general.A_BUTTON, 150, 400));
  while (1) {
    while (general.PressOneButton(general.A_BUTTON, 150, 800));
    while (general.PressOneButton(general.A_BUTTON, 150, 800));
    while (general.PressOneButton(general.A_BUTTON, 150, 800));
    while (general.PressOneButton(general.A_BUTTON, 150, 800));
    while (general.PressOneButton(general.Y_BUTTON, 150, 100));
    for (int k = 0; k < 4; k++) {
      while (general.PressOneButton(general.A_BUTTON, 150, 100));
      while (general.LeftJoystick(general.RIGHT, general.STICK_CENTER, 150, 100));  
    }
    while (general.LeftJoystick(general.LEFT, general.STICK_CENTER, 150, 100)); 
    while (general.LeftJoystick(general.STICK_CENTER, general.DOWN, 150, 100));
    for (int l = 0; l < 4; l++) {
      while (general.PressOneButton(general.A_BUTTON, 150, 100));
      while (general.LeftJoystick(general.LEFT, general.STICK_CENTER, 150, 100));  
    }
    while (general.PressOneButton(general.B_BUTTON, 150, 400));
    while (general.PressOneButton(general.A_BUTTON, 150, 1200));
    while (general.PressOneButton(general.X_BUTTON, 2, 2500));
    while (general.PressOneButton(general.A_BUTTON, 150, 1200));
    while (general.LeftJoystick(general.STICK_CENTER, general.DOWN, 150, 100));
    while (general.PressOneButton(general.A_BUTTON, 150, 6000));
    while (general.PressOneButton(general.A_BUTTON, 150, 5000));
    if(day < 25) {
      dayChange();
      day++; 
    }
    else if (month < 12) {
      monthChange();
      month++;
      day = 0;
    }
    else {
      yearChange();
      month = 0;
      day = 0;
    }
    while (general.PressOneButton(general.A_BUTTON, 150, 300));
    while (general.PressOneButton(general.A_BUTTON, 150, 5000));
    for (int l = 0; l < 35; l++) {
      while (general.PressOneButton(general.B_BUTTON, 150, 300));      
    }
    for (int j = 0; j < 2; j++) {
      while (general.PressOneButton(general.A_BUTTON, 150, 1000));   
    }   
    while (general.LeftJoystick(general.STICK_CENTER, general.DOWN, 100, 200));
    while (general.LeftJoystick(general.STICK_CENTER, general.DOWN, 100, 200));
    while (general.PressOneButton(general.A_BUTTON, 150, 2500));
    while (general.PressOneButton(general.A_BUTTON, 150, 400));
    while (general.PressOneButton(general.A_BUTTON, 150, 400));
  }
  return;
}

void PokemonExtra::championsCup() {
    while (general.LeftJoystick(general.STICK_CENTER, general.UP, 200, 150));
    while (general.LeftJoystick(general.STICK_CENTER, general.UP, 200, 150));
    while (general.LeftJoystick(general.STICK_CENTER, general.UP, 4000, 200));
    for (int i = 0; i < 4; i++) {
     while (general.LeftJoystick(general.STICK_CENTER, general.UP, 300, 200));      
    }
    while (general.PressOneButton(general.A_BUTTON, 150, 150));
    while (general.PressOneButton(general.A_BUTTON, 150, 150));
    while (general.PressOneButton(general.B_BUTTON, 150, 150));
    while (general.PressOneButton(general.B_BUTTON, 150, 150));
    while (general.PressOneButton(general.B_BUTTON, 150, 150));
    for (int j = 0; j < 100; j++) {
      while (general.PressOneButton(general.A_BUTTON, 150, 150));   
      while (general.PressOneButton(general.A_BUTTON, 150, 150));          
    }
}

void PokemonExtra::monthChange() {
  toDateTimeSettings();
  while (general.LeftJoystick(general.STICK_CENTER, general.UP, 200, 100));
  while (general.LeftJoystick(general.RIGHT, general.STICK_CENTER, 200, 400));
  for (int i = 0; i < 25; i++) {
    while (general.LeftJoystick(general.STICK_CENTER, general.DOWN, 200, 100)); 
  }
  while (general.LeftJoystick(general.RIGHT, general.STICK_CENTER, 1000, 200));
  while (general.PressOneButton(general.A_BUTTON, 200, 500));
  while (general.PressOneButton(general.HOME_BUTTON, 200, 1000));
  while (general.PressOneButton(general.A_BUTTON, 200, 2000));
  return;
}

void PokemonExtra::toDateTimeSettings() {
  while (general.PressOneButton(general.HOME_BUTTON, 200, 1000));
  while (general.LeftJoystick(general.STICK_CENTER, general.DOWN, 200, 200));
  for (int i = 0; i < 4; i++) {
    while (general.LeftJoystick(general.RIGHT, general.STICK_CENTER, 200, 100));  
  }
  while (general.PressOneButton(general.A_BUTTON, 200, 500));
  while (general.LeftJoystick(general.STICK_CENTER, general.DOWN, 2000, 100));
  while (general.PressOneButton(general.A_BUTTON, 200, 500));
  for (int i = 0; i < 2; i++) {
    while (general.LeftJoystick(general.STICK_CENTER, general.DOWN, 400, 100));  
  }
  while (general.PressOneButton(general.A_BUTTON, 200, 300));
  while (general.LeftJoystick(general.STICK_CENTER, general.DOWN, 1000, 100));
  while (general.PressOneButton(general.A_BUTTON, 200, 400));
  return;
}

void PokemonExtra::pokemonRelease() {
  while (general.PressOneButton(general.A_BUTTON, 100, 250) == true);
  while (general.LeftJoystick(general.STICK_CENTER, general.UP, 100, 200) == true);
  while (general.LeftJoystick(general.STICK_CENTER, general.UP, 100, 200) == true);
  while (general.PressOneButton(general.A_BUTTON, 100, 1200) == true);
  while (general.LeftJoystick(general.STICK_CENTER, general.UP, 100, 150) == true);
  while (general.PressOneButton(general.A_BUTTON, 100, 600) == true);
  while (general.PressOneButton(general.A_BUTTON, 100, 650) == true);
  while (general.PressOneButton(general.A_BUTTON, 100, 600) == true);
  return;
}

void PokemonExtra::releaseSetup() {
  while (general.PressOneButton(general.A_BUTTON, 100, 150) == true);
  while (general.LeftJoystick(general.STICK_CENTER, general.UP, 100, 100) == true);
  while (general.LeftJoystick(general.STICK_CENTER, general.UP, 100, 100) == true);
  while (general.PressOneButton(general.A_BUTTON, 100, 300) == true);
  while (general.LeftJoystick(general.STICK_CENTER, general.UP, 100, 100) == true);
  while (general.PressOneButton(general.A_BUTTON, 100, 300) == true);
  while (general.PressOneButton(general.A_BUTTON, 100, 1000) == true);
  while (general.PressOneButton(general.B_BUTTON, 100, 300) == true);
  while (general.LeftJoystick(general.STICK_CENTER, general.DOWN, 100, 100) == true);
  return;
}

void PokemonExtra::yearChange () {
  toDateTimeSettings();
  while (general.LeftJoystick(general.STICK_CENTER, general.UP, 200, 100));
  while (general.LeftJoystick(general.RIGHT, general.STICK_CENTER, 200, 400));
  for (int i = 0; i < 25; i++) {
    while (general.LeftJoystick(general.STICK_CENTER, general.DOWN, 200, 100)); 
  }
  while (general.LeftJoystick(general.RIGHT, general.STICK_CENTER, 200, 400));
  while (general.LeftJoystick(general.STICK_CENTER, general.UP, 200, 100));
  while (general.LeftJoystick(general.RIGHT, general.STICK_CENTER, 1000, 200));
  while (general.PressOneButton(general.A_BUTTON, 200, 500));
  while (general.PressOneButton(general.HOME_BUTTON, 200, 1000));
  while (general.PressOneButton(general.A_BUTTON, 200, 2000));
  return;
}
