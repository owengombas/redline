#include "../headers/Warrior.h"

#include <iostream>

#include "../headers/Hero.h"
#include "../headers/Sword.h"

using namespace std;

namespace HE_Arc::RPG {
void Warrior::interact(const Hero &hero) {
  cout << "Hero " << this->getName() << " interact with the Warrior named "
       << hero.getName();
}
} // namespace HE_Arc::RPG