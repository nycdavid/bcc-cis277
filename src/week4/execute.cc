#include <iostream>
#include <sstream>

struct Matrix {
  double values[2][2];
};

void calc_sum();
void calc_diff();
void calc_scalar_multiplication();
void calc_matrix_multiplication();
void calc_matrix_inversion();
void show_menu();
void print_matrix(Matrix m);
Matrix get_matrix();

/***************************************************
  Function: main executes the menu and triggers the correct function according to the user's choice
  called by: N/A
  Function Parameters: N/A
  Function Return Type: N/A
***************************************************/
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
      std::cout << std::endl;
      std::cout << "You chose:" << std::endl;
      calc_diff();
      break;
    case 3:
      std::cout << std::endl;
      std::cout << "You chose:" << std::endl;
      calc_scalar_multiplication();
      break;
    case 4:
      std::cout << std::endl;
      std::cout << "You chose:" << std::endl;
      calc_matrix_multiplication();
      break;
    case 5:
      std::cout << std::endl;
      std::cout << "You chose:" << std::endl;
      calc_matrix_inversion();
      break;
    case 6:
      break;
    default:
      std::cout << "Invalid choice." << std::endl;
      break;
  }
  std::cout << "Exiting program." << std::endl;
  return 0;
}

/***************************************************
  Function: calc_sum allows the user to enter 2 matrices, sums them together and displays the result
  called by: main
  Function Parameters: none
  Function Return Type: void
***************************************************/
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

/***************************************************
  Function: calc_diff allows the user to enter 2 matrices, subtracts them and displays the result
  called by: main
  Function Parameters: none
  Function Return Type: void
***************************************************/
void calc_diff() {
  std::cout << "  _____       _     _                  _   _             " << std::endl;
  std::cout << " / ____|     | |   | |                | | (_) " << std::endl;
  std::cout << "| (___  _   _| |__ | |_ _ __ __ _  ___| |_ _  ___  _ __ " << std::endl;
  std::cout << " \\___ \\| | | | '_ \\| __| '__/ _` |/ __| __| |/ _ \\| '_ \\" << std::endl;
  std::cout << " ____) | |_| | |_) | |_| | | (_| | (__| |_| | (_) | | | |" << std::endl;
  std::cout << "|_____/ \\__,_|_.__/ \\__|_|  \\__,_|\\___|\\__|_|\\___/|_| |_|" << std::endl;
  std::cout << "#########################################################" << std::endl;

  Matrix m1 = get_matrix();
  print_matrix(m1);
  Matrix m2 = get_matrix();
  print_matrix(m2);
  Matrix result;

  result.values[0][0] = m1.values[0][0] - m2.values[0][0];
  result.values[0][1] = m1.values[0][1] - m2.values[0][1];
  result.values[1][0] = m1.values[1][0] - m2.values[1][0];
  result.values[1][1] = m1.values[1][1] - m2.values[1][1];

  std::cout << "Difference of the 2 matrices: " << std::endl;
  print_matrix(result);
}

/***************************************************
  Function: calc_scalar_multiplication allows the user to enter 1 matrix, and a scalar multiple.
  it then multiplies the scalar and the matrix and displays the result
  called by: main
  Function Parameters: none
  Function Return Type: void
***************************************************/
void calc_scalar_multiplication() {
  std::cout << "     _____           _                                         " << std::endl;
  std::cout << "    / ____|         | |" << std::endl;
  std::cout << "   | (___   ___ __ _| | __ _ _ __" << std::endl;
  std::cout << "    \\___ \\ / __/ _` | |/ _` | '__|" << std::endl;
  std::cout << "    ____) | (_| (_| | | (_| | |" << std::endl;
  std::cout << "   |_____/ \\___\\__,_|_|\\__,_|_|_ _           _   _" << std::endl;
  std::cout << "   |  \\/  |     | | | (_)     | (_)         | | (_)" << std::endl;
  std::cout << "   | \\  / |_   _| | |_ _ _ __ | |_  ___ __ _| |_ _  ___  _ __" << std::endl;
  std::cout << "   | |\\/| | | | | | __| | '_ \\| | |/ __/ _` | __| |/ _ \\| '_ \\" << std::endl;
  std::cout << "   | |  | | |_| | | |_| | |_) | | | (_| (_| | |_| | (_) | | | |" << std::endl;
  std::cout << "   |_|  |_|\\__,_|_|\\__|_| .__/|_|_|\\___\\__,_|\\__|_|\\___/|_| |_|" << std::endl;
  std::cout << "                        | |" << std::endl;
  std::cout << "                        |_|" << std::endl;

  double k;
  Matrix m1 = get_matrix();
  print_matrix(m1);
  Matrix result;
  std::cout << "Enter scalar value: ";
  std::cin >> k;
  std::cout << std::endl;

  result.values[0][0] = k * m1.values[0][0];
  result.values[0][1] = k * m1.values[0][1];
  result.values[1][0] = k * m1.values[1][0];
  result.values[1][1] = k * m1.values[1][1];
  std::cout << "Scalar multiplication of scalar k & matrix: " << std::endl;
  print_matrix(result);
}

/***************************************************
  Function: calc_matrix_multiplication allows the user to enter 2 matrices, and  multiplies them together.
  it then displays the result
  called by: main
  Function Parameters: none
  Function Return Type: void
***************************************************/
void calc_matrix_multiplication() {
  std::cout << "     __  __       _        _                                    " << std::endl;
  std::cout << "    |  \\/  |     | |      (_)                                   " << std::endl;
  std::cout << "    | \\  / | __ _| |_ _ __ ___  __                              " << std::endl;
  std::cout << "    | |\\/| |/ _` | __| '__| \\ \\/ /                              " << std::endl;
  std::cout << "    | |  | | (_| | |_| |  | |>  <                               " << std::endl;
  std::cout << "    |_|  |_|\\__,_|\\__|_|_ |_/_/\\_\\_           _   _             " << std::endl;
  std::cout << "    |  \\/  |     | | | (_)     | (_)         | | (_)            " << std::endl;
  std::cout << "    | \\  / |_   _| | |_ _ _ __ | |_  ___ __ _| |_ _  ___  _ __  " << std::endl;
  std::cout << "    | |\\/| | | | | | __| | '_ \\| | |/ __/ _` | __| |/ _ \\| '_ \\ " << std::endl;
  std::cout << "    | |  | | |_| | | |_| | |_) | | | (_| (_| | |_| | (_) | | | |" << std::endl;
  std::cout << "    |_|  |_|\\__,_|_|\\__|_| .__/|_|_|\\___\\__,_|\\__|_|\\___/|_| |_|" << std::endl;
  std::cout << "                         | |                                    " << std::endl;
  std::cout << "                         |_|                                      " << std::endl;

  Matrix m1 = get_matrix();
  print_matrix(m1);
  Matrix m2 = get_matrix();
  print_matrix(m2);
  Matrix result;

  result.values[0][0] = (m1.values[0][0] * m2.values[0][0]) + (m1.values[0][1] * m2.values[1][0]);
  result.values[0][1] = (m1.values[0][0] * m2.values[0][1]) + (m1.values[0][1] * m2.values[1][1]);
  result.values[1][0] = (m1.values[1][0] * m2.values[0][0]) + (m1.values[1][1] * m2.values[1][0]);
  result.values[1][1] = (m1.values[1][0] * m2.values[0][1]) + (m1.values[1][1] * m2.values[1][1]);
  std::cout << "Multiplication of matrices:" << std::endl;
  print_matrix(result);
}

/***************************************************
  Function: calc_matrix_inversion allows the user to enter 1 matrix, and calculates the determinant.
  it then inverts the matrix using the determinant and displays the result
  called by: main
  Function Parameters: none
  Function Return Type: void
***************************************************/
void calc_matrix_inversion() {
  std::cout << "   __  __       _        _                     " << std::endl;
  std::cout << "  |  \\/  |     | |      (_)                    " << std::endl;
  std::cout << "  | \\  / | __ _| |_ _ __ ___  __               " << std::endl;
  std::cout << "  | |\\/| |/ _` | __| '__| \\ \\/ /               " << std::endl;
  std::cout << "  | |  | | (_| | |_| |  | |>  <                " << std::endl;
  std::cout << "  |_|__|_|\\__,_|\\__|_|  |_/_/\\_\\ _             " << std::endl;
  std::cout << "  |_   _|                       (_)            " << std::endl;
  std::cout << "    | |  _ ____   _____ _ __ ___ _  ___  _ __  " << std::endl;
  std::cout << "    | | | '_ \\ \\ / / _ \\ '__/ __| |/ _ \\| '_ \\ " << std::endl;
  std::cout << "   _| |_| | | \\ V /  __/ |  \\__ \\ | (_) | | | |" << std::endl;
  std::cout << "  |_____|_| |_|\\_/ \\___|_|  |___/_|\\___/|_| |_|" << std::endl;

  Matrix m1 = get_matrix();
  print_matrix(m1);
  Matrix result;
  double determinant = (m1.values[0][0] * m1.values[1][1]) - (m1.values[1][0] * m1.values[0][1]);

  result.values[0][0] = m1.values[1][1] / determinant;
  result.values[0][1] = -(m1.values[0][1] / determinant);
  result.values[1][0] = -(m1.values[1][0] / determinant);
  result.values[1][1] = m1.values[0][0] /determinant;
  std::cout << "Inversion of Matrix:" << std::endl;
  print_matrix(result);
}

/***************************************************
  Function: get_matrix allows the user to enter 1 matrix, it's name, and it's corresponding values in each cell
  called by: calc_sum, calc_diff, calc_scalar_multiplication, calc_matrix_multiplication, calc_matrix_inversion
  Function Parameters: none
  Function Return Type: Matrix
***************************************************/
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

/***************************************************
  Function: print_matrix displays the values of a matrix
  called by: calc_sum, calc_diff, calc_scalar_multiplication, calc_matrix_multiplication, calc_matrix_inversion, get_matrix
  Function Parameters: Matrix m
  Function Return Type: void
***************************************************/
void print_matrix(Matrix m) {
  std::cout << "Matrix Values:" << std::endl;
  std::cout << "[  " << m.values[0][0] << "    " << m.values[0][1] << "  ]" << std::endl;
  std::cout << "[  " << m.values[1][0] << "    " << m.values[1][1] << "  ]" << std::endl;
  std::cout << std::endl;
}

/***************************************************
  Function: show_menu displays the possible menu options
  called by: main
  Function Parameters: none
  Function Return Type: void
***************************************************/
void show_menu() {
  std::cout << std::endl;
  std::cout << "Options:" << std::endl;
  std::cout << "1) Matrix Addition" << std::endl;
  std::cout << "2) Matrix Subtraction" << std::endl;
  std::cout << "3) Scalar Matrix Multiplication" << std::endl;
  std::cout << "4) Matrix Multiplication" << std::endl;
  std::cout << "5) Matrix Inversion" << std::endl;
  std::cout << "6) Exit" << std::endl;
  std::cout << std::endl;
  std::cout << "Please choose your Matrix operation: ";
}
