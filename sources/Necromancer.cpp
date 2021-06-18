#include "../headers/Necromancer.h"

using namespace std;

namespace HE_Arc::RPG {
/**
 * Use the "rise undeads" spell
 */
void Necromancer::riseUndeads() {
  if (this->mana >= 2) {
    cout << "Rise Undeads!!!";
  }
}
} // namespace HE_Arc::RPG