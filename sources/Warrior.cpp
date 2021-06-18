#include "../headers/Warrior.h"

using namespace std;

namespace HE_Arc::RPG {
void Warrior::interact(const Hero &hero) {
  cout << "Le héro " << this->getName() << " intéragis avec le guerrier "
       << hero.getName();
}
} // namespace HE_Arc::RPG