#include <iostream>
#include <cstring>
#include "Room.h"

using namespace std;

Room::Room() {

}

char* Room::getDescription() {
  return description;
}

char* Room::getName() {
  return name;
}
