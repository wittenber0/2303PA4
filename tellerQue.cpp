#include "headerheader.h"

TQNode::TQNode(Customer c, TQNode* p, TQNode* n){
  this->customer = c;
  this->previous = p;
  this->next = n;
}

int TellerQue::add(Customer c){
  TQNode* np = &(this->last);
  TQNode* nn = 0;
  TQNode* n = new TQNode(e, np, nn);
  this->last.next = n;
  return 0;
}

int TellerQue::deleteNode(TQNode* n){
  //deleteNode From memory still needs to be done here
  n->previous->next = n->next;
}

int TellerQue::removeHelp(TQNode* n, Customer c){
  TQNode node = *n;
  if(&(node.customer) == &c){
    deleteNode(n);
    return 1;
  }

  if(node.next){
    removeHelp(node.next, c);
  }

  return 0;
}


int TellerQue::remove(Customer c){
  this->current = this->first;

  removeHelp(this->current, c);
}

TQNode* TellerQue::getFirst(){
  return this.first;
}


TQNode* TellerQue::getLast(){
  return this.last;
}