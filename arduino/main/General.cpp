#include "General.h"
#include "Descriptors.h"
#include "Joystick.h"
#include <EEPROM.h>
#include "PokemonEggHatching.h"
#include "PokemonExtra.h"
#include "ACNH.h"

unsigned long previousMillis = 0; 
unsigned long currentMillis = millis();

void General::handleUSB() {
  HID_Task();
  USB_USBTask();
}

bool General::handshake() {
  String incomingMessage = "waiting";
  String outgoingMessage = "";
  int stepNumber = -1;
  int integerStoreIndex = 4;
  PokemonExtra pokemonExtra;
  PokemonEggHatching pokemonEggHatching;
  ACNH acnh;
  while (incomingMessage == "waiting") {
      currentMillis = millis();
      while(Serial1.available()) {
          incomingMessage = Serial1.readString();
      }
  }
  // EEPROM flash
  if (incomingMessage == "FLASH") {
    while (incomingMessage != "COMPLETE") {
      currentMillis = millis();
      if (((currentMillis - previousMillis) > 700) && (incomingMessage != "FLASH")) {
          if (stepNumber != -1) {
              outgoingMessage = incomingMessage.substring(0,3) + " Complete";
              Serial1.println(outgoingMessage);
          }
          previousMillis = millis();
      }
      
      else {
        while (Serial1.available()) {
          currentMillis = millis();
          incomingMessage = Serial1.readString();
          if((incomingMessage != "COMPLETE") && (incomingMessage != "FLASH")) {
             stepNumber = incomingMessage.substring(0, 3).toInt();

             EEPROM.write(3*stepNumber, getChar(incomingMessage));
             EEPROM.write(3*stepNumber+1, highByte(getInteger(incomingMessage)));
             EEPROM.write(3*stepNumber+2, lowByte(getInteger(incomingMessage)));
             EEPROM.write(1, highByte(stepNumber));
             EEPROM.write(2, lowByte(stepNumber));
             
             //Serial1.println(3*stepNumber);
             //Serial1.println(getInteger(incomingMessage));
             //Serial1.println(word(EEPROM.read(3*16+1),EEPROM.read(3*16+2)));
             //Serial1.println(word(EEPROM.read(1),EEPROM.read(2)));
             
             //Serial1.println(String(EEPROM.read(3))+String(EEPROM.read(6))+String(EEPROM.read(9))+String(EEPROM.read(12))+String(EEPROM.read(15)));
             /*
             if (tempIter == 0) {
               Serial1.println(getString(EEPROM.read(3)));
               tempIter++;
             }
             */
          }
              else {
                if ((currentMillis-previousMillis) > 700) {
                  Serial1.println("READYFOREXCHA");
              }
            }
        }

      }
    }
    EEPROM.write(1, highByte(stepNumber));
    EEPROM.write(2, lowByte(stepNumber));
    incomingMessage = "waiting";
    return;
  }
  else if (incomingMessage == "CLEAR") {
    while (incomingMessage == "CLEAR") {
      currentMillis = millis();
      if ((currentMillis-previousMillis) > 700){
        Serial1.println("READYFOREXCHA");
        previousMillis = millis();
      }
      while(Serial1.available()) {
        incomingMessage = Serial1.readString();
      }
    }
    for (int i = 0 ; i < EEPROM.length() ; i++) {
        EEPROM.write(i, 0);
          
    }
    incomingMessage = "waiting";
    currentMillis = millis();
    while (incomingMessage == "waiting") {
      if ((currentMillis-previousMillis) > 700){
        Serial1.println("COMPLETEEXCHA");
        previousMillis = millis();
      }
      
      while(Serial1.available()) {
        incomingMessage = Serial1.readString();
      }
    }
    
    //Serial1.println("CLEARINGMSG");
    incomingMessage = "waiting";
    return;
  }
  
  else if (incomingMessage == "EXECUTE") {
    while (1) {
      executeMemScript();
    }
  }


  else if (incomingMessage == "STATUS") {
    char statusMsg[12];
    int commandNumber = 0;
    while (incomingMessage == "STATUS") {
      currentMillis = millis();
      if ((currentMillis-previousMillis) > 700){
        Serial1.println("STATUSEXCHANG");
        previousMillis = millis();
      }
      while(Serial1.available()) {
        incomingMessage = Serial1.readString();
      }
    }

    // INSERT STATUS CODE
    // NOT WORKING
    //strcat(statusMsg, EEPROM.read(1));
    //strcat(statusMsg, EEPROM.read(2));
    
    for (int i = 2; i < EEPROM.length(); i++) {
        if (((i%3)== 0) && (EEPROM.read(i) != 0)) {
          commandNumber++;
        }
    }

    int totalCommandNumber = word(EEPROM.read(1), EEPROM.read(2));
    //char testWordChar = testWord;
    //strcat(statusMsg, highByte(commandNumber));
    //strcat(statusMsg, lowByte(commandNumber));
    strcat(statusMsg, totalCommandNumber);
    strcat(statusMsg, "XXXXXXX");
    

    

    incomingMessage = "waiting";
    while (incomingMessage != "COMPLETEMSG!") {
      currentMillis = millis();
      if ((currentMillis-previousMillis) > 700){
        //Serial1.println(statusMsg);
        //Serial1.println(String(totalCommandNumber));
        
        if (totalCommandNumber < 10) { Serial1.println("00" + String(totalCommandNumber) + "XXXXXXXXX"); }
        else if (totalCommandNumber < 100) { Serial1.println("0" + String(totalCommandNumber) + "XXXXXXXXX"); }
        else { Serial1.println(String(totalCommandNumber) + "XXXXXXXXX"); }
        
        previousMillis = millis();
      }
      
      while(Serial1.available()) {
        incomingMessage = Serial1.readString();
      }
    }
    incomingMessage = "waiting";
    return;
  }

  else if (incomingMessage == "wattFarimng") {
    while(1) {
      pokemonExtra.wattFarming();
    }
  }

  else if (incomingMessage == "boxRelease") {
    while (1) {
      pokemonEggHatching.boxHatch(5);
    }
  }

  else if (incomingMessage == "diggerBrothers") {
    while (1) {
      pokemonExtra.diggerBrothers();
    }
  }

  else if ((incomingMessage == "Arctovish") || (incomingMessage == "Arctozolt") || (incomingMessage == "Dracovish") || (incomingMessage == "Dracozolt")) {
    while (1) {
      pokemonExtra.fossilPokemon(incomingMessage, 100);
    }
  }

  else if (incomingMessage == "berryFarimng") {
    while(1) {
      pokemonExtra.berryFarm();
    }
  }

  else if (incomingMessage == "lottoFarm") {
    while(1) {
      pokemonExtra.lottoFarm();
    }
  }

  else if (incomingMessage.indexOf("&") != -1) {
    while (1) {
      // Untested
      pokemonExtra.evTrain(incomingMessage.substring(0, incomingMessage.indexOf("&")-1), incomingMessage.substring(incomingMessage.indexOf("&")+1, incomingMessage.length()));
    }
  }

  else if (incomingMessage == "pokeJob") {
    while (1) {
      pokemonExtra.pokeJobs();
    }
  }
  
  else if (incomingMessage == "championsCup") {
    while (1) {
      pokemonExtra.championsCup();
    }
  }
  
  else if (incomingMessage == "stowOnSide") {
    while (1) {
      pokemonExtra.stowOnSideBargain();
    }
  }

  else if (incomingMessage.substring("Steps") != -1) {
    while (1) {
      pokemonEggHatching.eggHatch(incomingMessage.substring(0, incomingMessage.indexOf(" ") -1).toInt());
    }
  }

  else if (incomingMessage == "starFarming") {
    while (1) {
      acnh.starFarm();
    }
  }

  else if (incomingMessage == "diyRepetition") {
    while (1) {
      acnh.starFarm();
    }
  }
}

void General::executeMemScript() {
   int actionCount = word(EEPROM.read(1),EEPROM.read(2));
   char buttonPressed;
   int intDuration;
   unsigned long buttonDuration;
   //char buttonChars[] = "ABXYRSLMCHPON";
   char buttonChars[13] = { 'A','B','X','Y','R','S','L','M','C','H','P','O','N' };
   char rightJoystickChars[4] = { 'a','b','c','d' };
   char leftJoystickChars[4] = { 'e','f','g','h' };
   String buttonString = "ABXYRSLMCHPON";
   String rightJoystickString = "abcd";
   String leftJoystickString = "efgh";


   for (int i = 1; i < (actionCount+1); i++) {
      buttonPressed = EEPROM.read(3*i);
      intDuration = word(EEPROM.read(3*i+1),EEPROM.read(3*i+2));
      buttonDuration = intDuration;
      if (buttonString.indexOf(String(buttonPressed).charAt(0)) != -1) {
        if (String(buttonPressed).charAt(0) == 'N') { 
          while (Nothing(buttonDuration) == true);
          Serial1.println(String(i) + " " + String(buttonPressed) + " " + String(getButton(buttonPressed)) + " XXXXXXXXXX");
        }
        else {
          while (PressOneButton(getButton(buttonPressed), buttonDuration, 1) == true);
          Serial1.println(String(i) + " " + String(buttonPressed) + " " + String(getButton(buttonPressed)) + " XXXXXXXXXX");
        }
      }
      else if (rightJoystickString.indexOf(String(buttonPressed).charAt(0)) != -1) {
        if ((String(buttonPressed).charAt(0) == 'a') || (String(buttonPressed).charAt(0) == 'd')) {
          while (RightJoystick(STICK_CENTER, getButton(buttonPressed), buttonDuration, 1) == true);        
        }
        else {
          while (RightJoystick(getButton(buttonPressed), STICK_CENTER, buttonDuration, 1) == true);
        }
      }
      else if (leftJoystickString.indexOf(String(buttonPressed).charAt(0)) != -1) {
        if ((String(buttonPressed).charAt(0) == 'e') || (String(buttonPressed).charAt(0) == 'h')) {
          while (LeftJoystick(STICK_CENTER, getButton(buttonPressed), buttonDuration, 1) == true);       
        }
        else {
          while (LeftJoystick(getButton(buttonPressed), STICK_CENTER, buttonDuration, 1) == true);
        }
      }  
      else {
        Serial1.println(String(i) + " " + String(buttonPressed) + " " + "YYYYYYYYYYYY");
      }
   }
}

int General::getButton(char selectButton) {
  //Serial1.println(String(selectButton) + " " + String(String(selectButton).charAt(0)) + "YYYYYYYYYY");
  if (String(selectButton).charAt(0) == 'A') return A_BUTTON;
  else if (String(selectButton).charAt(0) == 'B') return B_BUTTON;
  else if (String(selectButton).charAt(0) == 'X')  return X_BUTTON;
  else if (String(selectButton).charAt(0) == 'Y')  return Y_BUTTON;
  else if (String(selectButton).charAt(0) == 'R')  return RB_BUTTON;
  else if (String(selectButton).charAt(0) == 'S')  return ZR_BUTTON;
  else if (String(selectButton).charAt(0) == 'L')  return LB_BUTTON;
  else if (String(selectButton).charAt(0) == 'M')  return ZL_BUTTON;
  else if (String(selectButton).charAt(0) == 'C')  return CAPTURE_BUTTON;
  else if (String(selectButton).charAt(0) == 'H')  return HOME_BUTTON;
  else if (String(selectButton).charAt(0) == 'P')  return PLUS_BUTTON;
  else if (String(selectButton).charAt(0) == 'O')  return MINUS_BUTTON;
  else if (String(selectButton).charAt(0) == 'a')  return UP;
  else if (String(selectButton).charAt(0) == 'b')  return LEFT;
  else if (String(selectButton).charAt(0) == 'c')  return DOWN;
  else if (String(selectButton).charAt(0) == 'd')  return RIGHT;
  else if (String(selectButton).charAt(0) == 'e')  return UP;
  else if (String(selectButton).charAt(0) == 'f')  return LEFT;
  else if (String(selectButton).charAt(0) == 'g')  return DOWN;
  else if (String(selectButton).charAt(0) == 'h')  return RIGHT;
  else return 'Z';
  //up left right down

}




int General::getInteger(String incomingMessage) {
  return incomingMessage.substring(incomingMessage.indexOf("(")+1, incomingMessage.indexOf(")")).toInt();
}

char General::getChar(String incomingMessage) {
  String inputValue = incomingMessage.substring(incomingMessage.indexOf(" ")+1, incomingMessage.indexOf("("));

  if (inputValue == "aButton") { return 'A'; }
  else if (inputValue == "bButton") { return 'B';}
  else if (inputValue == "xButton") { return 'X';}
  else if (inputValue == "yButton") { return 'Y';}
  else if (inputValue == "rButton") { return 'R';}
  else if (inputValue == "zrButton") { return 'S';}
  else if (inputValue == "lButton") { return 'L'; }
  else if (inputValue == "zlButton") { return 'M'; }
  else if (inputValue == "captureButton") { return 'C'; }
  else if (inputValue == "homeButton") { return 'H'; }
  else if (inputValue == "plusButton") { return 'P'; }
  else if (inputValue == "minusButton") { return 'O'; }
  else if (inputValue == "nothing") { return 'N'; }
  else if (inputValue == "rjsUp") { return 'a';}
  else if (inputValue == "rjsLeft") { return 'b';}
  else if (inputValue == "rjsRight") { return 'c'; }
  else if (inputValue == "rjsDown") { return 'd'; }
  else if (inputValue == "ljsUp") { return 'e'; }
  else if (inputValue == "ljsLeft") { return 'f';}
  else if (inputValue == "ljsRight") { return 'g'; }
  else if (inputValue == "ljsDown") { return 'h'; }
  else {return 'Z'; }
}

String General::getString(char inputChar) {
  if (strcmp(inputChar, 'A') == 0) {
    return "a";
  }
  else if (strcmp(inputChar, 'B') == 0) {
    return "b";
  }
  else if (strcmp(inputChar, 'X') == 0) {
    return "x";
  }
  else if (strcmp(inputChar, 'Y') == 0) {
    return "y";
  }
  else if (strcmp(inputChar, 'a') == 0) {
    return "u";
  }
  else if (strcmp(inputChar, 'b') == 0) {
    return "l";
  }
  else if (strcmp(inputChar, 'c') == 0) {
    return "r";
  }
  else if (strcmp(inputChar, 'd') == 0) {
    return "d";
  }
  else {
    return "NOCHARXXXXXX";
  }
}

bool General::PressOneButton(int button, unsigned long pressDuration, unsigned long waitDuration) {
  currentMillis = millis();
  if ((currentMillis - previousMillis) < pressDuration) {
    ReportData.Button |= button;  
    ReportData.LX = STICK_CENTER;
    ReportData.LY = STICK_CENTER; 
    ReportData.RX = STICK_CENTER;
    ReportData.RY = STICK_CENTER;
    
  }
  else if ((currentMillis - previousMillis) < (pressDuration + waitDuration)) {
    ReportData.LX = STICK_CENTER;
    ReportData.LY = STICK_CENTER;
    ReportData.RX = STICK_CENTER;
    ReportData.RY = STICK_CENTER;
  }
  else {
    previousMillis = millis();
    ReportData.LX = STICK_CENTER;
    ReportData.LY = STICK_CENTER;
    ReportData.RX = STICK_CENTER;
    ReportData.RY = STICK_CENTER;
    return false;
  }
  handleUSB();
  return true;
}

bool General::PressTwoButtons(int buttonOne, int buttonTwo, unsigned long pressDuration, unsigned long waitDuration) {
  currentMillis = millis();
  if ((currentMillis - previousMillis) < pressDuration) {
    ReportData.Button |= buttonOne;
    ReportData.Button |= buttonTwo;  
    ReportData.LX = STICK_CENTER;
    ReportData.LY = STICK_CENTER;
    ReportData.RX = STICK_CENTER;
    ReportData.RY = STICK_CENTER;
  }
  else if ((currentMillis - previousMillis) < (pressDuration + waitDuration)) {
    ReportData.LX = STICK_CENTER;
    ReportData.LY = STICK_CENTER;
    ReportData.RX = STICK_CENTER;
    ReportData.RY = STICK_CENTER;
  }
  else {
    previousMillis = millis();
    ReportData.LX = STICK_CENTER;
    ReportData.LY = STICK_CENTER;
    ReportData.RX = STICK_CENTER;
    ReportData.RY = STICK_CENTER;
    return false;
  }
  handleUSB();
  return true;
}

bool General::LeftJoystick(int joystickXVal, int joystickYVal, unsigned long pressDuration, unsigned long waitDuration) {
  currentMillis = millis();
  if ((currentMillis - previousMillis) < pressDuration) {  
    ReportData.LX = joystickXVal;
    ReportData.LY = joystickYVal; 
    ReportData.RX = STICK_CENTER;
    ReportData.RY = STICK_CENTER;
  }
  else if ((currentMillis - previousMillis) < (pressDuration + waitDuration)) {
    ReportData.LX = STICK_CENTER;
    ReportData.LY = STICK_CENTER;
    ReportData.RX = STICK_CENTER;
    ReportData.RY = STICK_CENTER;
  }
  else {
    previousMillis = millis();
    ReportData.LX = STICK_CENTER;
    ReportData.LY = STICK_CENTER;
    ReportData.RX = STICK_CENTER;
    ReportData.RY = STICK_CENTER;
    return false;
  }
  handleUSB();
  return true;
}

bool General::LeftJoystickOneButton(int joystickXVal, int joystickYVal, int button, unsigned long pressDuration, unsigned long waitDuration) {
  currentMillis = millis();
  if ((currentMillis - previousMillis) < pressDuration) {  
    ReportData.Button |= button;
    ReportData.LX = joystickXVal;
    ReportData.LY = joystickYVal;
    ReportData.RX = STICK_CENTER;
    ReportData.RY = STICK_CENTER;
  }
  else if ((currentMillis - previousMillis) < (pressDuration + waitDuration)) {
    ReportData.LX = STICK_CENTER;
    ReportData.LY = STICK_CENTER;
    ReportData.RX = STICK_CENTER;
    ReportData.RY = STICK_CENTER;
  }
  else {
    previousMillis = millis();
    ReportData.LX = STICK_CENTER;
    ReportData.LY = STICK_CENTER;
    ReportData.RX = STICK_CENTER;
    ReportData.RY = STICK_CENTER;
    return false;
  }
  handleUSB();
  return true;
}

bool General::LeftJoystickTwoButtons(int joystickXVal, int joystickYVal, int buttonOne, int buttonTwo, unsigned long pressDuration, unsigned long waitDuration) {
  currentMillis = millis();
  if ((currentMillis - previousMillis) < pressDuration) {  
    ReportData.Button |= buttonOne;
    ReportData.Button |= buttonTwo;
    ReportData.LX = joystickXVal;
    ReportData.LY = joystickYVal; 
    ReportData.RX = STICK_CENTER;
    ReportData.RY = STICK_CENTER;
  }
  else if ((currentMillis - previousMillis) < (pressDuration + waitDuration)) {
    ReportData.LX = STICK_CENTER;
    ReportData.LY = STICK_CENTER;
    ReportData.RX = STICK_CENTER;
    ReportData.RY = STICK_CENTER;
  }
  else {
    previousMillis = millis();
    ReportData.LX = STICK_CENTER;
    ReportData.LY = STICK_CENTER;
    ReportData.RX = STICK_CENTER;
    ReportData.RY = STICK_CENTER;
    return false;
  }
  handleUSB();
  return true;
}

bool General::RightJoystick(int joystickXVal, int joystickYVal, unsigned long pressDuration, unsigned long waitDuration) {
  currentMillis = millis();
  if ((currentMillis - previousMillis) < pressDuration) {  
    ReportData.RX = joystickXVal;
    ReportData.RY = joystickYVal; 
    ReportData.LX = STICK_CENTER;
    ReportData.LY = STICK_CENTER;
  }
  else if ((currentMillis - previousMillis) < (pressDuration + waitDuration)) {
    ReportData.RX = STICK_CENTER;
    ReportData.RY = STICK_CENTER;
    ReportData.LX = STICK_CENTER;
    ReportData.LY = STICK_CENTER;
  }
  else {
    previousMillis = millis();
    ReportData.RX = STICK_CENTER;
    ReportData.RY = STICK_CENTER;
    ReportData.LX = STICK_CENTER;
    ReportData.LY = STICK_CENTER;
    return false;
  }
  handleUSB();
  return true;
}

bool General::RightJoystickOneButton(int joystickXVal, int joystickYVal, int button, unsigned long pressDuration, unsigned long waitDuration) {
  currentMillis = millis();
  if ((currentMillis - previousMillis) < pressDuration) {  
    ReportData.Button |= button;
    ReportData.RX = joystickXVal;
    ReportData.RY = joystickYVal;
    ReportData.LX = STICK_CENTER;
    ReportData.LY = STICK_CENTER; 
  }
  else if ((currentMillis - previousMillis) < (pressDuration + waitDuration)) {
    ReportData.RX = STICK_CENTER;
    ReportData.RY = STICK_CENTER;
    ReportData.LX = STICK_CENTER;
    ReportData.LY = STICK_CENTER;
  }
  else {
    previousMillis = millis();
    ReportData.RX = STICK_CENTER;
    ReportData.RY = STICK_CENTER;
    ReportData.LX = STICK_CENTER;
    ReportData.LY = STICK_CENTER;
    return false;
  }
  handleUSB();
  return true;
}

bool General::RightJoystickTwoButtons(int joystickXVal, int joystickYVal, int buttonOne, int buttonTwo, unsigned long pressDuration, unsigned long waitDuration) {
  currentMillis = millis();
  if ((currentMillis - previousMillis) < pressDuration) {  
    ReportData.Button |= buttonOne;
    ReportData.Button |= buttonTwo;
    ReportData.RX = joystickXVal;
    ReportData.RY = joystickYVal;
    ReportData.LX = STICK_CENTER;
    ReportData.LY = STICK_CENTER;
  }
  else if ((currentMillis - previousMillis) < (pressDuration + waitDuration)) {
    ReportData.RX = STICK_CENTER;
    ReportData.RY = STICK_CENTER;
    ReportData.LX = STICK_CENTER;
    ReportData.LY = STICK_CENTER;
  }
  else {
    previousMillis = millis();
    ReportData.RX = STICK_CENTER;
    ReportData.RY = STICK_CENTER;
    ReportData.LX = STICK_CENTER;
    ReportData.LY = STICK_CENTER;
    return false;
  }
  handleUSB();
  return true;
}

bool General::Nothing(unsigned long waitDuration) {
    currentMillis = millis();
    if (currentMillis - previousMillis < waitDuration) {
      currentMillis = millis();
      ReportData.LX = STICK_CENTER;
      ReportData.LY = STICK_CENTER; 
      ReportData.RX = STICK_CENTER;
      ReportData.RY = STICK_CENTER; 
    }
    else {
      previousMillis = millis();
      return false;
    }
    handleUSB();
    return true;
}




