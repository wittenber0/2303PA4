
#include "customerEvent.h"//#include "headerheader.h"
#include <cstdlib>

CustomerEvent::CustomerEvent(double arrivalTime, double serviceDuration){
  Event(arrivalTime);
  this.arrivalTime = arrivalTime;
  this.serviceDuration = serviceDuration;
}

int CustomerEvent::action(){
  totalServiceTime += serviceDuration;
  totalCustomersServed++;
  finishTime = this.completionTime + this.duration;
  if(this.completionTime - this.arrivalTime > maximumWaitTime){
    maximumWaitTime = this.completionTime - this.arrivalTime;
  }
}

int CustomerEvent::isCustomer(){
  return 1;
}
