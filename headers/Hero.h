#pragma once
#include "Attackable.h"
#include "Backpack.h"
#include "IObject.h"
#include <iostream>

using namespace std;

namespace HE_Arc::RPG {
class Hero : public Attackable {
public:
  friend ostream &operator<<(ostream &s, const Hero &hero);

  Hero() = default;
  Hero(const Hero &hero);
  Hero(int strength, int agility, int intelligence, int hp, string name,
       IObject *sword);
  virtual ~Hero();

  float getMoney() const { return money; }
  IObject *getObject() const { return pObject; }
  Backpack *getBackpack() const { return backpack; }

  void setMoney(float money) { this->money = money; }

  /**
   * Changing the object in hands change the given damage
   */
  void setObject(IObject *object) {
    this->getBackpack()->add(this->getObject());
    this->pObject = object;
  }

  void sell(IObject *pObject, Hero *hero);

  int attack(Attackable *attackable) override;
  int getAttackDamage() const override;

  virtual void interact(const Hero &otherHero) = 0;

  Hero &operator=(const Hero &hero);

protected:
  Backpack *backpack;
  float money = 250;
  int strength = 10;
  int agility = 10;
  int intelligence = 10;
  int hp = 100;
  string name = "no_name";
  IObject *pObject = nullptr;
};

ostream &operator<<(ostream &s, const Hero &hero);
} // namespace HE_Arc::RPG
