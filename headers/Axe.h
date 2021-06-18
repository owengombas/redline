#pragma once
#include "IObject.h"
#include <string>

using namespace std;

namespace HE_Arc::RPG {
class Axe : public IObject {
public:
  Axe() = default;
  Axe(int power, float priceFactor = 1) : IObject(priceFactor), power(power){};
  ;
  virtual ~Axe() override = default;

  string getName() const override;
  int getFeature() const override;

  Axe *clone() const override { return new Axe(*this); };

protected:
  int power = 10;
};
} // namespace HE_Arc::RPG
