#include <iostream>

#include "../headers/Backpack.h"

using namespace std;

namespace HE_Arc::RPG {
bool Backpack::isNotEmpty() const { return !mStack.empty(); }

void Backpack::pack(IObject *pObject) { mStack.push(pObject); }

IObject *Backpack::unpack() {
  IObject *pObject = this->mStack.top();
  mStack.pop();
  return pObject;
}
} // namespace HE_Arc::RPG