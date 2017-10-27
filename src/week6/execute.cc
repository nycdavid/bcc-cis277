#include <iostream>
#include <sstream>

typedef int QEl;

struct Queue {
  QEl container[30];
  int Back = -1;
  std::string Name;
};

void Enqueue(Queue* q);
QEl Dequeue(Queue* q);
bool Empty(Queue* q);
void Purge(Queue* q);
Queue CreateQueue();
void PrintQueue(Queue* q);
void ShowMenu();
int ChooseQueue(Queue allQs[]);

void PrintQueue(Queue* q) {
  std::cout << std::endl;
  std::cout << "================" << std::endl;
  std::cout << std::endl;

  std::string empty = ((Empty(q)) ? "EMPTY" : "NOT EMPTY");
  int back = ((q->Back == -1) ? 0 : q->container[q->Back]);

  std::cout << "The front element is: " << q->container[0] << std::endl;
  std::cout << "The back element is: " << back << std::endl;
  std::cout << "Contents of the queue: " << std::endl;
  std::cout << "| ";
  for (int i = 0; i < q->Back + 1; ++i) {
    std::cout << q->container[i] << " | ";
  }
  std::cout << std::endl;
  std::cout << "The queue is: " << empty << std::endl;
}

int ChooseQueue(Queue allQs[]) {
  int qChoice = 0;
  for (int i = 0; i < 4; ++i) {
    std::cout << i + 1 << ") " << allQs[i].Name << std::endl;
  }
  std::cout << "Please choose a Queue: ";
  std::string input;
  getline(std::cin, input);
  std::stringstream inputStream(input);
  inputStream >> qChoice;
  return qChoice - 1;
}

int main() {
  std::string input;
  bool keepAlive = true;
  int menuChoice;
  std::cout << "Welcome to the Queue program!" << std::endl;
  Queue q1 = CreateQueue();
  Queue q2 = CreateQueue();
  Queue q3 = CreateQueue();
  Queue q4 = CreateQueue();
  Queue allQueues[4] = { q1, q2, q3, q4 };
  do {
    menuChoice = 0;
    ShowMenu();

    getline(std::cin, input);
    std::stringstream inputStream(input);
    inputStream >> menuChoice;
    Queue* chosenQ;
    if (menuChoice != 8) {
      int qIdx = ChooseQueue(allQueues);
      chosenQ = &allQueues[qIdx];
    }

    switch(menuChoice) {
      case 0:
        break;
      case 1:
        std::cout << std::endl;
        std::cout << "You chose: ";
        std::cout << "Enqueueing" << std::endl;
        std::cout << "=========================" << std::endl;
        Enqueue(chosenQ);
        break;
      case 2:
        std::cout << std::endl;
        std::cout << "You chose: ";
        std::cout << "Dequeueing" << std::endl;
        std::cout << "=========================" << std::endl;
        Dequeue(chosenQ);
        break;
      case 3:
        std::cout << std::endl;
        std::cout << "You chose: ";
        std::cout << "Print Queue" << std::endl;
        std::cout << "=========================" << std::endl;
        PrintQueue(chosenQ);
        break;
      case 4:
        std::cout << std::endl;
        std::cout << "You chose: ";
        std::cout << "Purge Queue" << std::endl;
        std::cout << "=========================" << std::endl;
        Purge(chosenQ);
        break;
      case 8:
        std::cout << std::endl;
        std::cout << "You chose: EXIT" << std::endl;
        keepAlive = false;
        break;
      default:
        std::cout << "Invalid choice." << std::endl;
        break;
    }
  } while (keepAlive);
  std::cout << "Exiting program." << std::endl;
  return 0;
}

void ShowMenu() {
  std::cout << std::endl;
  std::cout << "Options:" << std::endl;
  std::cout << "1) Enqueue to a Queue" << std::endl;
  std::cout << "2) Dequeue from a Queue" << std::endl;
  std::cout << "3) Show Queue Status" << std::endl;
  std::cout << "4) Purge Queue" << std::endl;
  std::cout << "8) Exit" << std::endl;
  std::cout << "Please choose your Queue operation: ";
}

Queue CreateQueue() {
  std::cout << "Create Queue" << std::endl;
  std::string name;
  int noOfItems;
  Queue newQ;
  std::cout << "What's the name of the Queue? ";
  std::string input;
  getline(std::cin, input);
  std::stringstream inputStream(input);
  inputStream >> name;
  newQ.Name = name;
  std::cout << "How many items in the Queue? ";
  std::string itemsIpt;
  getline(std::cin, itemsIpt);
  std::stringstream itemsInputStream(itemsIpt);
  itemsInputStream >> noOfItems;
  for (int i = 0; i < noOfItems; ++i) {
    Enqueue(&newQ);
  }
  return newQ;
}

void Enqueue(Queue* q) {
  QEl item;
  std::cout << "Enter item: ";
  std::string input;
  getline(std::cin, input);
  std::stringstream inputStream(input);
  inputStream >> item;
  std::cout << "Enqueueing item..." << std::endl;
  q->Back += 1;
  q->container[q->Back] = item;
}

QEl Dequeue(Queue* q) {
  std::cout << "Dequeueing item..." << std::endl;
  QEl front = q->container[0];
  q->container[0] = NULL;
  for (int i = 1; i < 30; ++i) {
    int prev = i - 1;
    q->container[prev] = q->container[i];
  }
  q->Back -= 1;
  return front;
}

bool Empty(Queue* q) {
  bool empty = ((q->Back == -1) ? true : false);
  return empty;
}

void Purge(Queue* q) {
  std::cout << "Purging the Queue..." << std::endl;
  q->Back = -1;
  for (int i = 0; i < 30; ++i) {
    q->container[i] = 0;
  }
}
