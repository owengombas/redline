#pragma once
#include "Vendor.h"
#include <iostream>

using namespace std;

namespace HE_Arc::RPG {
class PotionVendor : public Vendor {
public:
  PotionVendor(int strength = 10, int agility = 5, int intelligence = 1,
               double hp = 20, string name = "unknown potion vendor",
               IObject *pObject = new Sword())
      : Vendor(strength, agility, intelligence, hp, name, pObject) {}

  void interact(const Hero &hero) override;
};
} // namespace HE_Arc::RPG
