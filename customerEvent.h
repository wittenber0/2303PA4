#include "headerheader.h"

class CustomerEvent : public Event{
private:
  double arrivalTime;
  double serviceDuration;
  double completionTime;
public:
  CustomerEvent(arrivalTime, serviceDuration);
  int action();
};
