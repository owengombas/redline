#include <iostream>

#include "./headers/Hero.h"

using namespace std;
using namespace HE_Arc::RPG;

int main(int argc, char const *argv[]) {
  Hero ven = Hero(20, 20, 20, 20, "ven");
  Hero clems = Hero(20, 20, 20, 20, "clems");
  cout << ven;
  return 0;
}
