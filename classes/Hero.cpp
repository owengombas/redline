#include "../headers/Hero.h"

#include <iostream>

#include "../headers/IObject.h"

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

ostream &operator<<(ostream &s, const Hero &hero) {
  s << "=================" << endl;
  s << "HERO: " << hero.getName() << endl;
  s << "=================" << endl;
  s << "strength: " << hero.getStrength() << endl;
  s << "agility: " << hero.getAgility() << endl;
  s << "intelligence: " << hero.getIntelligence() << endl;
  s << "HP: " << hero.getHp() << endl;
  return s;
}
} // namespace HE_Arc::RPG