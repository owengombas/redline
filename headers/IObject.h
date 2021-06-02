#pragma once
#include <iostream>

using namespace std;

namespace HE_Arc::RPG {
class IObject {
public:
  virtual ~IObject() = default;

  virtual string getName() const = 0;
  virtual int getFeature() const = 0;
};
} // namespace HE_Arc::RPG
