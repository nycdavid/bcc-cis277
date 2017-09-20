#include <iostream>
#include <sstream>

struct Matrix {
  int values[2][2];
};

int main() {
  std::string input;
  int menuChoice;
  std::cout << "Welcome to the Matrix program!" << std::endl;

  while (menuChoice != 6) {
    std::cout << "Please choose your Matrix operation: ";
    getline(std::cin, input);
    std::stringstream inputStream(input);
    inputStream >> menuChoice;

    switch(menuChoice) {
      case 1:
        std::cout << "You chose: Matrix Addition." << std::endl;
        break;
      case 2:
        std::cout << "You chose: Matrix Subtraction." << std::endl;
        break;
      case 3:
        std::cout << "You chose: Matrix Multiplication." << std::endl;
        break;
      case 4:
        std::cout << "You chose: Matrix Inversion." << std::endl;
        break;
      case 5:
        std::cout << "You chose: Scalar Matrix Multiplication." << std::endl;
        break;
      case 6:
        std::cout << "Exiting program." << std::endl;
        break;
      default:
        std::cout << "Invalid choice." << std::endl;
        break;
    }
  }
  return 0;
}
