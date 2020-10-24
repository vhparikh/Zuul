//Created by Vatsal Parikh
//Date: 10/23/20
//.h file for items class

//imports
#include <iostream>
#include <cstring>

//start of header gaurd
#ifndef ITEM_H
#define ITEM_H

using namespace std;

class Item {
 public:
  Item(); //constructor
  char* getName(); //returns pointer to name
 private:
  char name[100]; //char array for item name
};

//end of header gaurd
#endif
