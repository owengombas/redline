#pragma once
#include <iostream>

using namespace std;

namespace HE_Arc::RPG
{
  class Sword
  {
  public:
    Sword() = default;
    Sword(int damage);
    int getDamage() const { return damage; }

  protected:
    int damage = 10;
  };
} // namespace HE_Arc::RPG
