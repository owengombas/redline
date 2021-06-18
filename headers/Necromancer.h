#pragma once
#include <iostream>

#include "IObject.h"
#include "Potion.h"
#include "Wizard.h"

using namespace std;

namespace HE_Arc::RPG {
class Necromancer : public Wizard {
public:
  Necromancer(int strength = 10, int agility = 5, int intelligence = 1,
              int hp = 20, string name = "unknown necromancer", int mana = 10,
              IObject *pObject = new Potion())
      : Wizard(strength, agility, intelligence, hp, name, mana, pObject) {}
  void riseUndeads();

  const string getType() const override { return "necromancer"; }
};
} // namespace HE_Arc::RPG
