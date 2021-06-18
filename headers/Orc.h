#pragma once
#include <iostream>

#include "Monster.h"

using namespace std;

namespace HE_Arc::RPG {
class Orc : public Monster {
public:
  Orc(int strength = 100, int agility = 75, int intelligence = 10,
      double hp = 200, string name = "orc")
      : Monster(strength, agility, intelligence, hp, name) {}

  string getType() const override { return "orc"; }
};
} // namespace HE_Arc::RPG
