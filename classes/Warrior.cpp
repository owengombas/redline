#include "../headers/Hero.h"
#include "../headers/Warrior.h"
#include "../headers/Sword.h"

#include <iostream>

using namespace std;

namespace HE_Arc::RPG
{
  Warrior::Warrior(int strength, int agility, int intelligence, double hp, string name, Sword *sword) : Hero(strength, agility, intelligence, hp, name,
                                                                                                             sword)
  {
  }

  void Hero::interact(const Hero &hero) {}
} // namespace HE_Arc::RPG