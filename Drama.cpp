#include "Drama.h"
using namespace std;

// prints movie values in the correct order
ostream &Drama::print(ostream &os) const {
  os << title << ", " << releaseYear << ", " << director << " (" << stock
     << ") - Drama";
  return os;
}

// reads necessary input values to create a new movie
bool Drama::read(string &input) {
  stock = stoi(seperateItem(input));
  director = seperateItem(input);
  title = seperateItem(input);
  releaseYear = stoi(seperateItem(input));
  type = 'D';
  return true;
}

// getter methods
string Drama::getDirector() const { return director; }
string Drama::getTitle() const { return title; }
string Drama::getActor() const { return ""; }
int Drama::getReleaseYear() const { return releaseYear; };
int Drama::getReleaseMonth() const { return 0; }
// gets the necessary information to identify a unique movie of this type
pair<string, string> Drama::getIdentifiable() const {
  return {director, title};
}

// sorts this type of movie by its unique identifiers
bool Drama::sort(const Movie *a, const Movie *b) const {
  if (a->getDirector() != b->getDirector()) {
    return a->getDirector() < b->getDirector();
  }
  return a->getTitle() < b->getTitle();
}

// initializes factory
DramaFactory::DramaFactory() { registerType('D', this); }

// creates a new movie
Movie *DramaFactory::makeMovie() const { return new Drama(); }

DramaFactory anonymousDramaFactory;