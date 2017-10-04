#include "headerheader.h"
#include <cstdlib>
double globalclock;

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
  if(argc > 4)
{
    int numCustomers = argv[2];
    int numTellers = argv[3];
    int simTime = argv[4];
    float averageTime = argv[5]
    float arrTime = 0;

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
    arrTime = simTime * rand()/float(RAND_MAX);
    CustomerEvent customerevent = new CustomerEvent(arrTime);
    //add handling starting ....
    eventque->add(customerevent);
}

for (globalclock =0; globalclock<simTime; globalclock += 0.1)
{
      //add handling starting ....
      Event* E = eventque.getFirst;
      if (E->iscustomer)
      {
        TellerQue* smallest = tellerlist->getSmallestTeller();
        smallest->add(E);
      }

      for(int i=0; i< numTellers; i++){
        TellerQue currentTeller = tellerlist;
        if(i!=0){
          currentTeller++;
        }
        if(currentTeller->getFirst()){
        CustomerEvent* T = currentTeller->getFirst()
          if(T->arrivalTime == globalclock){
            completiontime = T->arrivalTime + T->serviceTime;
            TellerEvent* tellerevent = new TellerEvent(completiontime);
            eventque->add(tellerevent);
            T->action();
            currentTeller->remove(T);
            eventque->remove(T);

          }
        }else{
          TellerEvent* idleEvent = new TellerEvent(globalclock);
          idleEvent.idle();
          eventque.add(idleEvent);
        }
      }








    //     if (E->arrivalTime == globalclock)
    //     {
    //
    //       completiontime = E->arrivalTime + E->serviceTime;
    //       TellerEvent* tellerevent = new TellerEvent(completiontime);
    //       eventque->add(tellerevent);
    //       E->action();
    //       eventque->remove(E);
    //     }
    //   }
    // else
    // {
    // if (E->arrivalTime == globalclock)
    // {
    //
    // }
  }
}


//TellerQue* smallest = getSmallestTeller(tellerlist, numTellers);








}
else
{
  //too few arg
}





}
