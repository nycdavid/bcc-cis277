#include <iostream>
#include <fstream>

struct Vector {
  std::string name;
  double x;
  double y;
};

#ifndef VECTOR_H
#define VECTOR_H
Vector get_vector() {
  std::string name;
  double x;
  double y;
  std::cout << "Enter a vector name: ";
  std::cin >> name;
  std::cout << "Enter an x value for " << name << ": ";
  std::cin >> x;
  std::cout << "Enter an y value for " << name << ": ";
  std::cin >> y;
  Vector vct = { name, x, y };

  return vct;
}

void print_vector(std::ofstream& output_file, Vector v) {
  output_file << "Vector " << v.name << " = (" << v.x << ", " << v.y << ")" << std::endl;
}

void calc_sum(Vector v1, Vector v2, Vector& sum) {
  double x_sum = v1.x + v2.x;
  double y_sum = v1.y + v2.y;
  sum.x = x_sum;
  sum.y = y_sum;
}
#endif
