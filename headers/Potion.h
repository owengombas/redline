#pragma once
#include <iostream>

#include "IObject.h"

using namespace std;

namespace HE_Arc::RPG {
class Potion : public IObject {
public:
  Potion() = default;
  Potion(int power) : power(power){};
  virtual ~Potion() override = default;

  string getName() const override;
  int getFeature() const override;

protected:
  int power = 10;
};
} // namespace HE_Arc::RPG
