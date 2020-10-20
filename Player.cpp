#include <iostream>
#include <cstring>
#include <vector>
#include <iterator>
#include "Player.h"

using namespace std;

Player::Player(Room* startRoom) {
  currentRoom = startRoom;
}


Room* Player::getCurrentRoom() {
  cout << currentRoom->getName() << endl;
  cout << currentRoom->getDescription() << endl;
  return currentRoom;
}

void Player::setCurrentRoom(Room* newRoom) {
  currentRoom = newRoom;
}

void Player::pick(char* newItem) {
  vector<Item*>* items = currentRoom->getItems();
  for (vector<Item*>::iterator it = items->begin(); it != items->end(); it++) {
    if (strcmp(newItem, (*it)->getName()) == 0) {
      inventory.push_back(*it);
      currentRoom->removeItems(*it);
      return;
    }
  }
  cout << "Not a valid item in this room" << endl;
}

void Player::list() {
  for (vector<Item*>::iterator it = inventory.begin(); it != inventory.end(); it++) {
    cout << (*it)->getName() << endl;
  }
}

void Player::drop(char* newItem) {
  for (vector<Item*>::iterator it = inventory.begin(); it != inventory.end(); it++) {
    if (strcmp(newItem, (*it)->getName()) == 0) {
      currentRoom->addItems(*it);
      inventory.erase(it);
      return;
    }
  }
  cout << "Not a valid item in your inventory" << endl;
}
