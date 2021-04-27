#include <iostream>
#include <list>
#include <algorithm>

#include "./headers/Hero.h"
#include "./headers/Warrior.h"
#include "./headers/Wizard.h"

using namespace std;
using namespace HE_Arc::RPG;

int main(int argc, char const *argv[])
{
  list<Hero *> party;

  Sword *defaultSword = new Sword(10);
  Hero *ven = new Warrior(20, 20, 20, 20, "ven", defaultSword);
  Hero *clems = new Wizard(20, 20, 20, 20, "clems", defaultSword, 10);
  Hero *jerem = new Warrior(20, 20, 20, 20, "jerem", defaultSword);
  Hero *julien = new Wizard(20, 20, 20, 20, "julien", defaultSword, 15);

  party.push_back(ven);
  party.push_back(clems);
  party.push_back(jerem);
  party.push_back(julien);

  for (auto hero : party)
  {
    cout << hero;
  }

  cout << ven;
  return 0;
}
