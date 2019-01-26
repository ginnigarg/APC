typedef struct Node {
  int data;
  struct Node * next;
}Node;

Node* reverse(Node* first) {
  Node* second = NULL;
  if(first != NULL) {
    second = first->next;
  }
  if(second == NULL) {
    return first;
  }
  Node* curr = reverse(second);
  first->next = second->next;
  second->next = first;
  return curr;
}

