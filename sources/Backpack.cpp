#include "../headers/Backpack.h"

using namespace std;

namespace HE_Arc::RPG {
/**
 * Remove an object from the backpack
 */
void Backpack::remove(const IObject *pObject) {
  auto found = find(this->items.begin(), this->items.end(), pObject);
  if (found != this->items.end()) {
    this->items.erase(found);
  }
}

/**
 * Verify that the object exists in the backpack
 */
bool Backpack::exists(const IObject *pObject) {
  auto found = find(this->items.begin(), this->items.end(), pObject);
  return found != this->getItems().end();
}

/**
 * Verify that the backpack is not empty
 */
bool Backpack::isNotEmpty() const { return !this->items.empty(); }

/**
 * Add an item in the backpack
 */
void Backpack::add(IObject *pObject) { this->items.push_back(pObject); }
} // namespace HE_Arc::RPG