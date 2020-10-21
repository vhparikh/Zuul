#include <iostream>
#include <cstring>
#include <vector>
#include <map>
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
  vector<Item*>* getItems();
  bool validKey(char* key);
  map<const char*, Room*>* getExits();
  void printExits();
  Room* getRoomByKey(char* key);
private:
  char description[1000];
  char name[100];
  vector<Item*> items;
  map<const char*, Room*> exits;
};

#endif
