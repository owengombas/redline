#pragma once
#include <cmath>
#include <iostream>

using namespace std;

namespace HE_Arc::RPG {
class IObject {
public:
  virtual ~IObject() = default;

  virtual string getName() const = 0;
  virtual int getFeature() const = 0;
  virtual IObject *clone() const = 0;

  // (1 + 1/25)^feature => Exponential function
  virtual float getPrice() const {
    return pow(1 + 1 / 25, this->getFeature());
  };

  friend ostream &operator<<(ostream &s, const IObject &pObject);
};
ostream &operator<<(ostream &s, const IObject &pObject);
} // namespace HE_Arc::RPG
