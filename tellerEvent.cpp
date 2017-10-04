#include "headerheader.h"


double TellerEvent::idle(){
  return 150*rand()/float(RAND_MAX);
}

TellerEvent::TellerEvent(double occuranceTime, double duration){
  this.occuranceTime = occuranceTime;
  this.duration = this.idle();
}

int TellerEvent::action(){
  totalIdleTime += this.duration;
  
}