//Created by Vatsal Parikh
//Date: 10/23/20
//.h file for the room class

//imports
#include <iostream>
#include <cstring>
#include <vector>
#include <map>
#include "Item.h"

//starts header gaurd
#ifndef ROOM_H
#define ROOM_H

using namespace std;

class Room {
 public:
  Room(); //constructor
  char* getDescription(); //returns a char pointer to description char array
  char* getName(); //returns a char pointer to the name char array
  void printItems(); //prints out the items in the room
  void addItems(Item* object); //adds items to the room
  void removeItems(Item* object); //removes items from the room
  vector<Item*>* getItems(); //returns a vector pointer of vector item pointers
  bool validKey(char* key); //returns if a inputed direction is valid based on the room 
  map<const char*, Room*>* getExits(); //returns a pointer to the map of exits for the room
  void printExits(); //prints out the available exits in the room
  Room* getRoomByKey(char* key); //returns the room pointer based on the exit type
private:
  char description[1000]; //char array for description o the room
  char name[100]; //char array for the name of the room
  vector<Item*> items; //vector of item pointers in the room
  map<const char*, Room*> exits; //map of exits key is a const char pointer and the element is a room pointer
};

//ends header gaurd
#endif
