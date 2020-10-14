#include <iostream>
#include <cstring>

#ifndef ITEM_H
#define ITEM_H

using namespace std;

class Item {
 public:
  Item();
  char* getName();
 private:
  char name[100];
};

#endif
