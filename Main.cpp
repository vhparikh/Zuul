#include <iostream>
#include <cstring>
#include <vector>
#include <iterator>
#include "Room.h"
#include "Item.h"
#include "Parser.h"
#include "Player.h"

using namespace std;

int main()
{
  char* input = new char();
  Parser parser;
  Room* r1 = new Room();
  Room* r2 = new Room();
  Player player(r1);
  strcpy(r2->getName(), "Bio lab");
  strcpy(r2->getDescription(), "frogs!!!!!");
  Item* pen = new Item();
  strcpy(r1->getName(), "Comp sci lab");
  strcpy(r1->getDescription(), "The coolest lab in the WORLD!!");
  strcpy(pen->getName(), "Pen");
  r1->addItems(pen);
  r1->printItems();
  cin.get(input, 100);
  cin.get();
  char* s1 = parser.getSubStr1(input);
  parser.getSubStr2(input, strlen(s1)+1, strlen(input)+1);
  player.getCurrentRoom();
  player.setCurrentRoom(r2);
  player.getCurrentRoom();
  player.setCurrentRoom(r1);
  player.addInventory(pen);
  //player.printInventory();
  player.setCurrentRoom(r2);
  player.removeInventory(pen);
  //player.printInventory();
  r2->printItems();
}
