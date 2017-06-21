#include <iostream>
#include <cstdlib>
#include <pthread.h>
#include <string>
#include <fstream>
using namespace std;

struct parameters
{
   int row;
   int column;
};

void *threadFunction(void *params) {
   struct parameters *stucture;
   stucture = (struct parameters *) params;
   cout << "Row: " << stucture->row;
   cout << "Column: " << stucture->column;
   pthread_exit(NULL);
}



int main (int argc, char** argv) {
   std::ifstream stream("sudoku_solution.txt");
   std::string sudoku_string((std::istreambuf_iterator<char>(stream)),(std::istreambuf_iterator<char>()));

   cout << sudoku_string << "\n";

   char sudoku_array [9][9]={0};
   int count=0;
   for(int i=0;i<9;i++){
      for(int j=0;j<9;j++){
         sudoku_array[i][j]=sudoku_string[count];
         count=count+2;
      }
   }

   for(int i=0;i<9;i++){
      for(int j=0;j<9;j++){
         cout << sudoku_array[i][j];
      }cout << "\n";
   }








   pthread_t thread;
   struct parameters td;
   td.row = 1;
   td.column = 1;
   int rc = pthread_create(&thread, NULL, threadFunction, (void *)&td);








   pthread_exit(NULL);
}