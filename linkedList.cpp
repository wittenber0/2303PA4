#include "headerheader.h"

Node::Node(Event e, Node* p, Node* n){
  this->event = e;
  this->previous = p;
  this->next = n;
}

int LinkedList::add(Event e){
  Node* np = &(this->last);
  Node* nn = 0;
  Node* n = new Node(e, np, nn);
  this->last.next = n;
  return 0;
}

int LinkedList::deleteNode(Node* n){
  //deleteNode From memory still needs to be done here
  n->previous->next = n->next;
}

int LinkedList::removeHelp(Node* n, Event e){
  Node node = *n;
  if(&(node.event) == &e){
    deleteNode(n);
    return 1;
  }

  if(node.next){
    removeHelp(node.next, e);
  }

  return 0;
}


int LinkedList::remove(Event e){
  this->current = this->first;

  removeHelp(this->current, e);
}
