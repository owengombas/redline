#pragma once
#include <iostream>

#include "Monster.h"

using namespace std;

namespace HE_Arc::RPG {
class Dragon : public Monster {
public:
  Dragon(int strength = 250, int agility = 25, int intelligence = 20,
         int hp = 1000, string name = "dragon")
      : Monster(strength, agility, intelligence, hp, name) {}

  const string getType() const override { return "dragon"; }
};
} // namespace HE_Arc::RPG
