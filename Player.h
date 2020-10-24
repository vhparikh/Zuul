//Created by Vatsal Parikh
//Date: 10/23/20
//.h file for player class

//imports
#include <iostream>
#include <cstring>
#include <vector>
#include "Room.h"
#include "Item.h"

//start of header gaurd
#ifndef PLAYER_H
#define PLAYER_H

using namespace std;

class Player {
 public:
  Player(Room* startRoom); //constructor with starting room
  Room* getCurrentRoom(); //returns pointer to currentroom
  void setCurrentRoom(Room* newRoom); //sets the currentroom to what is passed in the parameter
  void pick(char* newItem); //picks up item in room and adds it to the inventory
  void list(); //prints out a list of whats in inventory
  void drop(char* newItem); //drops item from the inventory
  int getInventorySize(); //returns the size of the inventory
private:
  vector<Item*> inventory; //vector of items: inventory
  Room* currentRoom; //pointer to point to the current room
};

//end of header gaurd
#endif
