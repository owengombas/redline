#include "../headers/Bow.h"

using namespace std;

namespace HE_Arc::RPG {
string Bow::getName() const { return "bow"; }
int Bow::getFeature() const { return this->power; }
} // namespace HE_Arc::RPG