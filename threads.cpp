#include <iostream>
#include <thread>
#include <string>
#include <fstream>
using namespace std;

typedef struct
{
	int row;
	int column;
} parameters;


void call_from_thread() {
	cout << "Hello, World" << "\n";
}


//1 is true, 0 is false
int main(int argc, char** argv)
{

	//this is an implementation of a text file to string parser 
	std::ifstream stream("sudoku_solution.txt");
	std::string sudoku_string((std::istreambuf_iterator<char>(stream)),(std::istreambuf_iterator<char>()));

	cout << sudoku_string << "\n";

	parameters *data = (parameters *) malloc(sizeof(parameters));
	data->row = 1;
	data->column = 1;


	std::thread t1(call_from_thread);
	t1.join();


	//one thread for columns
	//one thread for rows
	//nine threads for each 3x3 sub group




	return 0;
}