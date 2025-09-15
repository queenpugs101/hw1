/*
CSCI 104: Homework 1 Problem 1

Use this file to test your split.cpp file.

Create linked lists and split them with your split() function.

You can compile this file like this:
g++ split.cpp test_split.cpp -o test_split
*/

#include "split.h"
#include <cstddef>
#include <iostream>

using namespace std;
int main(int argc, char* argv[])
{
  Node* orignal = NULL;
  Node* odd = NULL;
  Node* even = NULL;
  
  push_back(1, orignal);
  push_back(3, orignal);
  push_back(5, orignal);
  push_back(7, orignal);
  push_back(9, orignal);
  push_back(11, orignal);
  push_back(12, orignal);
  // push_back(4, orignal);
  // push_back(5, orignal);
  // push_back(5, orignal);
  split(orignal, odd, even);

  Node* printer= odd;
  while(printer != nullptr){
    cout << printer->value << ", ";
    printer = printer->next;
  }
  cout <<"next list ";
  printer = even;
  while(printer != nullptr){
    cout << printer->value << ", ";
    printer = printer->next;
  }
    cout <<"last list list ";

  //printList(odd);
  //printList(even);
  mydeleteListdeleteList(orignal);
  mydeleteListdeleteList(even);
  mydeleteList(odd);

}
