#include "History.h"
using namespace std;

// calls the command and executes it
void History::execute(Store &store) {
  auto location = store.getCustomers().find(customerID);
  if (location == store.getCustomers().end()) {
    cout << "Error: customer ID " << customerID << " not found" << endl;
    return;
  }
  Customer *customer = location->second;
  cout << "History for " << *customer << ":" << endl;
  vector<Commands *> customerTransactions = customer->getTransactions();
  if (customerTransactions.empty()) {
    cout << "\tNo history" << endl;
  }
  for (auto &transaction : customerTransactions) {
    cout << "\t" << *transaction << endl;
  }
}

// reads values to initalize a valid command
bool History::read(string &input) {
  customerID = stoi(seperateItem(input));
  return true;
}

// prints out command values (if it has any)
ostream &History::print(ostream &os) const { return os; }

// initializes factory
HistoryFactory::HistoryFactory() { registerType('H', this); }

// creates a new command
Commands *HistoryFactory::makeCommands() const { return new History(); }

HistoryFactory anonymousHistoryFactory;