#ifndef _ACNH_H_
#define _ACNH_H_

#include "LUFAConfig.h"
#include <LUFA.h>
#include "Joystick.h"
#include "Descriptors.h"
#include "General.h"

using namespace std;

class ACNH {
  public:
  
  /// Farms starts by repeatedly moving gaze up and pressing A
  void starFarm();

  /// Completes DIY by repeatedly pressing the A button
  void diySpam();

  /// Shakes trees for fruit in a single spaced fenced box
  /// Must start at top left
  /// @param columnNumber number of trees in vertical column
  /// @param rowNumber number of rows of trees in horizontal row
  void fruitFarm(int columnNumber, int rowNumber);
  
  private:

  General general;
};

#endif
