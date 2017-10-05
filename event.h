

class Event{
private:


public:
  Event(double t);
  virtual int action();
  double time;
  virtual int isCustomer();
};
