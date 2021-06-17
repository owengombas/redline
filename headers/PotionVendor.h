#pragma once
#include <iostream>

#include "Potion.h"
#include "Vendor.h"

using namespace std;

namespace HE_Arc::RPG {
class PotionVendor : public Vendor {
public:
  PotionVendor(int strength = 10, int agility = 5, int intelligence = 1,
               double hp = 20, string name = "unknown potion vendor",
               float factor = 1.5, IObject *pObject = new Potion());

  const string getType() const override { return "potion vendor"; }
};
} // namespace HE_Arc::RPG
