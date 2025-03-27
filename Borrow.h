#ifndef BORROW_H
#define BORROW_H

#include "commands.h"
#include "movies.h"

class Borrow : public Commands {
public:
  void execute(Store &store) override;
  bool read(string &input) override;
  ostream &print(ostream &os) const override;

private:
  char type = 'B';
  int customerID;
  char mediaType;
  char movieType;
  string identifiable1;
  string identifiable2;
};

class BorrowFactory : public CommandsFactory {
public:
  BorrowFactory();
  Commands *makeCommands() const override;
};

#endif
