#include <iostream>

#include "../headers/Attackable.h"
#include "../headers/Log.h"
#include "../headers/Monster.h"

using namespace std;

namespace HE_Arc::RPG {
Monster::Monster(int strength, int agility, int intelligence, int hp,
                 string name)
    : Attackable(strength, agility, intelligence, hp, name) {}

Monster::~Monster() {}

Monster::Monster(const Monster &monster)
    : Attackable(strength, agility, intelligence, hp, name) {}

Monster &Monster::operator=(const Monster &mosnter) {
  this->agility = mosnter.agility;
  this->strength = mosnter.strength;
  this->hp = mosnter.hp;
  this->intelligence = mosnter.intelligence;
  this->name = mosnter.name;

  return *this;
}

int Monster::getAttackDamage() const {
  int damage = this->intelligence + this->agility * 2 + this->strength * 4;
  return damage;
}

int Monster::attack(Attackable *attacked) {
  int damage = this->getAttackDamage();
  attacked->setHp(attacked->getHp() - damage);
  Log::writeFight(this, attacked, damage);
  return damage;
}

ostream &operator<<(ostream &s, const Monster &monster) {
  s << "=================" << endl;
  s << monster.getType() << ": " << monster.getName() << endl;
  s << "=================" << endl;
  s << "Strength: " << monster.getStrength() << endl;
  s << "Agility: " << monster.getAgility() << endl;
  s << "Intelligence: " << monster.getIntelligence() << endl;
  s << "HP: " << monster.getHp() << endl;
  s << "Attack: " << monster.getAttackDamage() << endl;

  return s;
}
} // namespace HE_Arc::RPG