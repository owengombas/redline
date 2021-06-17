#include <iostream>

#include "../headers/Log.h"
#include "../headers/Vendor.h"

using namespace std;

namespace HE_Arc::RPG {
// A vendor can exchange their backpack items with money
// but they keep the item in their backpack because they have providers :)
void Vendor::sell(IObject *pObject, Hero *hero) {
  if (!this->backpack.exists(pObject)) {
    throw runtime_error("This vendor do not sell this item");
  }

  float price = pObject->getPrice() * this->factor;

  IObject *obj = pObject->clone();

  this->money += price;

  hero->money -= price;
  hero->backpack.add(obj);

  Log::writeTransaction(this, hero, pObject, price);
}

void Vendor::interact(const Hero &hero) { cout << "hello"; }
} // namespace HE_Arc::RPG
