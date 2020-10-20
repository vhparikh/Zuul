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
  void pick(char* newItem);
  void list();
  void drop(char* newItem);
 private:
  vector<Item*> inventory;
  Room* currentRoom;
};

#endif
