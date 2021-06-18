#pragma once
#include "Attackable.h"
#include <iostream>

using namespace std;

namespace HE_Arc::RPG {
class Monster : public Attackable {
public:
  Monster() = default;
  Monster(const Monster &monster);
  Monster(int strength, int agility, int intelligence, int hp, string name);
  virtual ~Monster();

  int attack(Attackable *attackable) override;
  int getAttackDamage() const override;

  friend ostream &operator<<(ostream &s, const Monster &monster);
  Monster &operator=(const Monster &hero);

  const string getType() const override { return "monster"; }

protected:
  int strength = 100;
  int agility = 50;
  int intelligence = 10;
  int hp = 250;
  string name = "no_name";
};

ostream &operator<<(ostream &s, const Monster &hero);
} // namespace HE_Arc::RPG
