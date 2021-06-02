#pragma once
#include <iostream>

#include "Hero.h"
#include "IObject.h"
#include "Sword.h"

using namespace std;

namespace HE_Arc::RPG {
class Warrior : public Hero {
public:
  Warrior(int strength = 10, int agility = 5, int intelligence = 1,
          double hp = 20, string name = "unknown warrior",
          IObject *pObject = new Sword())
      : Hero(strength, agility, intelligence, hp, name, pObject) {}

  void interact(const Hero &hero) override;
};
} // namespace HE_Arc::RPG
