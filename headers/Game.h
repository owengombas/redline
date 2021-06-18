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
  static void printTitle() {
    Game::print("__________.__.__ __________                          "
                "____________________  ________");
    Game::print(
        "\\_   _____|__|  |\\______   \\ ____  __ __  ____   ____\\______  "
        " \\______   \\/  _____/ ");
    Game::print(
        "|    __) |  |  | |       _//  _ \\|  |  \\/ ___\\_/ __ \\|       "
        "_/|     ___/   \\  ___ ");
    Game::print(
        "|     \\  |  |  |_|    |   (  <_> |  |  / /_/  \\  ___/|    |   "
        "\\|    |   \\    \\_\\  \\");
    Game::print(
        "\\___  /  |__|____|____|_  /\\____/|____/\\___  / \\___  |____|_  "
        "/|____|    \\______  /");
    Game::print(
        "    \\/                  \\/            /_____/      \\/       "
        "\\/                  \\/ ");
  }

  static void setVendors(vector<Vendor *> vendors) { Game::vendors = vendors; }
  static void setPlayers(vector<Hero *> players) { Game::players = players; }
  static void setMonsters(vector<Monster *> monsters) {
    Game::monsters = monsters;
  }
  static void setHero(Hero *hero) { Game::hero = hero; }

  static void updateMenu() {
    string menu = "";
    for (const auto &[key, value] : Game::menus) {
      if (menuTree.size() != value.size()) {
        continue;
      }

      if (equal(menuTree.begin(), menuTree.end(), value.begin())) {
        menu = key;
      }
    }

    if (menu == "root") {
      Game::printRootMenu();
      Game::readMenu();
    } else if (menu == "identity") {
      cout << *Game::hero << endl;
      Game::goBack();
    } else if (menu == "buy") {
      Game::printBuyMenu();
    } else if (menu == "exchange") {
      Game::printEchangeMenu();
    } else if (menu == "sell") {
      Game::printSellMenu();
    } else if (menu == "money") {
      cout << "Vous avez " << Game::hero->getMoney() << "$" << endl;
      Game::goBack();
    } else if (menu == "change-weapon") {
      Game::printChangeWeaponMenu();
    } else if (menu == "fight-heroes") {
      Game::printFightPlayersMenu();
    } else if (menu == "fight-monsters") {
      Game::printFightMonstersMenu();
    } else {
      Game::print("Menu non trouvé, réessayer");
      Game::readMenu();
    }
  }

  static void showMenu(int menu) {
    Game::menuTree.push_back(menu);
    updateMenu();
  }

  static void goBack() {
    cout << endl;
    if (Game::menuTree.size() <= 0) {
      cout << "Aurevoir" << endl;
      exit(0);
    }
    Game::menuTree.pop_back();
    Game::updateMenu();
  }

  static void print(string str) { cout << str << endl; }

  static void printHero(Hero *hero) { cout << *hero << endl; }

  static void printHeros(list<Hero *> heros) {
    for (const Hero *hero : heros) {
      cout << *hero << endl;
    }
  }

  static void sperate(int n = 1) {
    for (int i = 0; i < n; i++) {
      cout << endl;
    }
  }

  static void printOptions(string options[], int size) {
    for (unsigned int i = 0; i < size; i++) {
      cout << i << ". " << options[i] << endl;
    }
  }

  static int read() {
    cout << endl;
    int option;
    cin >> option;

    return option;
  }

  static void readMenu() {
    int option = Game::read();

    if (option <= 0) {
      Game::goBack();
    } else {
      Game::showMenu(option);
    }
  }

  static void printRootMenu() {
    Game::print("Choisissez parmis les options suivantes: ");
    string options[] = {"Quitter le programme",
                        "Afficher vos informations",
                        "Acheter des objets à un vendeur",
                        "Acheter des objets à d'autre joueurs",
                        "Vendre vos objets à d'autre joueurs",
                        "Afficher votre solde",
                        "Changer l'arme que vous avez dans vos mains",
                        "Combattre un joueur",
                        "Combattre un Monstre"};
    Game::printOptions(options, 9);
    Game::sperate();
  }

  static void printHeroMenu(vector<Hero *> heros) {
    int offset = 1;
    vector<pair<IObject *, Hero *>> objects{};

    // Print all the Hero items to sell
    for (int i = 0; i < heros.size(); i++) {
      Hero *hero = heros[i];
      int size = hero->getBackpack()->getItems().size();

      if (size <= 0) {
        continue;
      }

      cout << hero->getType() << ": " << hero->getName() << endl;
      for (int j = 0; j < size; j++) {
        IObject *object = hero->getBackpack()->getItem(j);
        cout << offset + j << ". " << object->getPrice() << "$ " << *object
             << endl;

        objects.push_back(pair(object, hero));
      }
      offset += size;
      cout << endl;
    }

    // Print the guide
    Game::printChooseItem();
    Game::printZero();

    // Execute the sell action
    int option = Game::read() - 1;
    if (option < 0 || option > objects.size() - 1) {
      Game::goBack();
      return;
    }

    pair<IObject *, Hero *> objectVendor = objects[option];

    try {
      objectVendor.second->sell(objectVendor.first, Game::hero);

      cout << "Vous avez acheter " << *objectVendor.first << " à "
           << objectVendor.second->getName() << " pour "
           << objectVendor.first->getPrice() << "$" << endl
           << "Il vous reste " << Game::hero->getMoney() << "$" << endl;
    } catch (exception &e) {
      cout << "Vous n'avez pas assez d'argent pour acheter "
           << *objectVendor.first << " à " << objectVendor.second->getName()
           << endl;
    }

    Game::goBack();
  }

  static void printBuyMenu() {
    Game::printHeroMenu(
        vector<Hero *>(Game::vendors.begin(), Game::vendors.end()));
  }

  static void printEchangeMenu() { Game::printHeroMenu(Game::players); }

  static void printSellMenu() {
    IObject *object = 0;
    Hero *player = 0;

    int size = hero->getBackpack()->getItems().size();

    if (size <= 0) {
      cout << endl
           << "Vous n'avez aucun objet à vendre, retour au menu principal"
           << endl;
      Game::goBack();
    }

    // Print hero's item list
    for (int i = 0; i < size; i++) {
      IObject *object = hero->getBackpack()->getItem(i);
      cout << i + 1 << ". " << object->getPrice() << "$ " << *object << endl;
    }

    int option = Game::verifyOption(size);
    if (option == -1)
      return;
    object = hero->getBackpack()->getItem(option);

    cout << endl << "Vous allez vendre: " << *object << endl;

    // Print all the other heros to sell
    size = Game::players.size();
    for (int i = 0; i < size; i++) {
      Hero *player = Game::players[i];
      cout << i + 1 << ". " << player->getName() << "(" << player->getType()
           << ")" << endl;
    }

    // Sell the item
    option = Game::verifyOption(size);
    if (option == -1)
      return;
    player = Game::players[option];

    Game::hero->sell(object, player);

    cout << "Vous avez vendu " << *object << " à " << player->getName()
         << " pour " << object->getPrice() << "$" << endl
         << "Vous avez " << Game::hero->getMoney() << "$" << endl;

    Game::goBack();
  }

  static void printFightMenu(vector<Attackable *> attackables) {
    int attackerDamage = Game::hero->getAttackDamage();
    int attackerHp = Game::hero->getHp();

    cout << "Vous avez " << attackerHp << " et vous attaquez avec "
         << attackerDamage << " point de dégats" << endl;

    vector<Attackable *> notDeadPlayers{};
    for (Attackable *player : attackables) {
      if (!player->isDead()) {
        notDeadPlayers.push_back(player);
      }
    }

    Attackable *player = 0;
    int size = notDeadPlayers.size();
    for (int i = 0; i < size; i++) {
      Attackable *player = notDeadPlayers[i];

      string willDieStr = "";

      int attackedDamage = player->getAttackDamage();
      int attackedHp = player->getHp();

      if (attackedDamage >= attackerHp) {
        willDieStr =
            " (Si vous l'attaquer vous allez mourir car il vous infligera " +
            to_string(attackedDamage) + " dégats)";
      }

      if (attackedHp <= attackerDamage) {
        willDieStr = "";
      }

      cout << i + 1 << ". " << player->getName() << "(" << player->getType()
           << ")"
           << " hp: " << player->getHp() << " | attack: " << attackedDamage
           << willDieStr << endl;
    }

    cout << endl
         << "Choisissez le numéro de l'entité que vous voulez attaquer" << endl;
    Game::printZero();

    int option = Game::verifyOption(size);
    if (option == -1)
      return;
    player = notDeadPlayers[option];

    Game::hero->attack(player);

    int attackedDamage = player->getAttackDamage();
    int attackedHp = player->getHp();

    string isAttackedDeadStr = "";
    string isAttackerDeadStr = "";

    if (player->isDead()) {
      isAttackedDeadStr = ", il a succombé à ses blessures...";
    } else {
      player->attack(Game::hero);
    }

    if (Game::hero->isDead()) {
      isAttackerDeadStr = ", vous avez succombé à vos blessures... Aurevoir";
    }

    cout << "Vous avez attaqué " << player->getName() << "("
         << player->getType() << ") et infligé " << attackerDamage << " dégats"
         << isAttackedDeadStr << endl;

    if (!player->isDead()) {
      cout << "Il vous a attaqué en retour et infligé " << attackedDamage
           << " dégats" << isAttackerDeadStr << ", il vous reste "
           << Game::hero->getHp() << "hp" << endl;
    }

    if (Game::hero->isDead()) {
      exit(0);
    }

    Game::goBack();
  }

  static void printChangeWeaponMenu() {
    int size = Game::hero->getBackpack()->getItems().size();

    cout << endl
         << "Choisissez parmis les items présent dans votre backpack: " << endl;
    for (int i = 0; i < size; i++) {
      IObject *object = Game::hero->getBackpack()->getItem(i);
      cout << i + 1 << ". " << *object << endl;
    }

    int option = Game::verifyOption(size);
    if (option == -1)
      return;
    IObject *object = Game::hero->getBackpack()->getItem(option);

    Game::hero->setObject(object);

    cout << "Vous avez dans vos mains " << *(Game::hero->getObject())
         << ", vous infligez maintenant " << Game::hero->getAttackDamage()
         << " dégats" << endl;

    Game::goBack();
  }

  static void printFightPlayersMenu() {
    Game::printFightMenu(
        vector<Attackable *>(Game::players.begin(), Game::players.end()));
  }

  static void printFightMonstersMenu() {
    Game::printFightMenu(
        vector<Attackable *>(Game::monsters.begin(), Game::monsters.end()));
  }

  static void printChooseItem() {
    cout << "Entrez le numéro de l'article que vous voulez acheter" << endl;
  }

  static void printZero() {
    cout << "Entrez 0 pour retourner au menu principal" << endl;
  }

  static int verifyOption(int size) {
    int option = Game::read() - 1;
    if (option < 0 || option > size - 1) {
      cout << "Saisie incorrecte, retour au menu principal" << endl;
      Game::goBack();
      return -1;
    }
    return option;
  }
};
} // namespace HE_Arc::RPG
