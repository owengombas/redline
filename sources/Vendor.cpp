#include <iostream>

#include "../headers/Log.h"
#include "../headers/Vendor.h"

using namespace std;

namespace HE_Arc::RPG {
/**
 * A vendor can exchange (sell) their backpack items with money
 * but they keep the item in their backpack because they have providers :)
 * So this method is different from the one for Hero
 */
void Vendor::sell(IObject *pObject, Hero *hero) {
  if (!this->backpack->exists(pObject)) {
    throw runtime_error("This vendor do not sell this item");
  }

  float price = pObject->getPrice();

  if (hero->money < price) {
    throw runtime_error("You don't have enough money to buy this item");
  }

  // We clone the object and do not erase it from his backpack
  // because the vendor can sell infinite items that are in the backpack
  IObject *obj = pObject->clone();

  this->money += price;
  hero->money -= price;
  hero->backpack->add(obj);

  // Log the transaction
  Log::writeTransaction(this, hero, pObject, price);
}

void Vendor::interact(const Hero &hero) {
  cout << "Hero " << this->getName() << " interact with the Vendor named "
       << hero.getName();
}
} // namespace HE_Arc::RPG
