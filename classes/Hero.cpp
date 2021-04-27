#include "../headers/Hero.h"

#include <iostream>

#include "../headers/Sword.h"

using namespace std;

namespace HE_Arc::RPG {
Hero::Hero(int strength, int agility, int intelligence, double hp, string name,
           Sword &sword)
    : strength(strength),
      agility(agility),
      intelligence(intelligence),
      hp(hp),
      name(name),
      sword(&sword) {}

Hero::~Hero() { delete this->sword; }

Hero::Hero(const Hero &hero) {
  this->init(hero.strength, hero.agility, hero.intelligence, hero.hp, hero.name,
             hero.sword);
}

Hero &Hero::operator=(const Hero &hero) {
  this->init(hero.strength, hero.agility, hero.intelligence, hero.hp, hero.name,
             hero.sword);

  return *this;
}

Hero &Hero::init(int strength, int agility, int intelligence, double hp,
                 string name, Sword *sword) {
  this->agility = agility;
  this->strength = strength;
  this->hp = hp;
  this->intelligence = intelligence;
  this->name = name;
  this->sword = sword;

  return *this;
}

ostream &operator<<(ostream &s, const Hero &hero) {
  s << "=================" << endl;
  s << "HERO: " << hero.getName() << endl;
  s << "=================" << endl;
  s << "strength: " << hero.getStrength() << endl;
  s << "agility: " << hero.getAgility() << endl;
  s << "intelligence: " << hero.getIntelligence() << endl;
  s << "HP: " << hero.getHp() << endl;
  return s;
}

void Hero::interact(const Hero &hero) {}
}  // namespace HE_Arc::RPG