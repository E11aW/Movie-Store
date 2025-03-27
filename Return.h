#ifndef RETURN_H
#define RETURN_H

#include "commands.h"
#include "movies.h"

class Return : public Commands {
public:
  void execute(Store &store) override;
  bool read(string &input) override;
  ostream &print(ostream &os) const override;

private:
  char type = 'R';
  int customerID;
  char mediaType;
  char movieType;
  string identifiable1;
  string identifiable2;
};

class ReturnFactory : public CommandsFactory {
public:
  ReturnFactory();
  Commands *makeCommands() const override;
};

#endif
