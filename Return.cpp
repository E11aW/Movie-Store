#include "Return.h"
#include <algorithm>
using namespace std;

// calls the command and executes it
void Return::execute(Store &store) {
  pair<string, string> identifiables = {identifiable1, identifiable2};
  Customer *customer = store.getCustomers()[customerID];
  if (customer == nullptr) {
    cout << "Error: customer ID " << customerID << " not found" << endl;
    return;
  }
  if (store.getMovies().count(identifiables) != 0) {
    if (customer->checkinMovie(identifiables)) {
      customer->addTransaction(new Return(*this));
      return;
    }
    cout << "Customer did not check out the movie: " << identifiable1 << " "
         << identifiable2 << endl;
    return;
  }
  cout << "Store does not contain movie: " << identifiable1 << " "
       << identifiable2 << endl;
}

// reads values to initalize a valid command
bool Return::read(string &input) {
  customerID = stoi(seperateItem(input));
  mediaType = seperateItem(input)[0];
  if (mediaType != 'D') {
    cout << "Unrecognized media type: " << mediaType
         << ", discarding line: " << input;
    return false;
  }
  movieType = seperateItem(input)[0];
  if (isdigit(input[0]) != 0) {
    string num1 = seperateItem(input);
    string num2 = seperateItem(input);
    identifiable1 = num1 + " " + num2;
  } else {
    identifiable1 = seperateItem(input, ',');
  }
  identifiable2 = seperateItem(input, ',');
  return true;
}

// prints out command values (if it has any)
ostream &Return::print(ostream &os) const {
  os << "Returned movie: " << identifiable1 << ", " << identifiable2;
  return os;
}

// initializes factory
ReturnFactory::ReturnFactory() { registerType('R', this); }

// creates a new command
Commands *ReturnFactory::makeCommands() const { return new Return(); }

ReturnFactory anonymousReturnFactory;