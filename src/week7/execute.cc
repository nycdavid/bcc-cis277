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
void AddToTail(Node*& head, int el);
void Insert(Node*& head, int el, int idx);

int main() {
  List lst;
  Node* tail = new Node;
  tail->data = 68;
  tail->next = NULL;
  lst.tail = tail;
  lst.head = tail;

  // Add to head of list;
  AddToHead(lst.head, 500); // | 500 | 68 |
  PrintList(lst);
  AddToHead(lst.head, 818); // | 818 | 500 | 68 |
  PrintList(lst);
  AddToHead(lst.head, 4346); // | 4346 | 818 | 500 | 68 |
  PrintList(lst);
  AddToHead(lst.head, 6400); // | 6400 | 4346 | 818 | 500 | 68 |
  PrintList(lst);
  AddToTail(lst.head, 9000); // | 6400 | 4346 | 818 | 500 | 68 | 9000 |
  PrintList(lst);

  Insert(lst.head, 989, 2);
  PrintList(lst); // | 6400 | 4346 | 989 | 818 | 500 | 68 | 9000 |
}

void Insert(Node*& head, int el, int idx) {
  int counter = 0;
  Node* newNode = new Node;
  newNode->data = el;
  Node* nextNode = head;
  do {
    nextNode = nextNode->next;
    counter += 1;
  } while ((counter + 1) != idx);
  newNode->next = nextNode->next;
  nextNode->next = newNode;
}

void AddToHead(Node*& head, int el) {
  Node* newNode = new Node;
  newNode->data = el;
  newNode->next = head;
  head = newNode;
}

void AddToTail(Node*& head, int el) {
  Node* temp = head;
  do {
    temp = temp->next;
  } while(temp->next != NULL);
  Node* newNode = new Node;
  newNode->data = el;
  newNode->next = NULL;
  temp->next = newNode;
}

void PrintList(List& lst) {
  Node* temp = lst.head;
  int data;
  do {
    data = temp->data;
    cout << " | "<< data;
    temp = temp->next;
  } while (temp != NULL);
  cout << " |" << endl;
}
