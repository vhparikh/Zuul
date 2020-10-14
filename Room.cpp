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

void Room::removeItems(vector<Item*>* objects, char name[]) {
  for (vector<Item*>::iterator it = items.begin(); it != items.end(); it++) {
    if (strcmp((*it)->getName(), name) == 0) {
      objects->push_back(*it);
      items.erase(it);
      return;
    }
  }
}
