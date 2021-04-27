#pragma once
#include <iostream>

#include "Hero.h"

using namespace std;

namespace HE_Arc::RPG
{
  class Warrior : public Hero
  {
  public:
    Warrior(int strength, int agility, int intelligence, double hp, string name, Sword *sword);

    void interact(const Hero &hero) override;

  protected:
    int strength = 10;
  };
} // namespace HE_Arc::RPG
