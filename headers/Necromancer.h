#pragma once
#include <iostream>

#include "Wizard.h"

using namespace std;

namespace HE_Arc::RPG {
class Necromancer : Wizard {
  Necromancer(int, int, int, double, string, int);
  void riseUndeads();
};
}  // namespace HE_Arc::RPG
