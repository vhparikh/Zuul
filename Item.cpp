//Created by Vatsal Parikh
//Date: 10/23/20
//.cpp file for item class

//imports
#include <iostream>
#include <cstring>
#include "Item.h"

using namespace std;

Item::Item() { //constructor
  
}

char* Item::getName() { //returns pointer to name
  return name;
}
