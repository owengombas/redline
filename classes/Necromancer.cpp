#include "../headers/Necromancer.h"

#include <iostream>

#include "../headers/Hero.h"
#include "../headers/Wizard.h"

using namespace std;

namespace HE_Arc::RPG {
Necromancer::Necromancer(int strength, int agility, int intelligence, double hp,
                         string name, Sword *sword, int mana)
    : Wizard(strength, agility, intelligence, hp, name, sword, mana) {}

void Necromancer::riseUndeads() {
  if (this->mana >= 2) {
    cout << "Rise Undeads!!!";
  }
}
} // namespace HE_Arc::RPG