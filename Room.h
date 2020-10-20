#include <iostream>
#include <cstring>
#include <vector>
#include "Item.h"

#ifndef ROOM_H
#define ROOM_H

using namespace std;

class Room {
 public:
  Room();
  char* getDescription();
  char* getName();
  void printItems();
  void addItems(Item* object);
  void removeItems(Item* object);
  bool validItem(char* object);
  vector<Item*>* getItems();
private:
  char description[1000];
  char name[100];
  vector<Item*> items;
};

#endif
