#include "Inventory.h"
#include <algorithm>
using namespace std;

// calls the command and executes it
void Inventory::execute(Store &store) {
  vector<Movie *> currMovies;
  for (auto &movie : store.getMovies()) {
    currMovies.push_back(movie.second);
  }
  sort(currMovies.begin(), currMovies.end(), Movie::movieSort);
  for (Movie *&movie : currMovies) {
    cout << *movie << endl;
  }
}

// reads values to initalize a valid command
bool Inventory::read(string &input) {
  input = "";
  return true;
}

// prints out command values (if it has any)
ostream &Inventory::print(ostream &os) const { return os; }

// initializes factory
InventoryFactory::InventoryFactory() { registerType('I', this); }

// creates a new command
Commands *InventoryFactory::makeCommands() const { return new Inventory(); }

InventoryFactory anonymousInventoryFactory;