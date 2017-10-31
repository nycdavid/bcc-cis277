#include <iostream>

using namespace std;

struct Node {
  int data;
  Node* next;
};

struct List {
  Node* head;
  Node* tail;
};

void PrintList(List& lst);
void AddToHead(Node*& head, int el);

int main() {
  List lst;
  Node* tail = new Node;
  tail->data = 68;
  tail->next = NULL;
  lst.tail = tail;
  lst.head = tail;

  // Add to head of list;
  AddToHead(lst.head, 500); // | 4346 | 818 | 500 | 68 |
  AddToHead(lst.head, 818); // | 4346 | 818 | 500 | 68 |
  AddToHead(lst.head, 4346); // | 4346 | 818 | 500 | 68 |
  AddToHead(lst.head, 6400); // | 4346 | 818 | 500 | 68 |

  PrintList(lst);
}

void AddToHead(Node*& head, int el) {
  Node* newNode = new Node;
  newNode->data = el;
  newNode->next = head;
  head = newNode;
}

void PrintList(List& lst) {
  Node* temp;
  int data;
  do {
    data = temp->data;
    cout << " | "<< data;
    temp = temp->next;
  } while (temp != NULL);
  cout << " |" << endl;
}
