#include "event.h"


class TQNode{
public:
  Event customerevent;
  TQNode* previous;
  TQNode* next;
  TQNode(Event c, TQNode* p, TQNode* n);
};

class TellerQue{
public:
  double avalibleTime;
  TellerQue();
  int add(Event c);
  int remove(Event c);
  int getSize();
  TQNode* getFirst();
  TQNode* getLast();
  double getAvalible();
  int idle(double duration);


private:

  int size;
  TQNode* first, last, current;
  int deleteNode(TQNode* n);
  int removeHelp(TQNode* n, Event c);
  int addHelper(TQNode* n, Event c);
};
