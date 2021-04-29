#pragma once
#include <iostream>

#include "Hero.h"

using namespace std;

namespace HE_Arc::RPG
{
  class Wizard : public Hero
  {
  public:
    Wizard(int strength, int agility, int intelligence, double hp, string name, Sword *sword, int mana);
    void castSpell();
    int getMana() { return this->mana; }
    void interact(const Hero &hero) override;

  protected:
    int mana = 0;
    int intelligence = 10;
  };
} // namespace HE_Arc::RPG
