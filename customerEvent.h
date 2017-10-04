#include "headerheader.h"

class CustomerEvent : public Event{
private:
  int arrivalTime;
  int serviceTime;
  int completeTime;
public:
  CustomerEvent(int time);
  int action();
};
