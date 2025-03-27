#include "commands.h"

// seperates out items recieved for a command
string Commands::seperateItem(string &str, char delimiter) {
  const char space = ' ';
  str = str.substr(str.find_first_not_of(space));
  size_t pos = str.find(delimiter);
  string item = (pos != string::npos) ? str.substr(0, pos) : str;
  item = item.substr(0, item.find_last_not_of(space) + 1);
  str = (pos != string::npos) ? str.substr(pos + 1) : "";

  return item;
}

// gets hashtable of command factories
HashTable<CommandsFactory> &CommandsFactory::getTable() {
  static HashTable<CommandsFactory> factories;
  return factories;
}

// registers different types of commands
void CommandsFactory::registerType(const char &type, CommandsFactory *factory) {
  getTable().insert(type, factory);
}

// creates different types of commands
Commands *CommandsFactory::create(const char &type) {
  CommandsFactory *currFactory = getTable().get(type);
  if (currFactory == nullptr) {
    cout << "Unknown Command type: " << type;
    return nullptr;
  }
  return currFactory->makeCommands();
}