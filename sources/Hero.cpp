#include <iostream>

#include "../headers/Hero.h"
#include "../headers/IObject.h"
#include "../headers/Log.h"

using namespace std;

namespace HE_Arc::RPG {
Hero::Hero(int strength, int agility, int intelligence, int hp, string name,
           IObject *pObject)
    : Attackable(strength, agility, intelligence, hp, name), pObject(pObject),
      backpack(new Backpack()) {}

Hero::~Hero() {
  delete this->pObject;
  delete this->backpack;
}

Hero::Hero(const Hero &hero)
    : Attackable(strength, agility, intelligence, hp, name),
      pObject(hero.pObject), backpack(new Backpack()) {}

Hero &Hero::operator=(const Hero &hero) {
  this->agility = hero.agility;
  this->strength = hero.strength;
  this->hp = hero.hp;
  this->intelligence = hero.intelligence;
  this->name = hero.name;
  this->pObject = hero.pObject;

  return *this;
}

/**
 * Interact with an other Hero
 */
void Hero::interact(const Hero &otherHero) {
  cout << "Le héro " << this->getName() << " intéragis avec le héro "
       << otherHero.getName();
}

/**
 * A hero can exchange (sell) their backpack items with money
 */
void Hero::sell(IObject *pObject, Hero *hero) {
  bool exists = !this->getBackpack()->exists(pObject);
  if (exists) {
    throw runtime_error("Vous ne possédez pas cet objet");
  }

  float price = pObject->getPrice();

  if (hero->money < price) {
    throw runtime_error(
        "Vous n'avez pas assez d'argent pour acheter cet objet");
  }

  this->money += price;
  hero->money -= price;

  hero->getBackpack()->add(pObject);
  this->getBackpack()->remove(pObject);

  // Log the transaction in transactions.log
  Log::writeTransaction(this, hero, pObject, price);
}

int Hero::getAttackDamage() const {
  int damage = this->intelligence * 0.5 + this->agility + this->strength * 1.5 +
               this->getObject()->getFeature() * 2;
  return damage;
}

int Hero::attack(Attackable *attacked) {
  int damage = this->getAttackDamage();
  attacked->setHp(attacked->getHp() - damage);
  Log::writeFight(this, attacked, damage);
  return damage;
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
  s << "Attack: " << hero.getAttackDamage() << endl;
  s << "Object in hands: " << *hero.getObject() << endl;

  s << "Backpack: " << endl;

  for (const auto &item : hero.getBackpack()->getItems()) {
    s << "    " << *item << endl;
  }

  return s;
}
} // namespace HE_Arc::RPG