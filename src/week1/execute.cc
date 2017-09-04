#include <iostream>
#include <fstream>
#include "./vector.hpp"

int main() {
  std::ofstream output_file;
  output_file.open("output.txt");

  Vector vct1 = get_vector();
  Vector vct2 = get_vector();
  Vector sum = { "Sum", 0, 0 };
  calc_sum(vct1, vct2, sum);

  print_vector(output_file, vct1);
  print_vector(output_file, vct2);
  print_vector(output_file, sum);
  
  output_file.close();
  return 0;
}
