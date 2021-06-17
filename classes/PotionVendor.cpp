#include "../headers/PotionVendor.h"
#include "../headers/Potion.h"
#include <iostream>

using namespace std;

namespace HE_Arc::RPG {
PotionVendor::PotionVendor(int strength, int agility, int intelligence,
                           double hp, string name, float factor,
                           IObject *pObject)
    : Vendor(strength, agility, intelligence, hp, name, factor, pObject) {
  this->backpack.add(new Potion(10));
  this->backpack.add(new Potion(20));
  this->backpack.add(new Potion(40));
  this->backpack.add(new Potion(80));
  this->backpack.add(new Potion(160));
}
} // namespace HE_Arc::RPG
