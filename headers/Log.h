#pragma once
#include <ctime>
#include <fstream>
#include <iostream>

#include "Hero.h"
#include "IObject.h"

using namespace std;

namespace HE_Arc::RPG {
class Log {
public:
  static void write(string path, string log);
  static void writeTransaction(Hero *seller, Hero *client, IObject *pObject,
                               float price);
};
} // namespace HE_Arc::RPG
