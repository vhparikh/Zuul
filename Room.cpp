#include <iostream>
#include <cstring>
#include <vector>
#include <iterator>
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
    cout << (*it)->getName() << endl;
  }
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
      
