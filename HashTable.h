#ifndef HASH_TABLE_H
#define HASH_TABLE_H

#include <functional>
#include <vector>

using namespace std;

template <class T> class HashTable {
public:
  // creates hashtable with all 26 letters in it
  HashTable() { objLocation.resize(26, nullptr); }

  // inserts a new object at the hashed location of its letter
  bool insert(char key, T *value) {
    size_t index = hashfn(key) % objLocation.size();
    objLocation[index] = value;
    return true;
  }

  // gets the object at the hashed location of its letter
  T *&get(char key) {
    size_t index = hashfn(key) % objLocation.size();
    return objLocation[index];
  }

private:
  vector<T *> objLocation;
  hash<char> hashfn;
};

#endif
