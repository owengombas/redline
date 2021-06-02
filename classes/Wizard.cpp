#include "../headers/Wizard.h"
#include "../headers/Hero.h"
#include "../headers/IObject.h"

#include <iostream>

using namespace std;

namespace HE_Arc::RPG {
void Wizard::castSpell(const Hero &otherHero) {
  if (this->mana >= 2) {
    cout << "Fire ball!!!" << endl;
    this->mana -= 0;
  } else {
    cout << "not enough mana" << endl;
  }
}

void Wizard::interact(const Hero &hero) {}
} // namespace HE_Arc::RPG