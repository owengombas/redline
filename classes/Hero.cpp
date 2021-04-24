#include "../headers/Hero.h"

#include <iostream>

using namespace std;

namespace HE_Arc::RPG {
Hero::Hero(int strength, int agility, int intelligence, double hp, string name)
    : strength(strength),
      agility(agility),
      intelligence(intelligence),
      hp(hp),
      name(name) {}

void Hero::show() {
  cout << "=================" << endl;
  cout << "HERO: " << name << endl;
  cout << "=================" << endl;
  cout << "strength: " << strength << endl;
  cout << "agility: " << agility << endl;
  cout << "intelligence: " << intelligence << endl;
  cout << "HP: " << hp << endl;
}

void Hero::interact(const Hero& hero) {}
}  // namespace HE_Arc::RPG