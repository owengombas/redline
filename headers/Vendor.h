#pragma once
#include "Hero.h"
#include "Sword.h"
#include <iostream>

using namespace std;

/*
Scénario 1 - Trading System

Objectifs généraux:
- Ajouter la possibilité d'acheter et de vendre des objets et obtenir ou
consommer
- de l'Or: de / vers d'autres héros de / vers PNJs (classe Merchant)

Minimal requirements:
- Ajouter 2 classes (types de marchants : ex. potion vendors ou weapon vendors)
Développer une solution de trading
- Utiliser au moins une exception pour gérer une erreur
- Ajouter un fichier de log pour garder trace de toutes les transactions
Améliorer la classe "Backpack"
- Utiliser le polymorphisme, la redéfinition et la surcharge des méthodes (y.c.
des opérateurs) Utiliser du code C++ modern (C++11 ou suivants)
*/

namespace HE_Arc::RPG {
class Vendor : public Hero {
public:
  Vendor(int strength = 10, int agility = 5, int intelligence = 1,
         double hp = 20, string name = "unknown vendor",
         IObject *pObject = new Sword())
      : Hero(strength, agility, intelligence, hp, name, pObject) {}

  virtual void sell(IObject *pObject) = 0;

  virtual void buy(IObject *pObject) = 0;

  void interact(const Hero &hero) override;
};
} // namespace HE_Arc::RPG
