#include "tellerEvent.h"
//#include <cstdlib>


double TellerEvent::idle(){
  return 150*rand()/float(RAND_MAX);
}

TellerEvent::TellerEvent(double occuranceTime){
  this->occuranceTime = occuranceTime;
  this->duration = this->idle();
}

int TellerEvent::action(){
  totalIdleTime += this->duration;

}

double TellerEvent::getDuration(){
	return this->duration;
}
