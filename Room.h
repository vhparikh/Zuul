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
  bool validItem(char* object);
  vector<Item*>* getItems();
  bool validKey(char* key);
  void printExits();
  map<const char*, Room*>* getExits();
  Room* getRoomByKey(char* key);
private:
  char description[1000];
  char name[100];
  vector<Item*> items;
  map<const char*, Room*> exits;
};

#endif
