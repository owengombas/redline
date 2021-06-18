#include "../headers/Warrior.h"

#include <iostream>

#include "../headers/Hero.h"
#include "../headers/Sword.h"

using namespace std;

namespace HE_Arc::RPG {
void Warrior::interact(const Hero &hero) {
  cout << "Le héro " << this->getName() << " intéragis avec le guerrier "
       << hero.getName();
}
} // namespace HE_Arc::RPG