#ifndef STORE_H
#define STORE_H

#include "Customer.h"
#include "movies.h"
#include <unordered_map>

using namespace std;

class Customer;

class Store {
public:
  struct PairStringHash {
    std::size_t operator()(const std::pair<string, string> &p) const {
      return hash<string>{}(p.first) ^ hash<string>{}(p.second);
    }
  };

  Store();
  bool addCustomer(Customer *newCust);
  bool addMovie(Movie *newMovie);
  unordered_map<int, Customer *> &getCustomers();
  unordered_map<pair<string, string>, Movie *, Store::PairStringHash> &
  getMovies();
  ~Store();

private:
  unordered_map<int, Customer *> customers;
  unordered_map<pair<string, string>, Movie *, PairStringHash> movies;
};

#endif
