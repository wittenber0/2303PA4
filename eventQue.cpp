//#include "headerheader.h"
#include "eventQue.h"

ENode::ENode(Event e, ENode* p, ENode* n){
  this->event = e;
  this->previous = p;
  this->next = n;
}

EventQue::EventQue(){
}

int EventQue::add(ENode* n, Event e){
  if(first){
      if(e.time > n->previous->time && e.time < n->time){
        ENode* middle = new ENode(e, n->previous, n);
        n->previous->next = middle;
        n->previous = middle;
      }else{
        if(n->next){
          add(n->next, e);
        }else{
          ENode* end = new ENode(e, n, 0);
          this.last = end;
        }
      }
  }else{
    this.first = new ENode(e, 0, 0);
    this.last = this.first;
  }


  return 0;
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
