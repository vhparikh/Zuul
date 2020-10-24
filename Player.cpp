//Created by Vatsal Parikh
//Date: 10/28/20
//.cpp file for player class

//imports
#include <iostream>
#include <cstring>
#include <vector>
#include <iterator>
#include "Player.h"

using namespace std;

Player::Player(Room* startRoom) { //contructor which sets the current room to the starting room
  currentRoom = startRoom;
}


Room* Player::getCurrentRoom() { //returns pointer ot players current room
  return currentRoom;
}

void Player::setCurrentRoom(Room* newRoom) { //sets the current room to whats passed in through the parameter
  currentRoom = newRoom;
}

void Player::pick(char* newItem) { //picks up a item and add it to the invetory
  vector<Item*>* items = currentRoom->getItems(); //gets item vector from the current room
  for (vector<Item*>::iterator it = items->begin(); it != items->end(); it++) {
    if (strcmp(newItem, (*it)->getName()) == 0) { //if the item is found
      inventory.push_back(*it); //add it to the inventory
      currentRoom->removeItems(*it); //remove it from the current room
      cout << (*it)->getName() << " has been added to your inventory" << endl;
      return; //returns
    }
  }
  cout << "Not a valid item in this room" << endl;
}

void Player::list() { //lists out whats in the inventory using an iterator
  if (inventory.empty()) {
    cout << "Your inventory is empty" << endl;
    return;
  }
  for (vector<Item*>::iterator it = inventory.begin(); it != inventory.end(); it++) {
    cout << (*it)->getName() << ' ';
  }
  cout << endl;
}

void Player::drop(char* newItem) { //drops the item from the inventory
  for (vector<Item*>::iterator it = inventory.begin(); it != inventory.end(); it++) {
    if (strcmp(newItem, (*it)->getName()) == 0) { //if item is found in inventory
      cout << (*it)->getName() << " has been removed from your inventory" << endl;
      currentRoom->addItems(*it); //adds item to current room
      inventory.erase(it); //removes item from the inventory
      return; //returns
    }
  }
  cout << "Not a valid item in your inventory" << endl;
}

int Player::getInventorySize() { //returns the size of the inventory
  return inventory.size();
}
