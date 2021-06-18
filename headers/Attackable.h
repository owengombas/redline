#pragma once
#include <string>

using namespace std;

namespace HE_Arc::RPG {
class Attackable {
public:
  Attackable(int strength, int agility, int intelligence, int hp, string name)
      : strength(strength), agility(agility), intelligence(intelligence),
        hp(hp), name(name) {}

  virtual int attack(Attackable *attackable) = 0;
  virtual int getAttackDamage() const = 0;
  virtual const string getType() const = 0;

  int getStrength() const { return this->strength; }
  int getAgility() const { return this->agility; }
  int getIntelligence() const { return this->intelligence; }
  int getHp() const { return this->hp; }
  string getName() const { return this->name; }
  bool isDead() const { return this->hp <= 0; }

  void setHp(int hp) { this->hp = hp; }

protected:
  int strength = 100;
  int agility = 50;
  int intelligence = 10;
  int hp = 250;
  string name = "no_name";
};
} // namespace HE_Arc::RPG
