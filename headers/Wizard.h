#pragma once
#include <iostream>

#include "Hero.h"

using namespace std;

namespace HE_Arc::RPG {
class Wizard : Hero {
 public:
  Wizard(int strength, int agility, int intelligence, double hp, string name,
         int mana);
  void castSpell();

 protected:
  int mana;
  void interact(const Hero &hero);
};
}  // namespace HE_Arc::RPG
