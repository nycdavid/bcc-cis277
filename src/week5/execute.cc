#include <iostream>
#include <string>

struct Stack {
  int count = 0;
  int elements[10];
};

void push(Stack& s, int el);
int pop(Stack& s);
int top(Stack& s);

int main() {
  Stack myStack;
  push(myStack, 8);
  // push(myStack, 18);
  // push(myStack, 15);
  // push(myStack, 7);
  pop(myStack);
  pop(myStack);
  // pop(myStack);
  // push(myStack, 7);

  std::cout << "Top of stack is: " << top(myStack) << std::endl;
  std::cout << "Number of elements is: " << myStack.count << std::endl;
  return 0;
}

void push(Stack& s, int el) {
  s.elements[s.count] = el;
  s.count += 1;
}

int pop(Stack& s) {
  if (s.count == 0) {

  } else {
    int topEl = s.elements[s.count - 1];
    s.elements[s.count - 1] = 0;
    s.count -= 1;
    return topEl;
  }
}

int top(Stack& s) {
  return s.elements[s.count - 1];
}

// void purge(Stack& s) {
//   s.cout = 0;
// }
