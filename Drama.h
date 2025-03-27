#ifndef DRAMA_H
#define DRAMA_H

#include "movies.h"
#include <vector>

using namespace std;

class Drama : public Movie {
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

class DramaFactory : public MovieFactory {
public:
  DramaFactory();
  Movie *makeMovie() const override;
};

#endif
