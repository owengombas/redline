#pragma once
#include "IObject.h"
#include <string>

using namespace std;

namespace HE_Arc::RPG {
class Bow : public IObject {
public:
  Bow() = default;
  Bow(int power, float priceFactor = 1) : IObject(priceFactor), power(power){};
  ;
  virtual ~Bow() override = default;

  string getName() const override;
  int getFeature() const override;

  Bow *clone() const override { return new Bow(*this); };

protected:
  int power = 10;
};
} // namespace HE_Arc::RPG
