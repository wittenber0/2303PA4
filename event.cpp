#include "headerheader.h"

Event::Event(int t){
  this.time = t;
}

int Event::getEvent(){
  return this.time;
}

int Event::addToTail(LinkedList q){
  return q.add(this);
}

int Event::removeFromHead(LinkedList q){
  q.remove(q.getFirst());
}
