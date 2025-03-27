#include "movies.h"
#include <vector>

#ifndef CLASSICS_H
#define CLASSICS_H

using namespace std;

class Classics : public Movie {
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
  string actor;
  int releaseYear;
  int releaseMonth;
};

class ClassicsFactory : public MovieFactory {
public:
  ClassicsFactory();
  Movie *makeMovie() const override;
};

#endif
