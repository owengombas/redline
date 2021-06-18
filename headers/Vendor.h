#pragma once
#include "Hero.h"
#include "Sword.h"
#include <iostream>
#include <vector>

using namespace std;
namespace HE_Arc::RPG {
class Vendor : public Hero {
public:
  Vendor(int strength = 10, int agility = 5, int intelligence = 1,
         double hp = 20, string name = "unknown vendor", float factor = 1,
         IObject *pObject = new Sword())
      : Hero(strength, agility, intelligence, hp, name, pObject),
        factor(factor) {}

  float getFactor() const { return this->factor; };
  const string getType() const override { return "vendor"; }

  void sell(IObject *pObject, Hero *hero);
  void interact(const Hero &hero) override;

protected:
  float factor = 1;
};
} // namespace HE_Arc::RPG
