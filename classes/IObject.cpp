#include <iostream>

#include "../headers/IObject.h"

using namespace std;

namespace HE_Arc::RPG {
ostream &operator<<(ostream &s, const IObject &pObject) {
  s << pObject.getName() << "(" << pObject.getFeature() << ")";
  return s;
}
} // namespace HE_Arc::RPG