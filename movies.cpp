#include "movies.h"
#include <iostream>
#include <vector>
using namespace std;

// seperates out items recieved for a movie
string Movie::seperateItem(string &str, char delimiter) {
  const char space = ' ';
  str = str.substr(str.find_first_not_of(space));
  size_t pos = str.find(delimiter);
  string item = (pos != string::npos) ? str.substr(0, pos) : str;
  item = item.substr(0, item.find_last_not_of(space) + 1);
  str = (pos != string::npos) ? str.substr(pos + 1) : "";

  return item;
}

// sorts movies based on their type and overridden type-based sort function
bool Movie::movieSort(const Movie *a, const Movie *b) {
  if (a->getType() != b->getType()) {
    return a->getType() > b->getType();
  }
  return a->sort(a, b);
}

// gets hashtable of command factories
HashTable<MovieFactory> &MovieFactory::getTable() {
  static HashTable<MovieFactory> factories;
  return factories;
}

// registers different types of movies
void MovieFactory::registerType(const char &type, MovieFactory *factory) {
  getTable().insert(type, factory);
}

// creates different types of movies
Movie *MovieFactory::create(const char &type) {
  MovieFactory *currFactory = getTable().get(type);
  if (currFactory == nullptr) {
    cout << "Unknown movie type: " << type;
    return nullptr;
  }
  return currFactory->makeMovie();
}

// getter methods
char Movie::getType() const { return type; }
int Movie::getStock() const { return stock; }
// increases and decreases the stock of any given movie, validating request
bool Movie::increaseStock() {
  stock++;
  return true;
}
bool Movie::decreaseStock() {
  if (stock <= 0) {
    return false;
  }
  stock--;
  return true;
}