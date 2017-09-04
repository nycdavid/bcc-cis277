#include <iostream>
#include <fstream>
#include <math.h>

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

void print_vector(std::ofstream& output_file, Vector v, std::string line_prefix = "") {
  if (line_prefix == "") {
    output_file << v.name << " = (" << v.x << ", " << v.y << ")" << std::endl;
  } else {
    output_file << line_prefix << " " << v.name << " = (" << v.x << ", " << v.y << ")" << std::endl;
  }
}

void calc_sum(Vector v1, Vector v2, Vector& sum) {
  sum.x = v1.x + v2.x;
  sum.y = v1.y + v2.y;
}

void calc_difference(Vector v1, Vector v2, Vector& diff) {
  diff.x = v1.x - v2.x;
  diff.y = v1.y - v2.y;
}

void calc_scalar_multiple(Vector v1, Vector& scalar_prod, double multiple) {
  scalar_prod.x = multiple * v1.x;
  scalar_prod.y = multiple * v1.y;
}

void calc_scalar_product(Vector v1, Vector v2, double& scalar_product) {
  scalar_product = (v1.x * v2.x) + (v1.y * v2.y);
}

void calc_vector_magnitude(Vector v1, double& magnitude) {
  double x_squared = pow(v1.x, 2);
  double y_squared = pow(v1.y, 2);
  magnitude = pow(x_squared + y_squared, 0.5);
}
#endif
