#include <iostream>
#include <cstring>
#include <vector>
#include "Room.h"
#include "Item.h"

#ifndef PLAYER_H
#define PLAYER_H

using namespace std;

class Player
{
 public:
  Player(Room* startRoom);
  Room* getCurrentRoom();
  void setCurrentRoom(Room* newRoom);
  void addInventory(Item* newItem);
  void printInventory();
  void removeInventory(Item* newItem);
 private:
  vector<Item*> inventory;
  Room* currentRoom;
};

#endif
