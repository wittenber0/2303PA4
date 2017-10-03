class Event{
private:
  int time;

public:
  Event(int t);
  int getTime();
  int addToTail(LinkedList q);
  int removeFromHead(LinkedList q);
  int action();
};
