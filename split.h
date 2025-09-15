#ifndef SPLIT_H
#define SPLIT_H


struct Node 
{
  int value;
  Node* next;

  /**
   * Initializing constructor
   */
  Node(int v, Node* n)
  {
    value = v;
    next = n;
  }
};

void split(Node*& in, Node*& odds, Node*& evens);
// helper functions
void push_back(int val, Node*& LList);
void push_backNode(Node*& node, Node*& LList);
Node* traverseList(Node*& LList);
//void mydeleteList(Node*& LList);
void printList(Node*& LList);
void freeNode(Node*& LList);
#endif
