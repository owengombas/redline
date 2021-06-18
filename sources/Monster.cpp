#include <iostream>

#include "../headers/IObject.h"
#include "../headers/Log.h"
#include "../headers/Monster.h"

using namespace std;

namespace HE_Arc::RPG {
Monster::Monster(int strength, int agility, int intelligence, double hp,
                 string name)
    : strength(strength), agility(agility), intelligence(intelligence), hp(hp),
      name(name) {}

Monster::~Monster() {}

Monster::Monster(const Monster &monster) {
  this->init(monster.strength, monster.agility, monster.intelligence,
             monster.hp, monster.name);
}

Monster &Monster::operator=(const Monster &monster) {
  this->init(monster.strength, monster.agility, monster.intelligence,
             monster.hp, monster.name);

  return *this;
}

/**
 * Initialize the Monster with properties
 */
Monster &Monster::init(int strength, int agility, int intelligence, double hp,
                       string name) {
  this->agility = agility;
  this->strength = strength;
  this->hp = hp;
  this->intelligence = intelligence;
  this->name = name;

  return *this;
}

ostream &operator<<(ostream &s, const Monster &monster) {
  s << "=================" << endl;
  s << monster.getType() << ": " << monster.getName() << endl;
  s << "=================" << endl;
  s << "Strength: " << monster.getStrength() << endl;
  s << "Agility: " << monster.getAgility() << endl;
  s << "Intelligence: " << monster.getIntelligence() << endl;
  s << "HP: " << monster.getHp() << endl;

  return s;
}
} // namespace HE_Arc::RPG