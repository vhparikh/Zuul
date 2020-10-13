#include <iostream>
#include <cstring>

using namespace std;

class Room {
 public:
  Room();
  char* getDescription();
  char* getName();
 private:
  char description[200];
  char name[200];
};
