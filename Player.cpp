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
  //  cout << currentRoom->getName() << endl;
  //cout << currentRoom->getDescription() << endl;
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
      cout << (*it)->getName() << " has been added to your inventory" << endl;
      return;
    }
  }
  cout << "Not a valid item in this room" << endl;
}

void Player::list() {
  if (inventory.empty()) {
    cout << "Your inventory is empty" << endl;
    return;
  }
  for (vector<Item*>::iterator it = inventory.begin(); it != inventory.end(); it++) {
    cout << (*it)->getName() << ' ';
  }
  cout << endl;
}

void Player::drop(char* newItem) {
  for (vector<Item*>::iterator it = inventory.begin(); it != inventory.end(); it++) {
    if (strcmp(newItem, (*it)->getName()) == 0) {
      currentRoom->addItems(*it);
      inventory.erase(it);
      cout << (*it)->getName() << " has been removed from your inventory" << endl;
      return;
    }
  }
  cout << "Not a valid item in your inventory" << endl;
}

int Player::getInventorySize() {
  return inventory.size();
}
