#include <iostream>

#include "../headers/Sword.h"

using namespace std;

namespace HE_Arc::RPG {
string Sword::getName() const { return "sword"; }
int Sword::getFeature() const { return this->damage; }
} // namespace HE_Arc::RPG