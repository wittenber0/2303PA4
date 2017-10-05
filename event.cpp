#include "event.h"

Event::Event(double start, double duration){
  this->arrivalTime = start;
  this->serviceDuration = duration;
}

int Event::isCustomer(){
  return 0;
}

int Event::action(){
  return 0;
}
