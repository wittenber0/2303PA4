//#include "headerheader.h"
#include "customerEvent.h"
#include "tellerEvent.h"


class TQNode{
public:
  CustomerEvent customerevent;
  TQNode* previous;
  TQNode* next;
  TQNode(CustomerEvent c, TQNode* p, TQNode* n);
}

class TellerQue{
public:
  TellerQue(int id);
  int add(CustomerEvent c);
  int remove(CustomerEvent c);
  int getSize();
  TQNode* getFirst();
  TQNode* getLast();
  double getAvalible();
  int idle(TellerEvent* t);


private:
  double avalibleTime;
  int size;
  int id;
  TQNode* first, last, current;
  int deleteNode(TQNode* n);
  int removeHelp(TQNode* n, CustomerEvent c);
};
