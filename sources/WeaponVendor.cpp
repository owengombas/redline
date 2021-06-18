#include "../headers/WeaponVendor.h"
#include <iostream>

using namespace std;

namespace HE_Arc::RPG {
/**
 * Initialize an WeaponVendor with all his items
 * This items cannot disappear from his backpack during a transaction
 */
WeaponVendor::WeaponVendor(int strength, int agilit, int intelligenc, int hp,
                           string name, float factor, IObject *pObject)
    : Vendor(strength, agility, intelligence, hp, name, factor, pObject) {
  this->getBackpack()->add(new Sword(25, factor));
  this->getBackpack()->add(new Sword(50, factor));
  this->getBackpack()->add(new Sword(100, factor));
  this->getBackpack()->add(new Sword(200, factor));
  this->getBackpack()->add(new Sword(400, factor));

  this->getBackpack()->add(new Shield(25, factor));
  this->getBackpack()->add(new Shield(50, factor));
  this->getBackpack()->add(new Shield(100, factor));
  this->getBackpack()->add(new Shield(200, factor));
  this->getBackpack()->add(new Shield(400, factor));
}
} // namespace HE_Arc::RPG
