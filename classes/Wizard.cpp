#include "../headers/Hero.h"
#include "../headers/Wizard.h"

#include <iostream>

using namespace std;

namespace HE_Arc::RPG
{
  Wizard::Wizard(int strength, int agility, int intelligence, double hp, string name, Sword *sword, int mana) : Hero(strength, agility, intelligence, hp, name,
                                                                                                                     sword)
  {
    this->mana = mana;
  }

  void Wizard::castSpell()
  {
    if (this->mana >= 2)
    {
      cout << "Fire ball!!!";
    }
  }

  void Wizard::interact(const Hero &hero) {}
} // namespace HE_Arc::RPG