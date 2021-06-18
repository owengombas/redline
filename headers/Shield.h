#pragma once
#include <iostream>

#include "IObject.h"

using namespace std;

namespace HE_Arc::RPG {
class Shield : public IObject {
public:
  Shield() = default;
  Shield(int solidity, float priceFactor = 1)
      : IObject(priceFactor), solidity(solidity){};
  ;
  virtual ~Shield() override = default;

  string getName() const override;
  int getFeature() const override;

  Shield *clone() const override { return new Shield(*this); };

private:
  int solidity = 10;
};
} // namespace HE_Arc::RPG
