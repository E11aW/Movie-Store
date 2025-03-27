#include "movies.h"
#include <vector>

#ifndef COMEDY_H
#define COMEDY_H

using namespace std;

class Comedy : public Movie {
public:
  ostream &print(ostream &os) const override;
  bool read(string &input) override;
  bool sort(const Movie *a, const Movie *b) const override;
  string getTitle() const override;
  string getDirector() const override;
  string getActor() const override;
  int getReleaseYear() const override;
  int getReleaseMonth() const override;
  pair<string, string> getIdentifiable() const override;

private:
  string director;
  string title;
  int releaseYear;
};

class ComedyFactory : public MovieFactory {
public:
  ComedyFactory();
  Movie *makeMovie() const override;
};

#endif
