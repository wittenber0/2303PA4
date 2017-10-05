#include "event.h"
#include "customerEvent.h"
#include "tellerEvent.h"
#include "eventQue.h"
#include "tellerQue.h"
#include <cstdlib>
#include <iostream>




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
      TellerQue tellerque = new TellerQue(i);
      tellerlist = tellerque;
    }

    EventQue eventque = new EventQue();//create event que
    EventQue proccessedEvents = new EventQue();
    for(int i=0; i<numCustomers; i++){
      double serviceDuration = 2*averageTime*rand()/float(RAND_MAX);
      double arrTime = simTime * rand()/float(RAND_MAX);

      CustomerEvent customerevent = new CustomerEvent(arrTime, serviceDuration);
      //add handling starting ....
      eventque.add(customerevent);
    }

    for (globalclock =0; globalclock<simTime; globalclock += 0.1){
    //add handling starting ....
      if(eventque.getFirst() && eventque.getFirst()->event.isCustomer()){

        CustomerEvent* E = eventque.getFirst;
        if (E->isCustomer()){
          TellerQue* smallest = getSmallestTeller(tellerlist, numTellers);
          smallest->add(*E);
          eventque.remove(*E);
        }

        for (int i=0; i< numTellers; i++){
          TellerQue currentTeller = tellerlist;
          if(i!=0){
            currentTeller++;
          }

          if(currentTeller.getAvalible() == globalclock && currentTeller.first){
            CustomerEvent* nextEvent = currentTeller.first;
            nextEvent->completionTime = globalclock + nextEvent->serviceDuration;
            nextEvent->action();

            currentTeller.avalibleTime = globalclock + nextEvent->serviceDuration;
            proccessedEvents.add(*nextEvent);
            currentTeller.remove(*nextEvent);
          }else if(!currentTeller.first && currentTeller.getAvalible() == globalclock){
            TellerEvent* idleEvent = new TellerEvent(globalclock);
            currentTeller.idle(idleEvent);
            idleEvent->action();
          }
        }
      }
    }

    printf("Total Customers Served: %i\n", totalCustomersServed);
    printf("Total Number of Tellers: %i\n", numTellers);
    printf("Average Time in Bank: %i  With Standard Deviation %d \n", totalCustomerMinutes/totalCustomersServed, standardDeviation);
    printf("Maximum Wait Time: %d\n", maximumWaitTime);
    printf("Total Service Time: %d\n", totalServiceTime);
    printf("Total Idle Time: %d\n", totalIdleTime);

  }
}
