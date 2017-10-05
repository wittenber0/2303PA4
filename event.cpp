#include "event.h"

Event::Event(int t){
  this->time = t;
}

virtual int Event::isCustomer(){
  return 0;
}

virtual int Event::action(){
  return 0;
}
