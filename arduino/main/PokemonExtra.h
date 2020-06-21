#ifndef _PokemonExtra_H_
#define _PokemonExtra_H_

#include "LUFAConfig.h"
#include <LUFA.h>
#include "Joystick.h"
#include "Descriptors.h"
#include "General.h"

using namespace std;

class PokemonExtra {
  public:

  PokemonExtra();

  ///Farms watts from a fountain using the date time exploit. 
  void wattFarming();

  /// Releases a set number of boxes of pokemon before stalling indefinitely 
  void boxRelease(const int boxes);

  /// Spams A to get rewards from the digger brothers
  void diggerBrothers();

  /// Gets a set number of fossil pokemon from the fossil lady on route six. 
  /// possible names: arctozolt, arctovish, dracovish, dracozolt 
  /// @param fossilName name of fossil pokemon to get
  /// @param fossilAmount number of fossils you want 
  void fossilPokemon(String fossilName, const int fossilAmount);
  
  /// Farms the stow on side bargain repeatedly using the date/time exploit. 
  void stowOnSideBargain();

  /// Farms a berry tree repeatedly using the date/time exploit. 
  void berryFarm(); 

  /// Farms the lotto repeatedly using the date/time exploit
  void lottoFarm();

  /// Uses the data/time exploit and poke jobs system to farm max EVs for two values.
  /// Possible values: hp, attack, defense, spatk, spdef, speed
  /// @param firstEV: first EV to farm
  /// @param secondEV: secondEV to farm   
  void evTrain(String firstEV, String secondEV);
  
  /// Uses the data/time exploit to farm exp and items
  void pokeJobs();

  /// Repeatedly competes in the champions cup to farm rare balls
  void championsCup();

  private:

  /// Changes the day forward once
  void dayChange(); 

  /// Changes the month forward and subtracts 25 days
  void monthChange(); 

  /// Release an individual pokemon
  void pokemonRelease(); 
  
  /// Sets up release to account for controller plug in set up
  void releaseSetup(); 
  
  /// Opens up the date/time settings
  void toDateTimeSettings(); 

  /// Changes the year forward
  void yearChange(); 

  General general;

  int day = 0;
  int month = 0;
  int year = 0;
};

#endif
