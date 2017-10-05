//#include "event.h"
//#include "headerheader.h"

class TellerEvent : public Event{
public:
  TellerEvent(double occuranceTime, double duration);
  int action();
  double idle();
  double getDuration();


private:
  double occuranceTime, duration;
};
