/**
 * Driver for starting movie store tests
 */

#include "HashTable.h"
#include "movies.h"
#include <iostream>

using namespace std;

// forward declaration, implementation in store_test.cpp
void testAll();

int main() {
  testAll();
  cout << "Done." << endl;
  return 0;
}
