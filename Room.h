#include <iostream>
#include <cstring>
#include <vector>
#include "Item.h"

using namespace std;

class Room {
 public:
  Room();
  char* getDescription();
  char* getName();
  void printItems();
  void addItems(Item* object);
  void removeItems(vector<Item*>* objects, char name[]);
 private:
  char description[1000];
  char name[100];
  vector<Item*> items;
};
