//#include "event.h"
//#include "headerheader.h"

class TellerEvent : public Event{
public:
  TellerEvent(double occuranceTime);
  int action();
  double idle();
  double getDuration();


private:
  double occuranceTime, duration;
};
