#include "../headers/PotionVendor.h"

using namespace std;

namespace HE_Arc::RPG {
/**
 * Initialize an PotionVender with all his items
 * This items cannot disappear from his backpack during a transaction
 */
PotionVendor::PotionVendor(int strength, int agility, int intelligence, int hp,
                           string name, float factor, IObject *pObject)
    : Vendor(strength, agility, intelligence, hp, name, factor, pObject) {
  this->getBackpack()->add(new Potion(10, factor));
  this->getBackpack()->add(new Potion(20, factor));
  this->getBackpack()->add(new Potion(40, factor));
  this->getBackpack()->add(new Potion(80, factor));
  this->getBackpack()->add(new Potion(160, factor));
}
} // namespace HE_Arc::RPG
