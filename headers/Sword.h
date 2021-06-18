#pragma once
#include "IObject.h"
#include <string>

using namespace std;

namespace HE_Arc::RPG {
class Sword : public IObject {
public:
  Sword() = default;
  Sword(int damage, float priceFactor = 1)
      : IObject(priceFactor), damage(damage){};
  virtual ~Sword() override = default;

  string getName() const override;
  int getFeature() const override;

  Sword *clone() const override { return new Sword(*this); };

private:
  int damage = 10;
};
} // namespace HE_Arc::RPG
