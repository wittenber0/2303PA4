#include "headerheader.cpp"

class TQNode{
public:
  Customer customer;
  TQNode* previous;
  TQNode* next;
  TQNode(Customer c, TQNode* p, TQNode* n);
}

class TellerQue{
public:
  TellerQue();
  int add(Customer c);
  int remove(Customer c);
  TQNode* getFirst();
  TQNode* getLast();


private:
  TQNode* first, last, current;
  int deleteNode(TQNode* n);
  int removeHelp(TQNode* n, Customer c);
}
