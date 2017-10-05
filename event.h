//#include "statistics.h"

class Event{
private:


public:
  Event(int t);
  int action();
  int time;
  virtual int isCustomer();
};
