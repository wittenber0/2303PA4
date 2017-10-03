#include "headerheader.h"

class CustomerEvent : public Event{
private:
  int startTime;
  int completeTime;
public:
  CustomerEvent(int time);
  int action();
};
