#include <iostream>

#include "../headers/Log.h"

using namespace std;

namespace HE_Arc::RPG {
void Log::write(string path, string log) {
  ofstream stream = ofstream(path, ios_base::app);

  time_t now = time(0);
  char *dt = ctime(&now);

  stream << "==================" << endl;
  stream << dt << endl;
  stream << log << endl;
  stream << "==================" << endl;
  stream << endl;

  stream.close();
}

void Log::writeTransaction(Hero *seller, Hero *client, IObject *pObject,
                           float price) {
  Log::write("transactions.log",
             seller->getName() + "(" + seller->getType() + ") sold " +
                 pObject->getName() + "(" + to_string(pObject->getFeature()) +
                 ") to " + client->getName() + "(" + client->getType() + ")" +
                 " for " + to_string(price) + "$");
}
} // namespace HE_Arc::RPG
