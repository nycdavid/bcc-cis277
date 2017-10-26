#include <iostream>

typedef int QEl;

struct Queue {
  QEl container[30];
  int Back = -1;
};

void Enqueue(Queue& q, QEl el);
QEl Dequeue(Queue& q);
bool Empty(Queue& q);
void Purge(Queue& q);
Queue CreateQueue();

void StatusCheck(Queue& q);

void StatusCheck(Queue& q) {
  std::cout << std::endl;
  std::cout << "================" << std::endl;
  std::cout << std::endl;

  std::string empty = ((Empty(q)) ? "EMPTY" : "NOT EMPTY");
  int back = ((q.Back == -1) ? 0 : q.container[q.Back]);

  std::cout << "The front element is: " << q.container[0] << std::endl;
  std::cout << "The back element is: " << back << std::endl;
  std::cout << "Contents of the queue: " << std::endl;
  std::cout << "| ";
  for (int i = 0; i < q.Back + 1; ++i) {
    std::cout << q.container[i] << " | ";
  }
  std::cout << std::endl;
  std::cout << "The queue is: " << empty << std::endl;
}

int main() {
  std::cout << "Welcome to the Queue program!" << std::endl;
  Queue myQ = CreateQueue();
  StatusCheck(myQ);
  Dequeue(myQ);
  StatusCheck(myQ);
  return 0;
}

Queue CreateQueue() {
  int noOfItems;
  Queue newQ;
  std::cout << "How many items in the Queue? ";
  std::cin >> noOfItems;
  for (int i = 0; i < noOfItems; ++i) {
    QEl item;
    std::cout << "Enter item: ";
    std::cin >> item;
    Enqueue(newQ, item);
  }
  return newQ;
}

void Enqueue(Queue& q, QEl el) {
  std::cout << "Enqueueing item..." << std::endl;
  q.Back += 1;
  q.container[q.Back] = el;
}

QEl Dequeue(Queue& q) {
  std::cout << "Dequeueing item..." << std::endl;
  QEl front = q.container[0];
  q.container[0] = NULL;
  for (int i = 1; i < 30; ++i) {
    int prev = i - 1;
    q.container[prev] = q.container[i];
  }
  q.Back -= 1;
  return front;
}

bool Empty(Queue& q) {
  bool empty = ((q.Back == -1) ? true : false);
  return empty;
}

void Purge(Queue& q) {
  std::cout << "Purging the Queue..." << std::endl;
  q.Back = -1;
  for (int i = 0; i < 30; ++i) {
    q.container[i] = NULL;
  }
}
