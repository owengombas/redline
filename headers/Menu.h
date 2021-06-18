#pragma once
#include <algorithm>
#include <iostream>
#include <list>
#include <map>
#include <stack>
#include <utility>

#include "Hero.h"
#include "IObject.h"
#include "Vendor.h"

using namespace std;

namespace HE_Arc::RPG {
/**
 * The class manage the menu and the navigation between actions
 */
class Menu {
private:
  static inline vector<Vendor *> vendors{};
  static inline vector<Hero *> players{};
  static inline Hero *hero;

  static inline vector<int> menuTree{};
  static inline map<string, vector<int>> menus{
      {"root", {}},  {"buy", {1}},   {"exchange", {2}},
      {"sell", {3}}, {"money", {4}}, {"fight", {5}}};

public:
  static void printTitle() {
    Menu::print("__________.__.__ __________                          "
                "____________________  ________");
    Menu::print(
        "\\_   _____|__|  |\\______   \\ ____  __ __  ____   ____\\______  "
        " \\______   \\/  _____/ ");
    Menu::print(
        "|    __) |  |  | |       _//  _ \\|  |  \\/ ___\\_/ __ \\|       "
        "_/|     ___/   \\  ___ ");
    Menu::print(
        "|     \\  |  |  |_|    |   (  <_> |  |  / /_/  \\  ___/|    |   "
        "\\|    |   \\    \\_\\  \\");
    Menu::print(
        "\\___  /  |__|____|____|_  /\\____/|____/\\___  / \\___  |____|_  "
        "/|____|    \\______  /");
    Menu::print(
        "    \\/                  \\/            /_____/      \\/       "
        "\\/                  \\/ ");
  }

  static void setVendors(vector<Vendor *> vendors) { Menu::vendors = vendors; }
  static void setPlayers(vector<Hero *> players) { Menu::players = players; }
  static void setHero(Hero *hero) { Menu::hero = hero; }

  static void updateMenu() {
    string menu = "";
    for (const auto &[key, value] : Menu::menus) {
      if (menuTree.size() != value.size()) {
        continue;
      }

      if (equal(menuTree.begin(), menuTree.end(), value.begin())) {
        menu = key;
      }
    }

    if (menu == "root") {
      Menu::printRootMenu();
      Menu::readMenu();
    } else if (menu == "buy") {
      Menu::printBuyMenu();
    } else if (menu == "exchange") {
      Menu::printEchangeMenu();
    } else if (menu == "sell") {
      Menu::printSellMenu();
    } else if (menu == "money") {
      cout << "Vous avez " << Menu::hero->getMoney() << "$" << endl;
      Menu::goBack();
    } else if (menu == "fight") {
      Menu::print("Attaquer");
    } else {
      Menu::print("Menu non trouvé, réessayer");
      Menu::readMenu();
    }
  }

  static void showMenu(int menu) {
    Menu::menuTree.push_back(menu);
    updateMenu();
  }

  static void goBack() {
    cout << endl;
    if (Menu::menuTree.size() <= 0) {
      cout << "Aurevoir" << endl;
      exit(0);
    }
    Menu::menuTree.pop_back();
    Menu::updateMenu();
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
    int option = Menu::read();

    if (option <= 0) {
      Menu::goBack();
    } else {
      Menu::showMenu(option);
    }
  }

  static void printRootMenu() {
    Menu::print("Choisissez parmis les options suivantes: ");
    string options[] = {"Quitter le programme",
                        "Acheter des objets à un vendeur",
                        "Acheter des objets à d'autre joueurs",
                        "Vendre vos objets à d'autre joueurs",
                        "Afficher votre solde",
                        "Combattre"};
    Menu::printOptions(options, 6);
    Menu::sperate();
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
    Menu::printChooseItem();
    Menu::printZero();

    // Execute the sell action
    int option = Menu::read() - 1;
    if (option < 0 || option > objects.size() - 1) {
      Menu::goBack();
      return;
    }

    pair<IObject *, Hero *> objectVendor = objects[option];

    try {
      objectVendor.second->sell(objectVendor.first, Menu::hero);

      cout << "Vous avez acheter " << *objectVendor.first << " à "
           << objectVendor.second->getName() << " pour "
           << objectVendor.first->getPrice() << "$" << endl
           << "Il vous reste " << Menu::hero->getMoney() << "$" << endl;
    } catch (exception &e) {
      cout << "Vous n'avez pas assez d'argent pour acheter "
           << *objectVendor.first << " à " << objectVendor.second->getName()
           << endl;
    }
  }

  static void printBuyMenu() {
    Menu::printHeroMenu(
        vector<Hero *>(Menu::vendors.begin(), Menu::vendors.end()));
    Menu::goBack();
  }

  static void printEchangeMenu() {
    Menu::printHeroMenu(Menu::players);
    Menu::goBack();
  }

  static void printSellMenu() {
    IObject *object = 0;
    Hero *player = 0;

    int size = hero->getBackpack()->getItems().size();

    if (size <= 0) {
      cout << endl
           << "Vous n'avez aucun objet à vendre, retour au menu principal"
           << endl;
      Menu::goBack();
    }

    // Print hero's item list
    for (int i = 0; i < size; i++) {
      IObject *object = hero->getBackpack()->getItem(i);
      cout << i + 1 << ". " << object->getPrice() << "$ " << *object << endl;
    }

    int option = Menu::verifyOption(size);
    if (option == -1)
      return;
    object = hero->getBackpack()->getItem(option);

    cout << endl << "Vous allez vendre: " << *object << endl;

    // Print all the other heros to sell
    size = Menu::players.size();
    for (int i = 0; i < size; i++) {
      Hero *player = Menu::players[i];
      cout << i + 1 << ". " << player->getName() << "(" << player->getType()
           << ")" << endl;
    }

    // Sell the item
    option = Menu::verifyOption(size);
    if (option == -1)
      return;
    player = Menu::players[option];

    Menu::hero->sell(object, player);

    cout << "Vous avez vendu " << *object << " à " << player->getName()
         << " pour " << object->getPrice() << "$" << endl
         << "Vous avez " << Menu::hero->getMoney() << "$" << endl;

    Menu::goBack();
  }

  static void printChooseItem() {
    cout << "Entrez le numéro de l'article que vous voulez acheter" << endl;
  }
  static void printZero() { cout << "Entrez 0 pour faire retour" << endl; }

  static int verifyOption(int size) {
    int option = Menu::read() - 1;
    if (option < 0 || option > size - 1) {
      cout << "Saisie incorrecte, retour au menu principal" << endl;
      Menu::goBack();
      return -1;
    }
    return option;
  }
};
} // namespace HE_Arc::RPG
