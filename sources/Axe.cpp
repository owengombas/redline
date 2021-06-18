#include "../headers/Axe.h"

using namespace std;

namespace HE_Arc::RPG {
string Axe::getName() const { return "axe"; }
int Axe::getFeature() const { return this->power; }
} // namespace HE_Arc::RPG