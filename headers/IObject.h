#pragma once
#include <cmath>
#include <iostream>

using namespace std;

namespace HE_Arc::RPG {
class IObject {
public:
  IObject(float priceFactor) : priceFactor(priceFactor) {}
  IObject() = default;
  virtual ~IObject() = default;

  virtual string getName() const = 0;
  virtual int getFeature() const = 0;
  virtual IObject *clone() const = 0;

  // (1 + 1/15)^feature => Exponential function
  float getPrice() const {
    return (float)pow(1 + 1.0 / 15, this->getFeature()) *
           this->getPriceFactor();
  };

  float getPriceFactor() const { return this->priceFactor; }
  void setPriceFactor(float priceFactor) { this->priceFactor = priceFactor; }

  friend ostream &operator<<(ostream &s, const IObject &pObject);

private:
  float priceFactor = 1;
};
ostream &operator<<(ostream &s, const IObject &pObject);
} // namespace HE_Arc::RPG
