
#include <cstdlib>
#include <iostream>
//#include "event.h"
#include "statistics.h"
#include "customerEvent.h"
#include "tellerEvent.h"
#include "tellerQue.h"

double globalclock = 0;
double totalIdleTime=0;
double totalServiceTime=0;
int totalCustomersServed=0;
double totalCustomerMinutes=0;
double maximumWaitTime=0;
double finishTime =0;
int emptybank = 0;
double standardDeviation = 0;


TellerQue* getSmallestTeller(TellerQue* first, int size){
  TellerQue* smallest = first;
  TellerQue* current = first;
  for (int i=1; i< size; i++){
    current++;
    if(current->getSize()< smallest->getSize())
    {
      smallest = current;
    }
  }

  return smallest;
}

int main(int argc, char* argv[]){
  if(argc > 4){
    int numCustomers = atoi(argv[2]);
    int numTellers = atoi(argv[3]);
    int simTime = atof(argv[4]);
    float averageTime = atof(argv[5]);

    TellerQue* tellerlist;
    for (int i=0; i<numTellers; i++){
      if (i!=0){
        tellerlist++;
      }
      TellerQue* tellerque = new TellerQue();
      tellerlist = tellerque;
    }

    TellerQue* eventque = new TellerQue();//create event que
    TellerQue* proccessedEvents = new TellerQue();
    for(int i=0; i<numCustomers; i++){
      double serviceDuration = 2*averageTime*rand()/float(RAND_MAX);
      double arrTime = simTime * rand()/float(RAND_MAX);

      CustomerEvent* customerevent = new CustomerEvent(arrTime, serviceDuration);
      //add handling starting ....
      eventque->add(*customerevent);
    }

    for (globalclock =0; globalclock<simTime; globalclock += 0.1){
    //add handling starting ....
      if(eventque->getFirst() && eventque->getFirst()->customerevent.isCustomer()){


        Event E = eventque->getFirst()->customerevent;

        if (E.isCustomer()){
          //CustomerEvent* E = dynamic_cast<CustomerEvent*>(&EE);
          TellerQue* smallest = getSmallestTeller(tellerlist, numTellers);
          smallest->add(E);
          eventque->remove(E);
        }

        for (int i=0; i< numTellers; i++){
          TellerQue* currentTeller = tellerlist;
          if(i!=0){
            currentTeller++;
          }

          if(currentTeller->getAvalible() == globalclock && currentTeller->getFirst()){
            Event nextEvent = currentTeller->getFirst()->customerevent;
            nextEvent.completionTime = globalclock + nextEvent.serviceDuration;
            nextEvent.action();

            currentTeller->avalibleTime = globalclock + nextEvent.serviceDuration;
            proccessedEvents->add(nextEvent);
            currentTeller->remove(nextEvent);
          }else if(!currentTeller->getFirst() && currentTeller->getAvalible() == globalclock){

            //tellerEvent constructor is wrong I thinkk we need to randomize idle duratin here instead of wherever it is
            TellerEvent* idleEvent = new TellerEvent(globalclock);
            currentTeller->idle(idleEvent->getDuration());
            idleEvent->action();
          }
        }
      }
    }

    printf("Total Customers Served: %i\n", totalCustomersServed);
    printf("Total Number of Tellers: %i\n", numTellers);
    printf("Average Time in Bank: %f  With Standard Deviation %f\n", totalCustomerMinutes/totalCustomersServed, standardDeviation);
    printf("Maximum Wait Time: %f\n", maximumWaitTime);
    printf("Total Service Time: %f\n", totalServiceTime);
    printf("Total Idle Time: %f\n", totalIdleTime);

  }
}
