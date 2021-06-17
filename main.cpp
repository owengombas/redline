#include <algorithm>
#include <iostream>
#include <list>

#include "./headers/Potion.h"
#include "./headers/Shield.h"
#include "./headers/Sword.h"

#include "./headers/Hero.h"
#include "./headers/Necromancer.h"
#include "./headers/Warrior.h"
#include "./headers/Wizard.h"

#include "./headers/PotionVendor.h"
#include "./headers/WeaponVendor.h"

using namespace std;
using namespace HE_Arc::RPG;

/*
Scénario 1 - Trading System

Objectifs généraux:
- Ajouter la possibilité d'acheter et de vendre des objets et obtenir ou
consommer
- de l'Or: de / vers d'autres héros de / vers PNJs (classe Merchant)

Minimal requirements:
- Ajouter 2 classes (types de marchants : ex. potion vendors ou weapon vendors)
- Développer une solution de trading
- Utiliser au moins une exception pour gérer une erreur
- Ajouter un fichier de log pour garder trace de toutes les transactions
- Améliorer la classe "Backpack"
- Utiliser le polymorphisme, la redéfinition et la surcharge des méthodes (y.c.
des opérateurs) Utiliser du code C++ modern (C++11 ou suivants)
*/

int main(int argc, char const *argv[]) {
  list<Hero *> party;

  Sword *defaultSword = new Sword(10);
  Potion *defaultPotion = new Potion(5);
  Shield *defaultShield = new Shield(15);

  Warrior *ven = new Warrior(20, 20, 20, 20, "Owen", defaultSword);
  Wizard *clems = new Wizard(20, 20, 20, 20, "Clement", 10, defaultPotion);
  Warrior *jerem = new Warrior(20, 20, 20, 20, "Jeremy", defaultSword);
  Wizard *julien = new Wizard(20, 20, 20, 20, "Julien", 15, defaultPotion);
  Necromancer *quentin =
      new Necromancer(20, 20, 20, 20, "Quentin", 15, defaultPotion);

  WeaponVendor *martin =
      new WeaponVendor(20, 20, 20, 20, "Martin", 1.9, defaultPotion);
  WeaponVendor *ali =
      new WeaponVendor(20, 20, 20, 20, "Ali", 0.8, defaultPotion);
  PotionVendor *harry =
      new PotionVendor(20, 20, 20, 20, "Harry", 1.4, defaultSword);
  PotionVendor *aria =
      new PotionVendor(20, 20, 20, 20, "Aria", 2.2, defaultSword);

  party.push_back(ven);
  party.push_back(clems);
  party.push_back(jerem);
  party.push_back(julien);
  party.push_back(quentin);
  party.push_back(martin);
  party.push_back(ali);
  party.push_back(harry);
  party.push_back(aria);

  ven->backpack.add(defaultSword->clone());

  ven->sell(ven->backpack.getItem(0), clems);
  martin->sell(martin->backpack.getItem(0), aria);
  ali->sell(ali->backpack.getItem(0), harry);

  for (const Hero *hero : party) {
    cout << *hero << endl;
  }

  return 0;
}
