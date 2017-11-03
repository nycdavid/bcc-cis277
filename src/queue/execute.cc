#include <iostream>

using namespace std;

struct Node {
  int data;
  Node* next;
};

struct Queue {
  Node* back;
  Node* front;
};

void Print(Queue& q);
void Enqueue(Queue& q, int el);
void Dequeue(Queue& q);

int main() {
  Queue q;
  Node* el = new Node;
  el->data = 10;
  el->next = NULL;
  q.front = el;
  // Print(q); // 10
  Enqueue(q, 20);
  // Print(q); // 10 | 20
  Enqueue(q, 30);
  // Print(q); // 10 | 20 | 30

  Dequeue(q);
  Print(q); // 10 | 20 |
}

void Print(Queue& q) {
  Node* temp = q.front;
  if (temp->next != NULL) {
    do {
      cout << temp->data << " | ";
      temp = temp->next;
    } while(temp != NULL);
  } else {
    cout << "Item is: " << temp->data << endl;
  }
}

void Enqueue(Queue& q, int el) {
  Node* temp = q.front;
  if (temp->next != NULL) {
    do {
      temp = temp->next;
    } while(temp->next != NULL);
  }
  Node* newEl = new Node;
  newEl->data = el;
  newEl->next = NULL;
  temp->next = newEl;
}

void Dequeue(Queue& q) {
  Node* temp = q.front;
  do {
    temp = temp->next;
  } while(temp->next->next != NULL);
  temp->next = NULL;
}
