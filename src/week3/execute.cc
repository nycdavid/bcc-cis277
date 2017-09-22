#include <iostream>
#include <fstream>
#include <string>
#include <cmath>
#include <cstdlib>

using namespace std;

struct vector {
	double x, y;
	string name;
} result;

vector a;

/***************************************************
  Function: print_vector prints a vector to stdout as well as writes output to text file
  called by: calc_sum, calc_dif, calc_mult
  Function Parameters: output_file stream, vector, line_prefix string
  Function Return Type: void
***************************************************/
void print_vector(std::ofstream& output_file, vector v, std::string line_prefix = "") {
  system("clear");
  if (line_prefix == "") {
    std::cout << "Writing line to file: " << std::endl << v.name << " = (" << v.x << ", " << v.y << ")" << std::endl;
    output_file << v.name << " = (" << v.x << ", " << v.y << ")" << std::endl;
  } else {
    std::cout << "Writing line to file: " << std::endl << line_prefix << " " << v.name << " = (" << v.x << ", " << v.y << ")" << std::endl;
    output_file << line_prefix << " " << v.name << " = (" << v.x << ", " << v.y << ")" << std::endl;
  }
}

/***************************************************
  Function: print_double prints a double value to stdout as well as writes output to text file
  called by: calc_prod, calc_mag
  Function Parameters: output_file stream, double val, line_prefix string
  Function Return Type: void
***************************************************/
void print_double(std::ofstream& output_file, double val, std::string line_prefix = "") {
  std::cout << "Writing line to file: " << std::endl << line_prefix << " " << val << std::endl << std::endl;
  output_file << std::endl << line_prefix << " " << val << std::endl << std::endl;
}

/***************************************************
	Function: get_vector defines a single vector variable(can be called multiple times), flags runtime error
	calls: defines single vector variable
	called by: calc_sum, calc_dif, calc_prod, calc_mag, calc_mult
	Function Parameters: N/A
	Function Return Type: vector
***************************************************/
vector get_vector() {
	vector vec;
	cout << "Enter a name for new vector" << endl;
  cin >> vec.name;
    while (cin.fail())
	{
  		getchar();
  		cin.clear();
  		system("clear");
  		cout << "INVALID INPUT" << endl;
  		cout << "----------------------------------" << endl << endl;
	}
	cout << "Enter a x-value for vector " << vec.name << endl;
	cin >> vec.x;
    while (cin.fail())
	{
  		getchar();
  		cin.clear();
  		system("clear");
  		cout << "INVALID INPUT" << endl;
  		cout << "NOT A NUMBER" << endl;
  		cout << "----------------------------------" << endl;
      cout << "Please re-enter a x-value for vector " << vec.name << endl;
    	cin >> vec.x;
	}
	cout << "Enter a y-value for vector " << vec.name << endl;
	cin >> vec.y;
    while (cin.fail())
	{
  		getchar();
  		cin.clear();
  		system("clear");
  		cout << "INVALID INPUT" << endl;
  		cout << "NOT A NUMBER" << endl;
  		cout << "----------------------------------" << endl << endl;
      cout << "Please re-enter a y-value for vector " << vec.name << endl;
    	cin >> vec.y;
	}
	return vec;
}

/***************************************************
	Function Name: calc_sum, adds two vectors and returns
	Calls: Returns sum of two vectors added together
	Called by: main
	Function Parameters: std::ofstream output_file
	Function Return Type: vector
/***************************************************/
vector calc_sum(std::ofstream& output_file) {
	vector v1 = get_vector();
  vector v2 = get_vector();
  vector result;
	result.x = v1.x + v2.x;
	result.y = v1.y + v2.y;
  result.name = "Sum";
  print_vector(output_file, result);
	return result;
}

/***************************************************
	Function Name: calc_dif, subtracts two vectors and returns the sum
	Calls: Returns sum of two vectors subtracted from each other
	Called by: main
	Function Parameters: std::ofstream output_file
	Function Return Type: vector
***************************************************/
vector calc_dif(std::ofstream& output_file) {
  vector v1 = get_vector();
  vector v2 = get_vector();
  vector result;
	result.x = v1.x - v2.x;
	result.y = v1.y - v2.y;
  result.name = "Difference";
  print_vector(output_file, result);
	return result;
}

/***************************************************
	Function Name: calc_mult, scalar multplies a vector and returns the result
	calls: result is returned after multiplication of scalar and vector
	called by: main
	Function Parameters: std::ofstream output_file
	Function Return Type: vector
***************************************************/
vector calc_mult(std::ofstream& output_file) {
  vector v1 = get_vector();
	int k;
	cout << "Input scalar value for k" << endl;
	cin >> k;
	while (cin.fail())
	{
  		getchar();
  		cin.clear();
  		system("clear");
  		cout << "INVALID INPUT" << endl;
  		cout << "NOT A NUMBER" << endl;
  		cout << "----------------------------------" << endl;
      cout << "Please re-enter a scalar value for k" << endl;
    	cin >> k;
	}
	result.x = v1.x * k;
	result.y = v1.y * k;
  result.name = "Scalar multiple";
  print_vector(output_file, result);
	return result;
}

/***************************************************
	Function: calc_prod,calculates the product of two vectors and returns it
	Calls: Product of two vectors is calculated then returned
	Called by: main
	Function Parameters: std::ofstream output_file
	Function Return Type: double
/***************************************************/
double calc_prod(std::ofstream& output_file) {
  vector v1 = get_vector();
  vector v2 = get_vector();
	double scalar_prod = ((v1.x * v2.x) + (v1.y * v2.y));
  system("clear");
  print_double(output_file, scalar_prod, "Scalar product = ");
  return scalar_prod;
}

/***************************************************
	Function Name: calc_mag, calculates the magnitude of a vector and returns it
	Calls: Magnitude of a vector is calculated and then returned
	Called by: main
	Function Parameters: std::ofstream output_file
	Function Return Type: double
***************************************************/
double calc_mag(std::ofstream& output_file) {
  vector v1 = get_vector();
  double mag = pow(pow(v1.x, 2.0) + pow(v1.y, 2.0), 0.5);
  system("clear");
  print_double(output_file, mag, "Magnitude of Vector = ");
  return mag;
}

/***************************************************
	Function: bool menu
	Calls: menu driven program
	Called by: main
	Function Parameters: N/A
	Function Return Type: bool
****************************************************/
int main() {
	int Menu_Select;
  std::ofstream output_file;
  output_file.open("/test_bin/output.txt");

	bool running = true;
	do{
      vector res_vct;
    	cout << "What do you want to do? type:" << endl;
    	cout << "	1 for vector addition." << endl;
    	cout << "	2 for vector subtraction." << endl;
    	cout << "	3 for scalar multiple of vector." << endl;
    	cout << "	4 for scalar product." << endl;
    	cout << "	5 for vector magnitude." << endl;
    	cout << "	9 to quit." << endl;
    	//Get the type the user want to do for this program
    	cin >> Menu_Select;
		if (cin.fail())
		{
      		getchar();
      		cin.clear();
      		system("clear");
      		cout << "INVALID INPUT" << endl;
      		cout << "NOT A NUMBER" << endl;
      		cout << "----------------------------------" << endl << endl;
      		continue;
    	}
		switch(Menu_Select)
    	{
        case 1:
    			system("clear");
    			calc_sum(output_file);
          cout << "----------------------------------" << endl << endl;
    			break;
        case 2:
			system("clear");
			calc_dif(output_file);
			cout << "----------------------------------" << endl << endl;
            break;
        case 3:
			system("clear");
			calc_mult(output_file);
			cout << "----------------------------------" << endl << endl;
            break;
        case 4:
			system("clear");
			calc_prod(output_file);
			cout << "----------------------------------" << endl << endl;
            break;
        case 5:
			system("clear");
			calc_mag(output_file);
			cout << "----------------------------------" << endl << endl;
            break;
        case 9:
        	system("clear");
        	cout << "Program shutting down..." << endl;
			running = false;
      		break;
        default:
          	system("clear");
			cout << "Invalid Input" << endl;
          	cout << "----------------------------------" << endl << endl;
    	}
    }

  while (running);
  return 0;
}

/***************************************************
	Function Name: main, closes system if runtime error is detected
	calls: runtime error
	called by: N/A
	Function Parameters: N/A
	Function Return Type: int
****************************************************/
