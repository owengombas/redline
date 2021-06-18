#include "../headers/Shield.h"

using namespace std;

namespace HE_Arc::RPG {
string Shield::getName() const { return "shield"; }
int Shield::getFeature() const { return this->solidity; }
} // namespace HE_Arc::RPG