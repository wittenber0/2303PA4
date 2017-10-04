#include "event.h"
//#include "headerheader.h"

class TellerEvent : public Event{
public:
  TellerEvent(double occuranceTime, double duration);
  int action();

private:
  double occuranceTime, duration;
}
