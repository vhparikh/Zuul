//Created by Vatsal Parikh
//Date: 10/23/20
//.h file for parser class

//imports
#include <iostream>
#include <cstring>

using namespace std;

class Parser {
 public:
  Parser(); //constructor
  char* getSubStr1(char* str); //return pointer to the first substring
  char* getSubStr2(char* str, int start, int end); //returns pointer to the second substring
};
