#ifndef COMMANDS_H
#define COMMANDS_H

#include "HashTable.h"
#include "Store.h"
#include <iostream>
#include <unordered_map>

using namespace std;

class Store;

class Commands {
public:
  friend ostream &operator<<(ostream &os, const Commands &c) {
    return c.print(os);
  };
  virtual ~Commands() = default;
  static string seperateItem(string &str, char delimiter = ' ');
  virtual bool read(string &input) = 0;
  virtual void execute(Store &store) = 0;

private:
  virtual ostream &print(ostream &os) const = 0;
};

class CommandsFactory {
public:
  virtual Commands *makeCommands() const = 0;
  static Commands *create(const char &type);

protected:
  static void registerType(const char &type, CommandsFactory *factory);

private:
  static HashTable<CommandsFactory> &getTable();
};

#endif
