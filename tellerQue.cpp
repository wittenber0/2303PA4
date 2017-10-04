#include "headerheader.h"

TQNode::TQNode(CustomerEvent c, TQNode* p, TQNode* n){
  this->CustomerEvent = c;
  this->previous = p;
  this->next = n;
}


int TellerQue::TellerQue(int id)
{
  this.id = id;
  this.size = 0;
  this.avalibleTime=0;
}

int TellerQue::idle(TellerEvent* t){
  this.avalibleTime = startTime + t.getDuration();
  return 0;
}

double TellerQue::getAvalible(){
  return this.avalibleTime;
}

int TellerQue::add(TQNode* n, CustomerEvent e){
  if(first){
      if(e.arrivalTime > n->previous->arrivalTime && e.arrivalTime < n->arrivalTime){
        TQNode* middle = new TQNode(e, n->previous, n);
        n->previous->next = middle;
        n->previous = middle;
      }else{
        if(n->next){
          add(n->next, e);
        }else{
          TQNode* end = new TQNode(e, n, 0);
          this.last = end;
        }
      }
  }else{
    this.first = new ENode(e, 0, 0);
    this.last = this.first;
  }


  return 0;
}


int TellerQue::deleteNode(TQNode* n){
  //deleteNode From memory still needs to be done here
  n->previous->next = n->next;
}

int TellerQue::getSize(){
  return this.size;
}

int TellerQue::removeHelp(TQNode* n, CustomerEvent c){
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
