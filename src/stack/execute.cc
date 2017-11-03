#include <iostream>

using namespace std;

struct Node {
  int data;
  Node* next;
};

struct Stack {
  Node* top;
};

void Push(Stack& s, int el);
void Pop(Stack& s);
void Print(Stack& s);
void Top(Stack& s);

int main() {
  Stack s;
  Node* el = new Node;
  el->data = 10;
  el->next = NULL;
  s.top = el;

  Push(s, 8);
  Push(s, 500);
  Pop(s);
  Print(s);
}

void Print(Stack& s) {
  Node* temp = s.top;
  if (temp->next != NULL) {
    do {
      cout << "Data: " << temp->data << endl;
      temp = temp->next;
    } while(temp != NULL);
  } else {
    cout << "Data: " << temp->data << endl;
  }
}

void Push(Stack& s, int el) {
  Node* oldNode = s.top;
  Node* newNode = new Node;
  newNode->data = el;
  newNode->next = s.top;
  s.top = newNode;
}

void Top(Stack& s) {
  cout << "Top is: " << s.top->data << endl;
}

void Pop(Stack& s) {
  s.top = s.top->next;
}
