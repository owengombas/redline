#include "../headers/Hero.h"
#include "../headers/Necromancer.h"
#include "../headers/Wizard.h"

#include <iostream>

using namespace std;

namespace HE_Arc::RPG
{
  Necromancer::Necromancer(int strength, int agility, int intelligence, double hp, string name, Sword *sword, int mana) : Wizard(strength, agility, intelligence, hp, name,
                                                                                                                                 sword, mana)
  {
  }

  void Necromancer::riseUndeads()
  {
    if (this->mana >= 2)
    {
      cout << "Rise Undeads!!!";
    }
  }

  void Hero::interact(const Hero &hero) {}
} // namespace HE_Arc::RPG