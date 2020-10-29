//Created by Vatsal Parikh
//Date: 10/23/20
//.cpp fiel for parser class

//imports
#include <iostream>
#include <cstring>
#include "Parser.h"

using namespace std;

Parser::Parser() { //constructor

}

char* Parser::getSubStr1(char* str) { //returns pointer to first substring in the input
  char* sub1 = new char[20]; //create char pointer to array of 20 chars in the heap
  int counter = 0; //counter
  for (int i = 0; i < strlen(str); i++) {
    if (str[i] == ' ') { //if the slot is a space increment counter and leave the loop
      break;
    }
    if (str[i] >= 'A' && str[i] <= 'Z') { //if a letter add it in lower case
      sub1[counter] = str[i] + 32;
      counter++;
    }
    else {
      sub1[counter] = str[i];
      counter++;
    }
  }
  
  sub1[counter] = '\0'; //adds in the null terminating
  return sub1; //returns the substring
}

char* Parser::getSubStr2(char* str, int start, int end) { //returns pointer to the second substring in the input
  char* sub2 = new char[end-start]; //create char pointer to array of exact size of the second substring
  int counter = 0; //counter
  for (int i = start; i < end; i++) {
    if (str[i] >= 'A' && str[i] <= 'Z') { //if a letter add it in lower case
      sub2[counter] = str[i] + 32;
      counter++;
    }
    else {
      sub2[counter] = str[i];
      counter++;
    }
  }
  return sub2; //returns substring
}

