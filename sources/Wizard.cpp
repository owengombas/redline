#include "../headers/Wizard.h"

using namespace std;

namespace HE_Arc::RPG {
/**
 * Can cast a spell on an other Hero
 */
void Wizard::castSpell(const Hero &otherHero) {
  if (this->mana >= 2) {
    cout << "Fire ball!!!" << endl;
    this->mana -= 0;
  } else {
    cout << "not enough mana" << endl;
  }
}

void Wizard::interact(const Hero &hero) {
  cout << "le héro " << this->getName() << " intéragis avec le sorcier "
       << hero.getName();
}
} // namespace HE_Arc::RPG