#include <iostream>

#include "../headers/Potion.h"

using namespace std;

namespace HE_Arc::RPG {
string Potion::getName() const { return "potion"; }
int Potion::getFeature() const { return this->power; }
} // namespace HE_Arc::RPG