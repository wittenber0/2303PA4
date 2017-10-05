
#include "headerheader.h"

CustomerEvent::CustomerEvent(double arrivalTime, double serviceDuration) : Event(arrivalTime){
  this->arrivalTime = arrivalTime;
  this->serviceDuration = serviceDuration;
}

int CustomerEvent::action(){
  totalServiceTime += serviceDuration;
  totalCustomersServed++;
  finishTime = this->completionTime + this->serviceDuration;
  if(this->completionTime - this->arrivalTime > maximumWaitTime){
    maximumWaitTime = this->completionTime - this->arrivalTime;
  }
  return 0;
}

int CustomerEvent::isCustomer(){
  return 1;
}

double CustomerEvent::getArrivalTime(){
	return this->arrivalTime;
}

double CustomerEvent::getCompletionTime(){
	return this->completionTime;
}

double CustomerEvent::getServiceDuration(){
	return this->serviceDuration;
}
