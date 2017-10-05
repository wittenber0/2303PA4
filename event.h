#ifndef EV
#define EV
class Event{
private:

public:
  Event(double arrivalTime, double serviceDuration);
  double arrivalTime;
  double serviceDuration;
  double completionTime;
  virtual int action();
  virtual int isCustomer();

};

#endif
