#pragma once
#include <iostream>

#include "Hero.h"

using namespace std;

namespace HE_Arc::RPG {
class Warrior : Hero {
 public:
  Warrior(int strength, int agility, int intelligence, double hp, string name);

  void interact(const Hero &hero) override;
};
}  // namespace HE_Arc::RPG
