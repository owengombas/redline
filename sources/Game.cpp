#include "../headers/Game.h"

using namespace std;

namespace HE_Arc::RPG {
void Game::Game::printTitle() {
  cout << "__________.__.__ __________                          "
          "____________________  ________"
       << endl;
  cout << "\\_   _____|__|  |\\______   \\ ____  __ __  ____   ____\\______  "
          " \\______   \\/  _____/ "
       << endl;
  cout << "|    __) |  |  | |       _//  _ \\|  |  \\/ ___\\_/ __ \\|       "
          "_/|     ___/   \\  ___ "
       << endl;
  cout << "|     \\  |  |  |_|    |   (  <_> |  |  / /_/  \\  ___/|    |   "
          "\\|    |   \\    \\_\\  \\"
       << endl;
  cout << "\\___  /  |__|____|____|_  /\\____/|____/\\___  / \\___  |____|_  "
          "/|____|    \\______  /"
       << endl;
  cout << "    \\/                  \\/            /_____/      \\/       "
          "\\/                  \\/ "
       << endl;
}

void Game::setVendors(vector<Vendor *> vendors) { Game::vendors = vendors; }
void Game::setPlayers(vector<Hero *> players) { Game::players = players; }
void Game::setMonsters(vector<Monster *> monsters) {
  Game::monsters = monsters;
}
void Game::setHero(Hero *hero) { Game::hero = hero; }

void Game::updateMenu() {
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
    Game::printVendorBuyMenu();
  } else if (menu == "exchange") {
    Game::printHeroesBuyMenu();
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
    cout << "Menu non trouvé, réessayer" << endl;
    Game::readMenu();
  }
}

void Game::showMenu(int menu) {
  Game::menuTree.push_back(menu);
  updateMenu();
}

void Game::goBack() {
  cout << endl;
  if (Game::menuTree.size() <= 0) {
    cout << "Aurevoir" << endl;
    exit(0);
  }
  Game::menuTree.pop_back();
  Game::updateMenu();
}

void Game::print(string str) { cout << str << endl; }

void Game::separate(int n) {
  for (int i = 0; i < n; i++) {
    cout << endl;
  }
}

void Game::printOptions(string options[], int size) {
  for (unsigned int i = 0; i < size; i++) {
    cout << i << ". " << options[i] << endl;
  }
}

int Game::read() {
  cout << endl;
  int option;
  cin >> option;

  return option;
}

void Game::readMenu() {
  int option = Game::read();

  if (option <= 0) {
    Game::goBack();
  } else {
    Game::showMenu(option);
  }
}

void Game::printRootMenu() {
  cout << "Choisissez parmis les options suivantes: " << endl;
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
  Game::separate();
}

void Game::printBuyMenu(vector<Hero *> heroes) {
  int offset = 1;
  vector<pair<IObject *, Hero *>> objects{};

  int size = heroes.size();

  if (size <= 0) {
    cout << endl
         << "Aucun héro ne vend d'articles pour le moment, retour au menu "
            "principal"
         << endl;
    Game::goBack();
  }

  // Print all the Hero items to sell
  for (int i = 0; i < size; i++) {
    Hero *hero = heroes[i];
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

void Game::printVendorBuyMenu() {
  Game::printBuyMenu(
      vector<Hero *>(Game::vendors.begin(), Game::vendors.end()));
}

void Game::printHeroesBuyMenu() { Game::printBuyMenu(Game::players); }

void Game::printSellMenu() {
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

  cout << endl
       << "Choisissez le numéro de l'item que vous voulez vendre: " << endl;
  int option = Game::verifyOption(size);
  if (option == -1)
    return;
  object = hero->getBackpack()->getItem(option);

  cout << endl << "Vous allez vendre: " << *object << endl;

  // Print all the other heroes to sell
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

void Game::printFightMenu(vector<Attackable *> attackables) {
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
  } else {
    isAttackerDeadStr =
        " (il vous reste " + to_string(Game::hero->getHp()) + "hp)";
  }

  cout << "Vous avez attaqué " << player->getName() << "(" << player->getType()
       << ") et infligé " << attackerDamage << " dégats" << isAttackedDeadStr
       << endl;

  if (!player->isDead()) {
    cout << "Il vous a attaqué en retour et infligé " << attackedDamage
         << " dégats" << isAttackerDeadStr << endl;
  }

  if (Game::hero->isDead()) {
    exit(0);
  }

  Game::goBack();
}

void Game::printChangeWeaponMenu() {
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

void Game::printFightPlayersMenu() {
  Game::printFightMenu(
      vector<Attackable *>(Game::players.begin(), Game::players.end()));
}

void Game::printFightMonstersMenu() {
  Game::printFightMenu(
      vector<Attackable *>(Game::monsters.begin(), Game::monsters.end()));
}

void Game::printChooseItem() {
  cout << "Entrez le numéro de l'article que vous voulez acheter" << endl;
}

void Game::printZero() {
  cout << "Entrez 0 pour retourner au menu principal" << endl;
}

int Game::verifyOption(int size) {
  int option = Game::read() - 1;
  if (option < 0 || option > size - 1) {
    cout << "Saisie incorrecte, retour au menu principal" << endl;
    Game::goBack();
    return -1;
  }
  return option;
}
} // namespace HE_Arc::RPG