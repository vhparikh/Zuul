#include <iostream>
#include <cstring>

using namespace std;

class Parser {
 public:
  Parser();
  char* getSubStr1(char* str);
  char* getSubStr2(char* str, int start, int end);
  bool validCommand(char* str);
};
