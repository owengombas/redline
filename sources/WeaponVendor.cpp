#include "../headers/WeaponVendor.h"
#include <iostream>

using namespace std;

namespace HE_Arc::RPG {
/**
 * Initialize an WeaponVendor with all his items
 * This items cannot disappear from his backpack during a transaction
 */
WeaponVendor::WeaponVendor(int strength, int agilit, int intelligenc, double hp,
                           string name, float factor, IObject *pObject)
    : Vendor(strength, agility, intelligence, hp, name, factor, pObject) {
  this->backpack.add(new Sword(25));
  this->backpack.add(new Sword(50));
  this->backpack.add(new Sword(100));
  this->backpack.add(new Sword(200));
  this->backpack.add(new Sword(400));

  this->backpack.add(new Shield(25));
  this->backpack.add(new Shield(50));
  this->backpack.add(new Shield(100));
  this->backpack.add(new Shield(200));
  this->backpack.add(new Shield(400));
}
} // namespace HE_Arc::RPG
