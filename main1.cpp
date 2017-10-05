#include "headerheader.h"
#include <cstdlib>
double globalclock;
double totalIdleTime=0;
double totalServiceTime=0;
int totalCustomersServed=0;
double totalCustomerMinutes=0;
double maximumWaitTime=0;
double finishTime =0;
int emptybank = 0;


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


int main(int argc, char* argv[])
{
  if(argc > 4){
    int numCustomers = atoi(argv[2]);
    int numTellers = atoi(argv[3]);
    int simTime = atof(argv[4]);
    float averageTime = atof(argv[5]);

    TellerQue* tellerlist;
    for (int i=0; i<numTellers; i++)
    {
      if (i!=0)
      {
        tellerlist++;
      }
      TellerQue tellerque = new TellerQue(i);
      tellerlist = tellerque;
    }

    EventQue eventque = new EventQue();//create event que
    for(int i=0; i<numCustomers; i++)
    {
      double serviceDuration = 2*averageTime*rand()/float(RAND_MAX);
      double arrTime = simTime * rand()/float(RAND_MAX);

      CustomerEvent customerevent = new CustomerEvent(arrTime, serviceDuration);
      //add handling starting ....
      eventque->add(customerevent);
    }

    for (globalclock =0; globalclock<simTime; globalclock += 0.1)
    {
    //add handling starting ....
    Event* E = eventque.getFirst;
    if(E.time == globalclock)
    {
      //if customerevent
      TellerQue* smallest = tellerlist->getSmallestTeller();
      smallest->add(E);
      eventque->remove(E);
      for (int i=0; i< numTellers; i++)
      {
          TellerQue currentTeller = tellerlist;
          if(currentTeller->getSize() == 0)
          {
            emptybank = 1;
          }
          if(i!=0){
            currentTeller++;
          }
      }
      if(emptybank == 1)
      {
          TellerEvent tellerevent = new TellerEvent(i,globalclock+idle);
      }
      else
      {
      for (int i=0; i< numTellers; i++)
      {
        TellerQue currentTeller = tellerlist;
        if(currentTeller->getSize() == 0 && (currentTeller++)->getSize() != 0)
        {
          currentTeller.addfirst(//the next teller's first customer)
          currentTeller.remove(//the teller's first customer)
        }
        if(i!=0)
        {
          currentTeller++;
        }
      }
    }
      //if tellerevent
      TellerEvent tellerevent = new TellerEvent(tellerlist[E.tellerlinenumber].getFirst.serviceDuration + globalclock);
      eventque->add(tellerevent);
      eventque->remove(E);
    }





    printf("Total Customers Served: %i\n", totalCustomersServed);
    printf("Total Number of Tellers: %i\n", numTellers);
    printf("Average Time in Bank: %i  With Standard Deviation %d \n", totalCustomerMinutes/totalCustomersServed, standardDeviation);
    printf("Maximum Wait Time: %d\n", maximumWaitTime);
    printf("Total Service Time: %d\n", totalServiceTime);
    printf("Total Idle Time: %d\n", totalIdleTime);

  }
}
