#pragma once
#include <iostream>
#include <vector>

#include "IObject.h"

using namespace std;

namespace HE_Arc::RPG {
class Backpack {
private:
  vector<IObject *> items;

public:
  Backpack() = default;
  virtual ~Backpack() = default;

  void add(IObject *pObject);
  void remove(const IObject *pObject);
  bool exists(const IObject *pObject);

  const vector<IObject *> getItems() const { return this->items; }
  IObject *getItem(const int index) const {
    if (index < this->items.size()) {
      return this->items[index];
    }
    throw runtime_error("Your backpack do not cointains this item");
  }

  bool isNotEmpty() const;
};
} // namespace HE_Arc::RPG
