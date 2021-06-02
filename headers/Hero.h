#pragma once
#include <iostream>

#include "Backpack.h"
#include "IObject.h"

using namespace std;

namespace HE_Arc::RPG {
class Hero {
public:
  Hero() = default;
  Hero(const Hero &hero);
  Hero(int strength, int agility, int intelligence, double hp, string name,
       IObject *sword);

  virtual ~Hero();

  virtual void interact(const Hero &otherHero) = 0;
  int getStrength() const { return strength; }
  int getAgility() const { return agility; }
  int getIntelligence() const { return intelligence; }
  double getHp() const { return hp; }
  string getName() const { return name; }
  IObject *getObject() const { return pObject; }

  friend ostream &operator<<(ostream &s, const Hero &hero);
  Hero &operator=(const Hero &hero);

  Backpack backpack;

protected:
  int strength = 0;
  int agility = 0;
  int intelligence = 0;
  double hp = 0;
  string name = "no_name";
  IObject *pObject = nullptr;

private:
  Hero &init(int strength, int agility, int intelligence, double hp,
             string name, IObject *sword);
};

ostream &operator<<(ostream &s, const Hero &hero);
} // namespace HE_Arc::RPG
