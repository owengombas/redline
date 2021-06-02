#pragma once
#include <iostream>
#include <stack>

#include "IObject.h"

using namespace std;

namespace HE_Arc::RPG {
class Backpack {
private:
  stack<IObject *> mStack;

public:
  Backpack() = default;
  virtual ~Backpack() = default;

  void pack(IObject *pObject);
  IObject *unpack();

  bool isNotEmpty() const;
};
} // namespace HE_Arc::RPG
