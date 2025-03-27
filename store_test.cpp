/**
 * Testing ass4 movie store functions
 *
 * @author Yusuf Pisan
 * @date 19 Jan 2019
 */

#include <algorithm>
#include <cassert>
#include <fstream>
#include <iostream>
#include <sstream>
#include <vector>

#include "Customer.h"
#include "Store.h"
#include "commands.h"
#include "movies.h"
#include <unordered_map>
using namespace std;

void testStore1() {
  cout << "Start testStore1" << endl;
  // Should do something more, but lets just read files
  // since each implementation will
  string cfile = "testcommands-1.txt";
  stringstream out;
  ifstream fs(cfile);
  assert(fs.is_open());
  char commandType;
  string discard;
  while (fs >> commandType) {
    out << commandType;
    getline(fs, discard);
  }
  fs.close();
  string result = "IHHBRIBBIH";
  assert(out.str() == result);
  cout << "End testStore1" << endl;
}

void testStore2() {
  cout << "Start testStore2" << endl;
  vector<Movie *> movies;
  string cfile = "data4movies.txt";
  ifstream fs(cfile);
  assert(fs.is_open());
  string line;
  while (getline(fs, line) && !line.empty()) {
    Movie *movie = MovieFactory::create(line[0]);
    line = line.substr(3);
    if (movie != nullptr) {
      movie->read(line);
      movies.push_back(movie);
    } else {
      cout << ", discarding line: " << line << endl;
    }
  }
  fs.close();
  cout << "=====================================" << endl;
  sort(movies.begin(), movies.end(), Movie::movieSort);
  for (auto &movie : movies) {
    cout << *movie << endl;
    delete movie;
  }
  cout << "End testStore2" << endl;
}

void testCustomers() {
  cout << "Start testCustomers" << endl;
  vector<Customer *> customers;
  string cfile = "data4customers.txt";
  ifstream fs(cfile);
  assert(fs.is_open());
  string line;
  while (getline(fs, line) && !line.empty()) {
    Customer *curr = new Customer();
    curr->read(line);
    customers.push_back(curr);
  }
  fs.close();
  for (const auto &customer : customers) {
    cout << *customer << endl;
    delete customer;
  }
  cout << "End testCustomers" << endl;
}

void testCommands() {
  cout << "Start testCommands" << endl;
  unordered_map<int, Customer *> customers;
  string cfile = "data4customers.txt";
  ifstream fs(cfile);
  assert(fs.is_open());
  string line;
  while (getline(fs, line) && !line.empty()) {
    Customer *curr = new Customer();
    curr->read(line);
    customers[curr->getID()] = curr;
  }
  vector<Commands *> commands;
  string seefile = "data4commands.txt";
  ifstream fsee(seefile);
  assert(fsee.is_open());
  line = "";
  while (getline(fsee, line) && !line.empty()) {
    Commands *command = CommandsFactory::create(line[0]);
    line = line.substr(1);
    if (command != nullptr) {
      command->read(line);
      commands.push_back(command);
    } else {
      cout << ", discarding line: " << line << endl;
    }
  }
  fsee.close();
  // for (auto &command : commands) {
  //   command->execute();
  //   delete command;
  // }
  cout << "End testCommands" << endl;
}

void testStoreFinal() {
  cout << "=====================================" << endl;
  cout << "Start testStoreFinal" << endl;
  Store store;
  // read all customers from the file
  string cfile = "data4customers.txt";
  ifstream cuf(cfile);
  assert(cuf.is_open());
  string line;
  while (getline(cuf, line) && !line.empty()) {
    Customer *curr = new Customer();
    curr->read(line);
    store.addCustomer(curr);
  }
  cuf.close();
  // read all movies from the file
  cfile = "data4movies.txt";
  ifstream mf(cfile);
  assert(mf.is_open());
  line = "";
  while (getline(mf, line) && !line.empty()) {
    Movie *movie = MovieFactory::create(line[0]);
    line = line.substr(3);
    if (movie != nullptr) {
      movie->read(line);
      store.addMovie(movie);
    } else {
      cout << ", discarding line: " << line << endl;
    }
  }
  mf.close();
  // execute all commands from the file
  vector<Commands *> commands;
  cfile = "data4commands.txt";
  ifstream cof(cfile);
  assert(cof.is_open());
  line = "";
  while (getline(cof, line) && !line.empty()) {
    Commands *command = CommandsFactory::create(line[0]);
    line = line.substr(1);
    if (command != nullptr) {
      command->read(line);
      commands.push_back(command);
    } else {
      cout << ", discarding line: " << line << endl;
    }
  }
  cof.close();
  for (auto &command : commands) {
    command->execute(store);
    delete command;
  }
  cout << "End testStoreFinal" << endl;
  cout << "=====================================" << endl;
}

void testAll() {
  // testStore1();
  // testStore2();
  // testCustomers();
  // testCommands();
  testStoreFinal();
}