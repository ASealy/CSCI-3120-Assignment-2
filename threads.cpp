#include <iostream>
#include <cstdlib>
#include <pthread.h>
#include <string>
#include <fstream>
using namespace std;

char sudoku_array [9][9]={0};
static int all_threads_valid[11]={0};




struct parameters
{
   int row;
   int column;
};

void *RowChecker(void *params) {
   int is_valid=1;
   struct parameters *structure;
   structure = (struct parameters *) params;
	for(int i=0;i<9;i++){
	int columnsArray[9]={0};
		for(int j=0;j<9;j++){
			columnsArray[(int)sudoku_array[i][j]-49]=1;
				//cout << sudoku_array[i][j];		
		}
		for(int j=0;j<9;j++){
			//cout << columnsArray[j];
			if(columnsArray[j]==0) is_valid=0;
		}
	
	}
	if(is_valid==1) all_threads_valid[0]=1;


	



   pthread_exit(NULL);
}

void *ColumnChecker(void *params) {
   int is_valid=1;
   struct parameters *structure;
   structure = (struct parameters *) params;
	for(int i=0;i<9;i++){
	int rowsArray[9]={0};
		for(int j=0;j<9;j++){
			rowsArray[(int)sudoku_array[j][i]-49]=1;
				//cout << sudoku_array[j][i];		
		}
		for(int j=0;j<9;j++){
			//cout << columnsArray[j];
			if(rowsArray[j]==0) is_valid=0;
		}
	
	}
	if(is_valid==1) all_threads_valid[1]=1;
   pthread_exit(NULL);
}

void *ThreeByThreeChecker(void *params) {
   int is_valid=1;
   struct parameters *structure;
   structure = (struct parameters *) params;

	int gridArray[9]={0};
	for(int i=structure->row;i<structure->row+3;i++){
      		for(int j=structure->column;j<structure->column+3;j++){
			gridArray[(int)sudoku_array[i][j]-49]=1;
			cout << sudoku_array[i][j];			
		}
	}

	for(int i=0;i<9;i++){
		if(gridArray[i]==0) is_valid=0;
	}
		
	
	if(is_valid==1) all_threads_valid[2]=1;
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




   pthread_t thread;
   struct parameters p;
   p.row = 0;
   p.column = 0;
   int rc = pthread_create(&thread, NULL, RowChecker, (void *)&p);


   

   p.row = 0;
   p.column = 0;
   rc = pthread_create(&thread, NULL, ColumnChecker, (void *)&p);




   p.row = 0;
   p.column = 0;
   rc = pthread_create(&thread, NULL, ThreeByThreeChecker, (void *)&p);
	

	cout << endl;
	for(int i=0;i<11;i++) cout << all_threads_valid[i];

	cout << endl;


   pthread_exit(NULL);







   
}





