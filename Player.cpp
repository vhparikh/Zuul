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

void Player::addInventory(Item* newItem) {
  inventory.push_back(newItem);
  currentRoom->removeItems(newItem);
}

void Player::printInventory() {
  for (vector<Item*>::iterator it = inventory.begin(); it != inventory.end(); it++) {
    cout << (*it)->getName() << endl;
  }
}

void Player::removeInventory(Item* newItem) {
  currentRoom->addItems(newItem);
  for (vector<Item*>::iterator it = inventory.begin(); it != inventory.end(); it++) {
    if (strcmp(newItem->getName(), (*it)->getName()) == 0) {
      inventory.erase(it);
      return;
    }
  }
}
