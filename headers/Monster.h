#pragma once
#include <iostream>

#include "Backpack.h"
#include "IObject.h"

using namespace std;

namespace HE_Arc::RPG {
class Monster {
public:
  Monster() = default;
  Monster(const Monster &hero);
  Monster(int strength, int agility, int intelligence, double hp, string name);
  virtual ~Monster();

  friend ostream &operator<<(ostream &s, const Monster &hero);
  Monster &operator=(const Monster &hero);

  virtual string getType() const = 0;
  int getStrength() const { return strength; }
  int getAgility() const { return agility; }
  int getIntelligence() const { return intelligence; }
  int getHp() const { return hp; }
  string getName() const { return name; }

protected:
  int strength = 100;
  int agility = 50;
  int intelligence = 10;
  double hp = 250;
  string name = "no_name";

private:
  Monster &init(int strength, int agility, int intelligence, double hp,
                string name);
};

ostream &operator<<(ostream &s, const Monster &hero);
} // namespace HE_Arc::RPG
