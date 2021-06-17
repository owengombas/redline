#include <algorithm>
#include <iostream>
#include <vector>

#include "../headers/Backpack.h"

using namespace std;

namespace HE_Arc::RPG {
bool Backpack::isNotEmpty() const { return !this->items.empty(); }

void Backpack::add(IObject *pObject) { this->items.push_back(pObject); }

void Backpack::remove(const IObject *pObject) {
  auto found = find(this->items.begin(), this->items.end(), pObject);
  if (found != this->items.end()) {
    this->items.erase(found);
  }
}

bool Backpack::exists(const IObject *pObject) {
  auto found = find(this->items.begin(), this->items.end(), pObject);
  return found != this->getItems().end();
}
} // namespace HE_Arc::RPG