#include <iostream>
#include <cstring>
#include "Parser.h"

using namespace std;

Parser::Parser() {

}

char* Parser::getSubStr1(char* str) {
  char* sub1 = new char[20];
  int counter = 0;
  for (int i = 0; i < strlen(str); i++) {
    if (str[i] == ' ') {
      counter++;
      break;
    }
    if (str[i] >= 'A' && str[i] <= 'Z') {
      sub1[counter] = str[i] + 32;
      counter++;
    }
    else {
      sub1[counter] = str[i];
      counter++;
    }
  }
  
  sub1[counter] = '\0';
  return sub1;
}

char* Parser::getSubStr2(char* str, int start, int end) {
  char* sub2 = new char[end-start];
  int counter = 0;
  for (int i = start; i < end; i++) {
    if (str[i] >= 'A' && str[i] <= 'Z') {
      sub2[counter] = str[i] + 32;
      counter++;
    }
    else {
      sub2[counter] = str[i];
      counter++;
    }
  }
  return sub2;
}

