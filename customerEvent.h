//#include "headerheader.h"
#include "event.h"

class CustomerEvent : public Event{
private:
  double arrivalTime;
  double serviceDuration;
  double completionTime;
public:
  CustomerEvent(double arrivalTime, double serviceDuration);
  int action();
};
