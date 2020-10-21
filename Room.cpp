#include <iostream>
#include <cstring>
#include <vector>
#include <iterator>
#include <map>
#include "Room.h"

using namespace std;

Room::Room() {

}

char* Room::getDescription() {
  return description;
}

char* Room::getName() {
  return name;
}

void Room::printItems() {
  for (vector<Item*>::iterator it = items.begin(); it != items.end(); it++) {
    cout << (*it)->getName() << ' ';
  }
  cout << endl;
}

void Room::addItems(Item* object) {
  items.push_back(object);
}

void Room::removeItems(Item* object) {
  for (vector<Item*>::iterator it = items.begin(); it != items.end(); it++) {
    if (strcmp(object->getName(), (*it)->getName()) == 0) {
      items.erase(it);
      return;
    }
  }
}

bool Room::validItem(char* object) {
  for (vector<Item*>::iterator it = items.begin(); it != items.end(); it++) {
    if (strcmp(object, (*it)->getName()) == 0) {
      return true;
    }
  }
  return false;
}

vector<Item*>* Room::getItems() {
  return &items;
}

bool Room::validKey(char* key) {
  for (map<const char*, Room*>::iterator it = exits.begin(); it != exits.end(); it++) {
    if (strcmp(key, it->first) == 0) {
      return true;
    }
  }
  return false;
}

void Room::printExits() {
  for (map<const char*, Room*>::iterator it = exits.begin(); it != exits.end(); it++) {
    cout << it->first << ' ';
  }
  cout << endl;
} 

map<const char*, Room*>* Room::getExits() {
  return &exits;
}

Room* Room::getRoomByKey(char* key) {
  for (map<const char*, Room*>::iterator it = exits.begin(); it != exits.end(); it++) {
    if (strcmp(key, it->first) == 0) {
      return it->second;
    }
  }
  return this;
}
