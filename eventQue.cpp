#include "headerheader.h"

ENode::ENode(Event e, ENode* p, ENode* n){
  this->event = e;
  this->previous = p;
  this->next = n;
}

int EventQue::add(Event e){

}

int EventQue::addHelper(Enode* n, Event e){
  if(n->previous){
    if(e.time > n->previous->time && e.time < n->time){
      Node* middle = new ENode(e, n->previous, n);
      n->previous->next = middle;
      n->previous = middle;
    }
  }
}

int EventQue::deleteNode(ENode* n){
  //deleteNode From memory still needs to be done here
  n->previous->next = n->next;
}

int EventQue::removeHelp(ENode* n, Event e){
  ENode node = *n;
  if(&(node.event) == &e){
    deleteNode(n);
    return 1;
  }

  if(node.next){
    removeHelp(node.next, e);
  }

  return 0;
}


int EventQue::remove(Event e){
  this->current = this->first;

  removeHelp(this->current, e);
}

ENode* EventQue::getFirst(){
  return this.first;
}


ENode* EventQue::getLast(){
  return this.last;
}
