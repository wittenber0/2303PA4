#include "tellerQue.h"
#include "event.h"
#include <iostream>

TQNode::TQNode(Event c, TQNode* p, TQNode* n){
  this->customerevent = c;
  this->previous = p;
  this->next = n;
}


TellerQue::TellerQue()
{
  this->size = 0
  this->avalibleTime=0;
}

int TellerQue::idle(double duration){
  this->avalibleTime = startTime + duration;
  return 0;
}

double TellerQue::getAvalible(){
  return this->avalibleTime;
}

int TellerQue::addHelper(TQNode* n, Event e){
  if(first){
      if(e.arrivalTime > n->previous->customerevent.getArrivalTime() && e.arrivalTime < n->customerevent.getArrivalTime()){
        TQNode* middle = new TQNode(e, n->previous, n);
        n->previous->next = middle;
        n->previous = middle;
      }else{
        if(n->next){
          this->addHelper(n->next, e);
        }else{
          TQNode* end = new TQNode(e, n, 0);
          this->last = end;
        }
      }
  }else{
    this->first = new TQNode(e, 0, 0);
    this->last = this->first;
  }


  return 0;
}

int TellerQue::add(Event e){
  this->size++;
	return this->addHelper(this->first, e);
}


int TellerQue::deleteNode(TQNode* n){
  //deleteNode From memory still needs to be done here
  n->previous->next = n->next;
}

int TellerQue::getSize(){
  return this->size;
}

int TellerQue::removeHelp(TQNode* n, Event c){
  TQNode node = *n;
  if(&(node.customerevent) == &c){
    deleteNode(n);
    return 1;
  }

  if(node.next){
    removeHelp(node.next, c);
  }

  return 0;
}


int TellerQue::remove(Event c){
  this->current = this->first;
  TQNode* kill = this->current;

  this->removeHelp(kill, c);
}

TQNode* TellerQue::getFirst(){
  return this->first;
}


TQNode* TellerQue::getLast(){
  return this->last;
}
