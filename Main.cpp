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
  strcpy(r1->getName(), "Entrance");
  strcpy(r1->getDescription(), "You are at the entrance the door is now locked you will be very lucky if you make it out alive");
  Room* r2 = new Room();
  strcpy(r2->getName(), "Main Hall");
  strcpy(r2->getDescription(), "Do you hear screaming?");
  Room* r3 = new Room();
  strcpy(r3->getName(), "Autopsy Room");
  strcpy(r3->getDescription(), "Woah is that Einstein's brain just lying out on a table!");
  Room* r4 = new Room();
  strcpy(r4->getName(), "Zoo");
  strcpy(r4->getDescription(), "Are those zombies in cages keep your distance");
  Room* r5 = new Room();
  strcpy(r5->getName(), "Bedroom");
  strcpy(r5->getDescription(), "Wow this might be the only quiet room");
  Room* r6 = new Room();
  strcpy(r6->getName(), "Rental Room");
  strcpy(r6->getDescription(), "It's free, but will you wake up once you go to sleep?");
  Room* r7 = new Room();
  strcpy(r7->getName(), "Torture Chamber");
  strcpy(r7->getDescription(), "I smell cyanide get out of hear quick!");
  Room* r8 = new Room();
  strcpy(r8->getName(), "Potions Room");
  strcpy(r8->getDescription(), "There are so many!");
  Room* r9 = new Room();
  strcpy(r9->getName(), "Graveyard");
  strcpy(r9->getDescription(), "How is there a graveyard in the house!");
  Room* r10 = new Room();
  strcpy(r10->getName(), "Lab");
  strcpy(r10->getDescription(), "Crazy stuff happens here");
  Room* r11 = new Room();
  strcpy(r11->getName(), "Living Room");
  strcpy(r11->getDescription(), "5 people have died in this room nobody knows why");
  Room* r12 = new Room();
  strcpy(r12->getName(), "Recovery Room");
  strcpy(r12->getDescription(), "These people were a little too brave");
  Room* r13 = new Room();
  strcpy(r13->getName(), "Spider Habitat");
  strcpy(r13->getDescription(), "Did you know there are over 45,000 spider species and we have all of them crawling around in this room!");
  Room* r14 = new Room();
  strcpy(r14->getName(), "Kitchen");
  strcpy(r14->getDescription(), "Wow that smells pretty good I wonder what's being cooked");
  Room* r15 = new Room();
  strcpy(r15->getName(), "Shed");
  strcpy(r15->getDescription(), "Not gonna lie this is kinda creepy");

  r1->getExits()->insert(pair<const char*, Room*>("north", r2));
  r1->getExits()->insert(pair<const char*, Room*>("east", r14));

  r2->getExits()->insert(pair<const char*, Room*>("south", r1));
  r2->getExits()->insert(pair<const char*, Room*>("north", r3));
  r2->getExits()->insert(pair<const char*, Room*>("east", r4));
  r2->getExits()->insert(pair<const char*, Room*>("west", r5));

  r3->getExits()->insert(pair<const char*, Room*>("south", r2));
  r3->getExits()->insert(pair<const char*, Room*>("west", r9));

  r4->getExits()->insert(pair<const char*, Room*>("west", r2));
  r4->getExits()->insert(pair<const char*, Room*>("north", r6));

  r5->getExits()->insert(pair<const char*, Room*>("west", r11));
  r5->getExits()->insert(pair<const char*, Room*>("south", r13));
  r5->getExits()->insert(pair<const char*, Room*>("east", r2));

  r6->getExits()->insert(pair<const char*, Room*>("south", r4));
  r6->getExits()->insert(pair<const char*, Room*>("east", r8));

  r7->getExits()->insert(pair<const char*, Room*>("south", r15));

  r8->getExits()->insert(pair<const char*, Room*>("west", r6));

  r9->getExits()->insert(pair<const char*, Room*>("west", r10));
  r9->getExits()->insert(pair<const char*, Room*>("east", r3));

  r10->getExits()->insert(pair<const char*, Room*>("south", r11));
  r10->getExits()->insert(pair<const char*, Room*>("east", r9));

  r11->getExits()->insert(pair<const char*, Room*>("north", r10));
  r11->getExits()->insert(pair<const char*, Room*>("east", r5));

  r12->getExits()->insert(pair<const char*, Room*>("east", r13));

  r13->getExits()->insert(pair<const char*, Room*>("north", r5));
  r13->getExits()->insert(pair<const char*, Room*>("west", r12));

  r14->getExits()->insert(pair<const char*, Room*>("west", r1));
  r14->getExits()->insert(pair<const char*, Room*>("east", r15));

  r15->getExits()->insert(pair<const char*, Room*>("west", r14));
  r15->getExits()->insert(pair<const char*, Room*>("north", r7));

  Item* toy = new Item();
  strcpy(toy->getName(), "toy");
  r4->addItems(toy);
  
  Parser parser;
  Player player(r1);

  char input[100];
  bool quit = false;
  bool openexit = false;
  
  cout << "You are currently in the: " << r1->getName() << ", " << r1->getDescription() << endl;
  cout << "Your exits are: ";
  r1->printExits();
  
  while (strcmp(parser.getSubStr1(input), "quit") != 0 ||
	 strcmp(player.getCurrentRoom()->getName(), "Exit") != 0) {

    if (player.getInventorySize() == 1 && !openexit) {
      Room* r16 = new Room();
      strcpy(r16->getName(), "Exit");
      strcpy(r16->getDescription(), "You finally reached the exit!");
      r16->getExits()->insert(pair<const char*, Room*>("south", r6));
      r6->getExits()->insert(pair<const char*, Room*>("north", r16));
      openexit = true;
    }

    cin.get(input, 100);
    cin.get();
    char* s1 = parser.getSubStr1(input);
    if (strcmp(s1, "go") == 0) {
      char* direction = parser.getSubStr2(input, strlen(s1) + 1, strlen(input) + 1);
      if (player.getCurrentRoom()->validKey(direction)) {
	player.setCurrentRoom(player.getCurrentRoom()->getRoomByKey(direction));
	cout << "You are currently in the: " << player.getCurrentRoom()->getName() << ", " <<
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
