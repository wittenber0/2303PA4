//#include "event.h"

class ENode{
public:
  Event event;
  ENode* previous;
  ENode* next;
  ENode(Event e, ENode* p, ENode* n);
};

class EventQue{
private:
  ENode* first, last;
  ENode* current;
  int deleteNode(ENode* n);
  int removeHelp(ENode* n, Event e);
  int addHelp(ENode* n, Event e);

public:
  EventQue();
  int add(Event e);
  int remove(Event e);
  ENode* getFirst();
  ENode* getLast();

};
