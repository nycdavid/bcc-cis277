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
void StatusCheck(Queue& q);

void StatusCheck(Queue& q) {
  std::string empty = ((Empty(q)) ? "EMPTY" : "NOT EMPTY");
  int back = ((q.Back == -1) ? 0 : q.container[q.Back]);

  std::cout << "The front element is: " << q.container[0] << std::endl;
  std::cout << "The back element is: " << back << std::endl;
  std::cout << "The queue is: " << empty << std::endl;
}

int main() {
  Queue myQ;
  Enqueue(myQ, 1337);
  Enqueue(myQ, 818);
  StatusCheck(myQ);
  Enqueue(myQ, 817);
  StatusCheck(myQ);
  Enqueue(myQ, 816);
  StatusCheck(myQ);
  Enqueue(myQ, 815);
  StatusCheck(myQ);

  Dequeue(myQ);
  StatusCheck(myQ);

  Purge(myQ);
  StatusCheck(myQ);

  return 0;
}

void Enqueue(Queue& q, QEl el) {
  q.Back += 1;
  q.container[q.Back] = el;
}

QEl Dequeue(Queue& q) {
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
