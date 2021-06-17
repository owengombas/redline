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
  virtual const string getType() const = 0;

  void sell(IObject *pObject, Hero *hero);

  int getStrength() const { return strength; }
  int getAgility() const { return agility; }
  int getIntelligence() const { return intelligence; }
  int getHp() const { return hp; }
  float getMoney() const { return money; }
  string getName() const { return name; }
  IObject *getObject() const { return pObject; }

  friend class Vendor;
  friend ostream &operator<<(ostream &s, const Hero &hero);
  Hero &operator=(const Hero &hero);

  Backpack backpack;

protected:
  float money = 250;
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
