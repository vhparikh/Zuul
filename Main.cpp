#include <iostream>
#include <cstring>
#include <vector>
#include <iterator>
#include "Room.h"
#include "Item.h"

using namespace std;

int main()
{
  vector<Room*> rooms;
  vector<Item*> inventory;
  Room* r1 = new Room();
  rooms.push_back(r1);
  Item* pen = new Item();
  strcpy(r1->getName(), "Comp sci lab");
  strcpy(r1->getDescription(), "The coolest lab in the WORLD!!");
  strcpy(pen->getName(), "Pen");
  r1->addItems(pen);
  r1->printItems();
  char bob[10];
  strcpy(bob, "Pen");
  r1->removeItems((&inventory), bob);
}
