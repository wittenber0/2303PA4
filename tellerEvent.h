#include "event.h"

class TellerEvent : public Event{
public:
  TellerEvent(double occuranceTime);
  int action();
  double idle();
  double getDuration();


private:
  double occuranceTime, duration;
};
