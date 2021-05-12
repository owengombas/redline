#include "../headers/Warrior.h"

#include <iostream>

#include "../headers/Hero.h"
#include "../headers/Sword.h"

using namespace std;

namespace HE_Arc::RPG {
Warrior::Warrior(int strength, int agility, int intelligence, double hp,
                 string name, Sword *sword)
    : Hero(strength, agility, intelligence, hp, name, sword) {}

void Warrior::interact(const Hero &hero) {}
} // namespace HE_Arc::RPG