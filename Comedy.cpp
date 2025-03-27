#include "Comedy.h"
using namespace std;

// prints movie values in the correct order
ostream &Comedy::print(ostream &os) const {
  os << title << ", " << releaseYear << ", " << director << " (" << stock
     << ") - Comedy";
  return os;
}

// reads necessary input values to create a new movie
bool Comedy::read(string &input) {
  stock = stoi(seperateItem(input));
  director = seperateItem(input);
  title = seperateItem(input);
  releaseYear = stoi(seperateItem(input));
  type = 'F';
  return true;
}

// getter methods
string Comedy::getTitle() const { return title; }
int Comedy::getReleaseYear() const { return releaseYear; }
string Comedy::getDirector() const { return director; };
string Comedy::getActor() const { return ""; };
int Comedy::getReleaseMonth() const { return 0; }
// gets the necessary information to identify a unique movie of this type
pair<string, string> Comedy::getIdentifiable() const {
  string strYear = to_string(releaseYear);
  return {title, strYear};
}

// sorts this type of movie by its unique identifiers
bool Comedy::sort(const Movie *a, const Movie *b) const {

  if (a->getTitle() != b->getTitle()) {
    return a->getTitle() < b->getTitle();
  }
  return a->getReleaseYear() < b->getReleaseYear();
}

// initializes factory
ComedyFactory::ComedyFactory() { registerType('F', this); }

// creates a new movie
Movie *ComedyFactory::makeMovie() const { return new Comedy(); }

ComedyFactory anonymousComedyFactory;