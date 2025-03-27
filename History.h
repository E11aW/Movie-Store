#ifndef HISTORY_H
#define HISTORY_H

#include "commands.h"

class History : public Commands {
public:
  void execute(Store &store) override;
  bool read(string &input) override;
  ostream &print(ostream &os) const override;

private:
  char type = 'H';
  int customerID;
};

class HistoryFactory : public CommandsFactory {
public:
  HistoryFactory();
  Commands *makeCommands() const override;
};

#endif
