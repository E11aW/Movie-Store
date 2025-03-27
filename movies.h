#include "HashTable.h"
#include <iostream>

#ifndef MOVIES_H
#define MOVIES_H

using namespace std;

class Movie {
public:
  friend ostream &operator<<(ostream &os, const Movie &m) {
    return m.print(os);
  };
  virtual ~Movie() = default;
  static string seperateItem(string &str, char delimiter = ',');
  static bool movieSort(const Movie *a, const Movie *b);
  virtual bool read(string &input) = 0;
  char getType() const;
  int getStock() const;
  bool increaseStock();
  bool decreaseStock();
  virtual string getTitle() const = 0;
  virtual string getDirector() const = 0;
  virtual string getActor() const = 0;
  virtual int getReleaseYear() const = 0;
  virtual int getReleaseMonth() const = 0;
  virtual pair<string, string> getIdentifiable() const = 0;

protected:
  virtual bool sort(const Movie *a, const Movie *b) const = 0;
  int stock;
  char type;

private:
  virtual ostream &print(ostream &os) const = 0;
};

class MovieFactory {
public:
  virtual Movie *makeMovie() const = 0;
  static Movie *create(const char &type);

protected:
  static void registerType(const char &type, MovieFactory *factory);

private:
  static HashTable<MovieFactory> &getTable();
};

#endif
