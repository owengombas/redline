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
    throw runtime_error("Cet vendeur ne vend pas cet objet");
  }

  float price = pObject->getPrice();

  if (hero->getMoney() < price) {
    throw runtime_error(
        "Vous n'avez pas assez d'argent pour acheter cet objet");
  }

  // We clone the object and do not erase it from his backpack
  // because the vendor can sell infinite items that are in the backpack
  IObject *obj = pObject->clone();

  this->money += price;
  hero->setMoney(hero->getMoney() - price);
  hero->getBackpack()->add(obj);

  // Log the transaction
  Log::writeTransaction(this, hero, pObject, price);
}

void Vendor::interact(const Hero &hero) {
  cout << "Le héro " << this->getName() << " intéragis avec le vendeur "
       << hero.getName();
}
} // namespace HE_Arc::RPG
