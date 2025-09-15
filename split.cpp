/*
CSCI 104: Homework 1 Problem 1

Write a recursive function to split a sorted singly-linked
list into two sorted linked lists, where one has the even 
numbers and the other contains the odd numbers. Students 
will receive no credit for non-recursive solutions. 
To test your program write a separate .cpp file and #include
split.h.  **Do NOT add main() to this file**.  When you submit
the function below should be the only one in this file.
*/

#include "split.h"
#include <cstddef>
#include <iostream>
using namespace std;
/* Add a prototype for a helper function here if you need */
void push_back(int val, Node*& LList);
Node* traverseList(Node*& LList);
void freeNode(Node*& LList);

void split(Node*& in, Node*& odds, Node*& evens)
{
  /* Add code here */
  // WRITE YOUR CODE HERE
  if(in == nullptr){
    in = NULL;
    return; //base case
  }
  Node* temp = in;
  in = in->next;
  temp->next = nullptr;

  if (temp->value % 2 == 0){
    // add to even list 
    if(evens == nullptr){
      evens = temp;
    }
    else{
      push_backNode(temp, evens);
      
    }
  }
  else if (temp->value % 2 != 0){
    // add to odd list 
    if(odds == nullptr){
      odds = temp;
    }
    else{
      push_backNode(temp, odds);
 
    }
   
  }

  // recursive call
    split(in, odds, evens);
}

/* If you needed a helper function, write it here */
void push_back(int val, Node*& LList){
  Node* newNode = new Node(val, nullptr);
  if(LList == nullptr){
      LList = newNode;
  }
  else{

    Node* temp =traverseList(LList );
    temp->next =newNode;
  }
}
void push_backNode(Node*& node, Node*& LList){
  if(LList == nullptr){
      LList = node;
  }
  else{

    Node* temp =traverseList(LList );
    temp->next =node;
  }
}

Node* traverseList(Node*& LList){
  if (LList == NULL || LList == nullptr){
    return LList;
  }
  if(LList->next == nullptr){
    return LList;
  }
  else{
    return traverseList(LList->next);
  }
}

void printList(Node*& LList){
  if (LList == NULL || LList == nullptr){
    return;
  }
  if(LList->next == nullptr){
    cout << LList->value;
  }
  else{
    printList(LList->next);
  }
}

/*
void mydeleteList(Node*& LList){
  if (LList == NULL || LList == nullptr){
    return;
  }
    deleteList(LList->next);
    delete LList;
    LList = nullptr;
  
}
*/

void freeNode(Node*& LList){
  if (LList == nullptr){
    return;
  }
  else{
    Node* temp = LList;
    LList = LList->next;
    delete temp;
  }
  
}
