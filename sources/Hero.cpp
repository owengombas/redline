#include <iostream>

#include "../headers/Hero.h"
#include "../headers/IObject.h"
#include "../headers/Log.h"

using namespace std;

namespace HE_Arc::RPG {
Hero::Hero(int strength, int agility, int intelligence, double hp, string name,
           IObject *pObject)
    : strength(strength), agility(agility), intelligence(intelligence), hp(hp),
      name(name), pObject(pObject) {}

Hero::~Hero() { delete this->pObject; }

Hero::Hero(const Hero &hero) {
  this->init(hero.strength, hero.agility, hero.intelligence, hero.hp, hero.name,
             hero.pObject);
}

Hero &Hero::operator=(const Hero &hero) {
  this->init(hero.strength, hero.agility, hero.intelligence, hero.hp, hero.name,
             hero.pObject);

  return *this;
}

void Hero::interact(const Hero &otherHero) {
  cout << "Hero " << this->getName() << " interact with "
       << otherHero.getName();
}

Hero &Hero::init(int strength, int agility, int intelligence, double hp,
                 string name, IObject *pObject) {
  this->agility = agility;
  this->strength = strength;
  this->hp = hp;
  this->intelligence = intelligence;
  this->name = name;
  this->pObject = pObject;

  return *this;
}

// A hero can exchange their backpack items with money
void Hero::sell(IObject *pObject, Hero *hero) {
  if (!this->backpack.exists(pObject)) {
    throw runtime_error("You do not possess this item");
  }

  float price = pObject->getPrice();
  this->money += price;
  hero->money -= price;

  hero->backpack.add(pObject);
  this->backpack.remove(pObject);

  Log::writeTransaction(this, hero, pObject, price);
}

ostream &operator<<(ostream &s, const Hero &hero) {
  s << "=================" << endl;
  s << hero.getType() << ": " << hero.getName() << endl;
  s << "=================" << endl;
  s << "Strength: " << hero.getStrength() << endl;
  s << "Agility: " << hero.getAgility() << endl;
  s << "Intelligence: " << hero.getIntelligence() << endl;
  s << "Money: " << hero.getMoney() << endl;
  s << "HP: " << hero.getHp() << endl;
  s << "Object in hands: " << *hero.getObject() << endl;

  s << "Backpack: " << endl;

  for (const auto &item : hero.backpack.getItems()) {
    s << "    " << *item << endl;
  }

  return s;
}
} // namespace HE_Arc::RPG