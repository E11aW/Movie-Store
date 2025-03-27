#include "Customer.h"
#include <iostream>

Customer::Customer() {}

Customer::~Customer() {
  for (auto *transaction : transactions) {
    delete transaction;
  }
}

// prints out customer information
ostream &operator<<(ostream &os, const Customer &cust) {
  os << cust.id << " " << cust.lastName << " " << cust.firstName;
  return os;
}

// reads customer information from the file
bool Customer::read(string &input) {
  id = stoi(seperateItem(input));
  lastName = seperateItem(input);
  firstName = seperateItem(input);
  return true;
}

// seperates out items recieved for a customer
string Customer::seperateItem(string &str, char delimiter) {
  const char space = ' ';
  str = str.substr(str.find_first_not_of(space));
  size_t pos = str.find(delimiter);
  string item = (pos != string::npos) ? str.substr(0, pos) : str;
  item = item.substr(0, item.find_last_not_of(space) + 1);
  str = (pos != string::npos) ? str.substr(pos + 1) : "";

  return item;
}

// gets customerID
int Customer::getID() const { return id; }

// adds a new transaction to the customer's list of transactions
void Customer::addTransaction(Commands *transaction) {
  transactions.push_back(transaction);
}
// gets a list of all customer transactions
vector<Commands *> Customer::getTransactions() const { return transactions; }

// adds a new movie to the customer's list of checked out movies
void Customer::checkoutMovie(pair<string, string> movieIdentifiables) {
  outMovies.insert(movieIdentifiables);
}
// checks in a movie from the customer's list of checked out movies
bool Customer::checkinMovie(pair<string, string> movieIdentifiables) {
  if (outMovies.count(movieIdentifiables) != 0) {
    outMovies.erase(movieIdentifiables);
    return true;
  }
  return false;
}