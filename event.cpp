#include "event.h"

Event::Event(double start, double duration){
  this->arrivalTime = start;
  this->serviceDuration = duration;
}

Event::Event(){
  this->arrivalTime = 0;
  this->serviceDuration = 0;
}

int Event::isCustomer(){
  return 0;
}





int Event::action(){
  return 0;
}
