

struct node{
  Event event;
  node* previous;
  node* next;
}

typedef struct node Node;

int LinkedList::add(Event e){
  Node* n = new Node(e, this.last, 0);
  this.last.next = n;
  return 0;
}

int LinkedList::deleteNode(Node n){
  //deleteNode From memory still needs to be done here
  n.previous->next = n.next;
}

int LinkedList::removeHelp(Node* n, Event e){
  Node node = *n;
  if(node.event == e){
    deleteNode(n);
    return 1;
  }

  if(node.next){
    removeHelp(node.next);
  }

  return 0;
}


int LinkedList::remove(Event e){
  this.current = &this.first;
  removeHelp(this.current, Event e);

}



Node* LinkedList::getNextNode(){
  Node* n = this.current++;
  return n;
}
