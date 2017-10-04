class Node{
public:
  Event event;
  Node* previous;
  Node* next;
  Node(Event e, Node* p, Node* n);
};

class LinkedList{


public:
  LinkedList();

  int add(Event e);
  int remove(Event e);
  Node* getFirst();
  Node* getLast();

private:
  Node* first, last;
  Node* current;
  int deleteNode(Node* n);
  int removeHelp(Node*, Event);
  
};
