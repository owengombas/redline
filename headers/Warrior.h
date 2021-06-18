#pragma once
#include "Hero.h"
#include "IObject.h"
#include "Sword.h"
#include <string>

using namespace std;

namespace HE_Arc::RPG {
class Warrior : public Hero {
public:
  Warrior(int strength = 10, int agility = 5, int intelligence = 1, int hp = 20,
          string name = "unknown warrior", IObject *pObject = new Sword())
      : Hero(strength, agility, intelligence, hp, name, pObject) {}

  void interact(const Hero &hero) override;

  const string getType() const override { return "warrior"; }
};
} // namespace HE_Arc::RPG
