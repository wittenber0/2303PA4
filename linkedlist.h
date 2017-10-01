class LinkedList{
private:
  Node first, last;
  Node* current;

public:
  LinkedList(){
  }

  int add(Event e);
  int remove(Event e);
}
