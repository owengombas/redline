#pragma once
#include <iostream>

#include "Wizard.h"

using namespace std;

namespace HE_Arc::RPG
{
  class Necromancer : public Wizard
  {
  public:
    Necromancer(int strength, int agility, int intelligence, double hp, string name,
                Sword *sword, int mana);
    void riseUndeads();
  };
} // namespace HE_Arc::RPG
