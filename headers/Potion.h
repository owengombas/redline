#pragma once
#include <iostream>

#include "IObject.h"

using namespace std;

namespace HE_Arc::RPG {
class Potion : public IObject {
public:
  Potion() = default;
  Potion(int power, float priceFactor = 1)
      : IObject(priceFactor), power(power){};
  ;
  virtual ~Potion() override = default;

  string getName() const override;
  int getFeature() const override;

  Potion *clone() const override { return new Potion(*this); };

protected:
  int power = 10;
};
} // namespace HE_Arc::RPG
