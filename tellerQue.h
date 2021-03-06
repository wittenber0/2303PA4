#include "customerEvent.h"


class TQNode{
public:
  CustomerEvent customerevent;
  TQNode* previous;
  TQNode* next;
  TQNode(CustomerEvent c, TQNode* p, TQNode* n);
};

class TellerQue{
public:
  double avalibleTime;
  TellerQue();
  int add(CustomerEvent c);
  int remove(CustomerEvent c);
  int getSize();
  TQNode* getFirst();
  TQNode* getLast();
  double getAvalible();
  int idle(double duration);


private:

  int size;
  TQNode* first, last, current;
  int deleteNode(TQNode* n);
  int removeHelp(TQNode* n, CustomerEvent c);
  int addHelper(TQNode* n, CustomerEvent c);
};
