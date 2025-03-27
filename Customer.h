#ifndef CUSTOMER_H
#define CUSTOMER_H

#include "commands.h"
#include <iostream>
#include <set>
#include <string>
#include <vector>

using namespace std;

class Commands;

class Customer {
public:
  Customer();
  ~Customer();
  friend ostream &operator<<(ostream &os, const Customer &cust);
  bool read(string &input);
  static string seperateItem(string &str, char delimiter = ' ');
  int getID() const;
  void addTransaction(Commands *transaction);
  vector<Commands *> getTransactions() const;
  void checkoutMovie(pair<string, string> movieIdentifiables);
  bool checkinMovie(pair<string, string> movieIdentifiables);

private:
  int id;
  string firstName;
  string lastName;
  set<pair<string, string>> outMovies;
  vector<Commands *> transactions;
};

#endif
