#include "Store.h"
using namespace std;

Store::Store() {}

Store::~Store() {
  for (auto movie : movies) {
    delete movie.second;
  }
  for (auto customer : customers) {
    delete customer.second;
  }
}

bool Store::addCustomer(Customer *newCust) {
  if (customers.count(newCust->getID()) != 0) {
    return false;
  }
  customers[newCust->getID()] = newCust;
  return true;
}

bool Store::addMovie(Movie *newMovie) {
  if (movies.count(newMovie->getIdentifiable()) != 0) {
    return false;
  }
  movies[newMovie->getIdentifiable()] = newMovie;
  return true;
}
unordered_map<int, Customer *> &Store::getCustomers() { return customers; }
unordered_map<pair<string, string>, Movie *, Store::PairStringHash> &
Store::getMovies() {
  return movies;
}
