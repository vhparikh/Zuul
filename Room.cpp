//Created by Vatsal Parikh
//Date: 10/23/20
//cpp file for the room class

//imports
#include <iostream>
#include <cstring>
#include <vector>
#include <iterator>
#include <map>
#include "Room.h"

using namespace std;

Room::Room() { //room constructor

}

char* Room::getDescription() { //returns pointer to description
  return description;
}

char* Room::getName() { //returns pointer to name
  return name;
}

void Room::printItems() { //prints out items in room with an iterator
  for (vector<Item*>::iterator it = items.begin(); it != items.end(); it++) {
    cout << (*it)->getName() << ' ';
  }
  cout << endl;
}

void Room::addItems(Item* object) { //adds item to the room
  items.push_back(object);
}

void Room::removeItems(Item* object) { //removes item from the room using an iterator
  for (vector<Item*>::iterator it = items.begin(); it != items.end(); it++) {
    if (strcmp(object->getName(), (*it)->getName()) == 0) {
      items.erase(it);
      return;
    }
  }
}

vector<Item*>* Room::getItems() { //gets vector pointer of a vector of item pointers for items in the room
  return &items;
}

bool Room::validKey(char* key) { //checks to see if inputed direction is valid
  for (map<const char*, Room*>::iterator it = exits.begin(); it != exits.end(); it++) {
    if (strcmp(key, it->first) == 0) { //if direction matches return true
      return true;
    }
  }
  return false; //return false
}

map<const char*, Room*>* Room::getExits() { //returns pointer to exits map to add and check for exits
  return &exits;
}

void Room::printExits() { //prints out exits in the room
  for (map<const char*, Room*>::iterator it = exits.begin(); it != exits.end(); it++) {
    cout << it->first << ' ';
  }
  cout << endl;
} 

Room* Room::getRoomByKey(char* key) { //returns what room is accesed by a certain direction in the map
  for (map<const char*, Room*>::iterator it = exits.begin(); it != exits.end(); it++) {
    if (strcmp(key, it->first) == 0) {
      return it->second;
    }
  }
  return this;
}
