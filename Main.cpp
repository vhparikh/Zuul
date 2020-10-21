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
  Room* r1 = new Room();
  strcpy(r1->getName(), "1-20");
  strcpy(r1->getDescription(), "cool shit");
  Room* r2 = new Room();
  strcpy(r2->getName(), "bio");
  strcpy(r2->getDescription(), "ewww");
  Room* r3 = new Room();
  strcpy(r3->getName(), "");
  strcpy(r3->getDescription(), "");
  Room* r4 = new Room();
  strcpy(r4->getName(), "");
  strcpy(r4->getDescription(), "");
  Room* r5 = new Room();
  strcpy(r5->getName(), "");
  strcpy(r5->getDescription(), "");
  Room* r6 = new Room();
  strcpy(r6->getName(), "");
  strcpy(r6->getDescription(), "");
  Room* r7 = new Room();
  strcpy(r7->getName(), "");
  strcpy(r7->getDescription(), "");
  Room* r8 = new Room();
  strcpy(r8->getName(), "");
  strcpy(r8->getDescription(), "");
  Room* r9 = new Room();
  strcpy(r9->getName(), "");
  strcpy(r9->getDescription(), "");
  Room* r10 = new Room();
  strcpy(r10->getName(), "");
  strcpy(r10->getDescription(), "");
  Room* r11 = new Room();
  strcpy(r11->getName(), "");
  strcpy(r11->getDescription(), "");
  Room* r12 = new Room();
  strcpy(r12->getName(), "");
  strcpy(r12->getDescription(), "");
  Room* r13 = new Room();
  strcpy(r13->getName(), "");
  strcpy(r13->getDescription(), "");
  Room* r14 = new Room();
  strcpy(r14->getName(), "");
  strcpy(r14->getDescription(), "");
  Room* r15 = new Room();
  strcpy(r15->getName(), "");
  strcpy(r15->getDescription(), "");

  r1->getExits()->insert(pair<const char*, Room*>("north", r2));
  r2->getExits()->insert(pair<const char*, Room*>("south", r1));

  Item* toy = new Item();
  strcpy(toy->getName(), "toy");
  r2->addItems(toy);
  
  Parser parser;
  Player player(r1);

  char input[100];
  bool quit = false;

  cout << "You are currently in: " << r1->getName() << ", " << r1->getDescription() << endl;
  cout << "Your exits are: ";
  r1->printExits();
  
  while (strcmp(parser.getSubStr1(input), "quit") != 0) {
    cin.get(input, 100);
    cin.get();
    char* s1 = parser.getSubStr1(input);
    if (strcmp(s1, "go") == 0) {
      char* direction = parser.getSubStr2(input, strlen(s1) + 1, strlen(input) + 1);
      if (player.getCurrentRoom()->validKey(direction)) {
	player.setCurrentRoom(player.getCurrentRoom()->getRoomByKey(direction));
	cout << "You are currently in: " << player.getCurrentRoom()->getName() << ", " <<
	  player.getCurrentRoom()->getDescription() << endl;
	cout << "Your exits are: ";
	player.getCurrentRoom()->printExits();
	cout << "The items in this room are: ";
	player.getCurrentRoom()->printItems();
	delete direction;
      }
      else {
	cout << "Invalid exit" << endl;
      }
    }
    else if (strcmp(s1, "pick") == 0) {
      char* item = parser.getSubStr2(input, strlen(s1) + 1, strlen(input) + 1);
      player.pick(item);
      delete item;
    }
    else if (strcmp(s1, "drop") == 0) {
      char* item = parser.getSubStr2(input, strlen(s1) + 1, strlen(input) + 1);
      player.drop(item);
      delete item;
    }
    else if (strcmp(s1, "inventory") == 0) {
      player.list();
    }
    else if (strcmp(s1, "exits") == 0) {
      cout << "Your exits are: ";
      player.getCurrentRoom()->printExits();
    }
    else if (strcmp(s1, "items") == 0) {
      cout << "The items in this room are: ";
      player.getCurrentRoom()->printItems();
    }
    else if (strcmp(s1, "quit") == 0) {
      quit = true;
    }
  }
  
}
