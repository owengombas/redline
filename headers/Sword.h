#pragma once
#include <iostream>

#include "IObject.h"

using namespace std;

namespace HE_Arc::RPG {
class Sword : public IObject {
public:
  Sword() = default;
  Sword(int damage) : damage(damage){};
  virtual ~Sword() override = default;

  string getName() const override;
  int getFeature() const override;

  Sword *clone() const override { return new Sword(*this); };

private:
  int damage = 10;
};
} // namespace HE_Arc::RPG
