#ifndef INVENTORY_H
#define INVENTORY_H

#include "commands.h"
#include "movies.h"

class Inventory : public Commands {
public:
  void execute(Store &store) override;
  bool read(string &input) override;
  ostream &print(ostream &os) const override;

private:
  char type = 'I';
};

class InventoryFactory : public CommandsFactory {
public:
  InventoryFactory();
  Commands *makeCommands() const override;
};

#endif
