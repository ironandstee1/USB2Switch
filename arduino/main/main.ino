#include "LUFAConfig.h"
#include <LUFA.h>
#include "Joystick.h"
#include "General.h"
#include "PokemonEggHatching.h"
#include "PokemonExtra.h"
#include "SimpleScripting.h"

String incoming = "";

PokemonEggHatching pokemonEggHatching; // Creates an instance of pokemon egg hatching class
PokemonExtra pokemonExtra; // Creates an instance of pokemon extra class

void setup() {
  SetupHardware(); // Needed for LUFA
  GlobalInterruptEnable(); // Needed for LUFA
  Serial1.begin(9600);
  Serial1.println("lol");
  pinMode(2, OUTPUT);
}

void loop() {
  //pokemonEggHatching.eggHatch(2560);
  //pokemonEggHatching.eggHatch(3840);
  //pokemonEggHatching.eggHatch(5120);
  //pokemonEggHatching.eggHatch(6400);
  //pokemonEggHatching.eggHatch(7680);
  //pokemonEggHatching.eggHatch(8960);
  //pokemonEggHatching.eggHatch(10240);
  //pokemonEggHatching.boxHatch(1);
  slTesting();
  //pokemonExtra.boxRelease(5);
    
  //pokemonExtra.boxRelease(5);
  //pokemonExtra.diggerBrothers();
  //pokemonExtra.wattFarming();
  //pokemonExtra.fossilPokemon("arctovish", 20);
  //pokemonExtra.stowOnSideBargain();
  //pokemonExtra.lottoFarm();
  //pokemonExtra.evTrain("hp", "spatk");
  //pokemonExtra.pokeJobs();
  //pokemonExtra.championsCup();

  //simpleScript();
}

// For writing simple scripts, use this function and call to it in the main. 
void simpleScript() {
  using namespace simple;
  
  Left(1000);
  Nothing(1000);
  Right(1000);
  Nothing(1000);
  Up(1000);
  Nothing(1000);
  X(1000);
  Nothing(1000);
  Y(1000);
  Nothing(1000);
  A(1000);
  Nothing(1000);
  B(1000);
  Nothing(1000);
}

void slTesting() {
  General general;
  general.handshake();


}




