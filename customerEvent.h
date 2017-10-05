#include "event.h"

class CustomerEvent : public Event{

public:
  CustomerEvent(double arrivalTime, double serviceDuration);
  double arrivalTime;
  double serviceDuration;
  double completionTime;
  int action();
  int isCustomer();
  double getArrivalTime();
  double getCompletionTime();
  double getServiceDuration();
};
