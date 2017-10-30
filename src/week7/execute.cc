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
void AddToHead(Node* head, int el);

int main() {
  List lst;
  Node tail = { 68, NULL };
  Node body = { 500, &tail };
  Node hd = { 818, &body };
  lst.head = &hd;

  PrintList(lst);

  // Add to head of list;
  AddToHead(lst.head, 4346); // | 4346 | 818 | 500 | 68 |
  PrintList(lst);
}

void AddToHead(Node* head, int el) {
  Node* headNode = head;
  Node newNode = { el, headNode };
  head = &newNode;
}

void PrintList(List& lst) {
  Node* temp;
  temp = lst.head;
  cout << "|";
  do {
    cout << " " << temp->data << " |";
    temp = temp->next;
  } while (temp != NULL);
  cout << endl;
}
