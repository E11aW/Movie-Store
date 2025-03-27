#include "Classics.h"
using namespace std;

// prints movie values in the correct order
ostream &Classics::print(ostream &os) const {
  os << releaseYear << " " << releaseMonth << ", " << actor << ", " << director
     << ", " << title << " (" << stock << ") - Classics";
  return os;
}

// reads necessary input values to create a new movie
bool Classics::read(string &input) {
  stock = stoi(seperateItem(input));
  director = seperateItem(input);
  title = seperateItem(input);
  string aFirstName = seperateItem(input, ' ');
  string aLastName = seperateItem(input, ' ');
  actor = aFirstName + " " + aLastName;
  releaseMonth = stoi(seperateItem(input, ' '));
  releaseYear = stoi(seperateItem(input));
  type = 'C';
  return true;
}

// getter methods
string Classics::getActor() const { return actor; }
string Classics::getTitle() const { return title; }
string Classics::getDirector() const { return director; }
int Classics::getReleaseYear() const { return releaseYear; }
int Classics::getReleaseMonth() const { return releaseMonth; }
// gets the necessary information to identify a unique movie of this type
pair<string, string> Classics::getIdentifiable() const {
  string strRelease = to_string(releaseMonth) + " " + to_string(releaseYear);
  return {strRelease, actor};
}

// sorts this type of movie by its unique identifiers
bool Classics::sort(const Movie *a, const Movie *b) const {
  if (a->getReleaseYear() != b->getReleaseYear()) {
    return a->getReleaseYear() < b->getReleaseYear();
  }
  if (a->getReleaseMonth() != b->getReleaseMonth()) {
    return a->getReleaseMonth() < b->getReleaseMonth();
  }
  return a->getActor() < b->getActor();
}

// initializes factory
ClassicsFactory::ClassicsFactory() { registerType('C', this); }

// creates a new movie
Movie *ClassicsFactory::makeMovie() const { return new Classics(); }

ClassicsFactory anonymousClassicsFactory;