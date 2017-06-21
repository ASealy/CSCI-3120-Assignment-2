#include <iostream>
#include <cstdlib>
#include <pthread.h>
#include <string>
#include <fstream>
using namespace std;

char sudoku_array [9][9]={0};
int all_threads_valid[11]={0};

struct parameters
{
   int row;
   int column;
};

void *RowChecker(void *params) {
   int is_valid=1;
   struct parameters *stucture;
   stucture = (struct parameters *) params;
	for(int i=0;i<9;i++){
	int columnsArray[9]={0};
		for(int j=0;j<9;j++){
			columnsArray[(int)sudoku_array[i][j]-49]=1;
				cout << sudoku_array[i][j];		
		}
		for(int j=0;j<9;j++){
			cout << columnsArray[j];
			if(columnsArray[j]==0) is_valid=0;
		}
	
	}
	if(is_valid==1) all_threads_valid[0]=1;
   pthread_exit(NULL);
}

void *ColumnChecker(void *params) {
   int is_valid=1;
   struct parameters *stucture;
   stucture = (struct parameters *) params;
	for(int i=0;i<9;i++){
	int columnsArray[9]={0};
		for(int j=0;j<9;j++){
			columnsArray[(int)sudoku_array[j][i]-49]=1;
				cout << sudoku_array[j][i];		
		}
		for(int j=0;j<9;j++){
			cout << columnsArray[j];
			if(columnsArray[j]==0) is_valid=0;
		}
	
	}
	if(is_valid==1) all_threads_valid[0]=1;
   pthread_exit(NULL);
}



int main (int argc, char** argv) {
   std::ifstream stream("sudoku_solution.txt");
   std::string sudoku_string((std::istreambuf_iterator<char>(stream)),(std::istreambuf_iterator<char>()));

   //cout << sudoku_string << "\n";

   
   int count=0;
   for(int i=0;i<9;i++){
      for(int j=0;j<9;j++){
         sudoku_array[i][j]=sudoku_string[count];
         count=count+2;
      }count++;
   }

	cout << endl;
   for(int i=0;i<9;i++){
      for(int j=0;j<9;j++){
         cout << sudoku_array[i][j];
      }cout << "\n";
   }
cout << endl;







   pthread_t thread_1;
   struct parameters p_1;
   p_1.row = 0;
   p_1.column = 0;
   int rc = pthread_create(&thread_1, NULL, RowChecker, (void *)&p_1);


    pthread_t thread_2;
   struct parameters p_2;
   p_2.row = 0;
   p_2.column = 0;
   rc = pthread_create(&thread_2, NULL, ColumnChecker, (void *)&p_2);


   pthread_exit(NULL);







   
}
