#pragma once
#include "Attackable.h"
#include "Hero.h"
#include "IObject.h"
#include <string>

using namespace std;

namespace HE_Arc::RPG {
class Log {
public:
  static void write(string path, string log);
  static void writeTransaction(Hero *seller, Hero *client, IObject *pObject,
                               float price);
  static void writeFight(Attackable *attacker, Attackable *attacked,
                         int damage);
};
} // namespace HE_Arc::RPG
