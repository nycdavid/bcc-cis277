#include <iostream>
#include <sstream>

struct Matrix {
  double values[2][2];
};

void calc_sum();
void show_menu();
void print_matrix(Matrix m);
Matrix get_matrix();

int main() {
  std::string input;
  int menuChoice;
  std::cout << "Welcome to the Matrix program!" << std::endl;
  show_menu();
  getline(std::cin, input);
  std::stringstream inputStream(input);
  inputStream >> menuChoice;

  switch(menuChoice) {
    case 1:
      std::cout << std::endl;
      std::cout << "You chose:" << std::endl;
      calc_sum();
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
    default:
      std::cout << "Invalid choice." << std::endl;
      break;
  }
  std::cout << "Exiting program." << std::endl;
  return 0;
}

void calc_sum() {
  std::cout << "             _     _ _ _   _             " << std::endl;
  std::cout << "    /\\      | |   | (_) | (_)            " << std::endl;
  std::cout << "   /  \\   __| | __| |_| |_ _  ___  _ __  " << std::endl;
  std::cout << "  / /\\ \\ / _` |/ _` | | __| |/ _ \\| '_ \\ " << std::endl;
  std::cout << " / ____ \\ (_| | (_| | | |_| | (_) | | | |" << std::endl;
  std::cout << "/_/    \\_\\__,_|\\__,_|_|\\__|_|\\___/|_| |_|" << std::endl;
  std::cout << "#########################################" << std::endl;

  Matrix m1 = get_matrix();
  print_matrix(m1);
  Matrix m2 = get_matrix();
  print_matrix(m2);
  Matrix result;

  result.values[0][0] = m1.values[0][0] + m2.values[0][0];
  result.values[0][1] = m1.values[0][1] + m2.values[0][1];
  result.values[1][0] = m1.values[1][0] + m2.values[1][0];
  result.values[1][1] = m1.values[1][1] + m2.values[1][1];

  std::cout << "Sum of the 2 matrices: " << std::endl;
  print_matrix(result);
}

Matrix get_matrix() {
  Matrix new_m;
  std::string name;
  std::cout << "Enter a matrix name: ";
  std::cin >> name;
  std::cout << std::endl;

  std::cout << "Please enter value for matrix " << name << " at (1, 1): ";
  std::cin >> new_m.values[0][0];

  std::cout << "Please enter value for matrix " << name << " at (1, 2): ";
  std::cin >> new_m.values[0][1];

  std::cout << "Please enter value for matrix " << name << " at (2, 1): ";
  std::cin >> new_m.values[1][0];

  std::cout << "Please enter value for matrix " << name << " at (2, 2): ";
  std::cin >> new_m.values[1][1];
  std::cout << std::endl;

  return new_m;
}

void print_matrix(Matrix m) {
  std::cout << "Matrix Values:" << std::endl;
  std::cout << "[  " << m.values[0][0] << "    " << m.values[0][1] << "  ]" << std::endl;
  std::cout << "[  " << m.values[1][0] << "    " << m.values[1][1] << "  ]" << std::endl;
  std::cout << std::endl;
}

/**
**/
void show_menu() {
  std::cout << std::endl;
  std::cout << "Options:" << std::endl;
  std::cout << "1) Matrix Addition" << std::endl;
  std::cout << "2) Matrix Subtraction" << std::endl;
  std::cout << "3) Matrix Multiplication" << std::endl;
  std::cout << "4) Matrix Inversion" << std::endl;
  std::cout << "5) Matrix Scalar Matrix Multiplication" << std::endl;
  std::cout << "6) Exit" << std::endl;
  std::cout << std::endl;
  std::cout << "Please choose your Matrix operation: ";
}
