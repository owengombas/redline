#pragma once
#include <iostream>

#include "Sword.h"

using namespace std;

namespace HE_Arc::RPG {
class Hero {
 public:
  Hero() = default;
  // Hero(const Hero& hero);  Not needed
  Hero(int strength, int agility, int intelligence, double hp, string name);

  int getStrength() const { return strength; }
  int getAgility() const { return agility; }
  int getIntelligence() const { return intelligence; }
  double getHp() const { return hp; }
  string getName() const { return name; }
  Sword getSword() const { return *sword; }

 protected:
  int strength = 0;
  int agility = 0;
  int intelligence = 0;
  double hp = 0;
  string name = "no_name";
  Sword* sword = new Sword();

  void show();
  void interact(const Hero& hero);
};
}  // namespace HE_Arc::RPG
