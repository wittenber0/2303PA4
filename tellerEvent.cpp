#include "tellerEvent.h"
#include "statistics.h"
#include <cstdlib>


double TellerEvent::idle(){
  return 150*rand()/float(RAND_MAX);
}

TellerEvent::TellerEvent(double occuranceTime):Event(occuranceTime, this->idle()){
  this->occuranceTime = occuranceTime;
  this->duration = this->idle();
}

int TellerEvent::action(){
  totalIdleTime += this->duration;

  return 0;
}

double TellerEvent::getDuration(){
	return this->duration;
}
