#pragma once
#include "Hero.h"
#include "IObject.h"
#include "Monster.h"
#include "Vendor.h"
#include <algorithm>
#include <iostream>
#include <list>
#include <map>
#include <stack>
#include <string>
#include <utility>

using namespace std;

namespace HE_Arc::RPG {
/**
 * The class manage the menu and the navigation between actions
 * It works with an arborescence system
 * each menu correspond to a vector and a name
 * So with this system we can easily implement a sub-menu program
 *
 * root {}
 * ├── buy {1}
 * │   ├── buy-sub-menu {1, 1}
 * │   ├── ... {1, x}
 * ├── exchange {2}
 * │   ├── ... {2, x}
 * └── sell {3}
 *     └── ... {3, x}
 */
class Game {
private:
  static inline vector<Vendor *> vendors{};
  static inline vector<Hero *> players{};
  static inline vector<Monster *> monsters{};
  static inline Hero *hero;

  static inline vector<int> menuTree{};
  static inline map<string, vector<int>> menus{
      {"root", {}},           {"identity", {1}},     {"buy", {2}},
      {"exchange", {3}},      {"sell", {4}},         {"money", {5}},
      {"change-weapon", {6}}, {"fight-heroes", {7}}, {"fight-monsters", {8}}};

public:
  static void setVendors(vector<Vendor *> vendors);
  static void setPlayers(vector<Hero *> players);
  static void setMonsters(vector<Monster *> monsters);
  static void setHero(Hero *hero);

  static void updateMenu();
  static void showMenu(int menu);
  static void goBack();

  static int read();
  static void readMenu();
  static int verifyOption(int size);

  static void printTitle();
  static void print(string str);
  static void separate(int n = 1);
  static void printOptions(string options[], int size);

  static void printFightPlayersMenu();
  static void printFightMonstersMenu();
  static void printChooseItem();
  static void printZero();
  static void printRootMenu();
  static void printHeroMenu(vector<Hero *> heros);
  static void printBuyMenu();
  static void printExchangeMenu();
  static void printSellMenu();
  static void printChangeWeaponMenu();
  static void printFightMenu(vector<Attackable *> attackables);
};
} // namespace HE_Arc::RPG
