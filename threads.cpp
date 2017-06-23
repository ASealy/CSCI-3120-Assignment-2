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
	cout << endl;
	for(int i=0;i<11;i++) cout << all_threads_valid[i];
	cout << endl;
	

	int valid_sudoku=0;
	for(int i=0;i<10;i++){
		if(all_threads_valid[i]==0) valid_sudoku=1;
	}
	if(valid_sudoku==0) cout << "This sudoku solution is valid!" <<endl;
	else cout << "This sudoku solution is NOT valid!" <<endl;

	



   //pthread_exit(NULL);
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
	cout << endl;
	for(int i=0;i<11;i++) cout << all_threads_valid[i];
	cout << endl;
   //pthread_exit(NULL);
}

void *ThreeByThreeChecker1(void *params) {
   	int is_valid=1;

   	struct parameters *structure;
   	structure = (struct parameters *) params;

	int gridArray[9]={0};
	for(int i=0;i<3;i++){
      		for(int j=0;j<3;j++){
			gridArray[(int)sudoku_array[i][j]-49]=1;
			cout << sudoku_array[i][j];			
		}
	}

	for(int i=0;i<9;i++){
		if(gridArray[i]==0) is_valid=0;
	}
		
	if(is_valid==1) all_threads_valid[2]=1;

	cout << endl;
	for(int i=0;i<11;i++) cout << all_threads_valid[i];
	cout << endl;
}

void *ThreeByThreeChecker2(void *params) {
   	int is_valid=1;

   	struct parameters *structure;
   	structure = (struct parameters *) params;

	cout <<endl<< "coordinates:" <<structure->row << structure->column<<endl;
	int gridArray[9]={0};
	for(int i=3;i<6;i++){
      		for(int j=0;j<3;j++){
			gridArray[(int)sudoku_array[i][j]-49]=1;
			cout << sudoku_array[i][j];			
		}
	}

	for(int i=0;i<9;i++){
		if(gridArray[i]==0) is_valid=0;
	}
		
	if(is_valid==1) all_threads_valid[3]=1;

	cout << endl;
	for(int i=0;i<11;i++) cout << all_threads_valid[i];
	cout << endl;
}
void *ThreeByThreeChecker3(void *params) {
   	int is_valid=1;

   	struct parameters *structure;
   	structure = (struct parameters *) params;

	cout <<endl<< "coordinates:" <<structure->row << structure->column<<endl;
	int gridArray[9]={0};
	for(int i=6;i<9;i++){
      		for(int j=0;j<3;j++){
			gridArray[(int)sudoku_array[i][j]-49]=1;
			cout << sudoku_array[i][j];			
		}
	}

	for(int i=0;i<9;i++){
		if(gridArray[i]==0) is_valid=0;
	}
		
	if(is_valid==1) all_threads_valid[4]=1;

	cout << endl;
	for(int i=0;i<11;i++) cout << all_threads_valid[i];
	cout << endl;
}
void *ThreeByThreeChecker4(void *params) {
   	int is_valid=1;

   	struct parameters *structure;
   	structure = (struct parameters *) params;

	cout <<endl<< "coordinates:" <<structure->row << structure->column<<endl;
	int gridArray[9]={0};
	for(int i=0;i<3;i++){
      		for(int j=3;j<6;j++){
			gridArray[(int)sudoku_array[i][j]-49]=1;
			cout << sudoku_array[i][j];			
		}
	}

	for(int i=0;i<9;i++){
		if(gridArray[i]==0) is_valid=0;
	}
		
	if(is_valid==1) all_threads_valid[5]=1;

	cout << endl;
	for(int i=0;i<11;i++) cout << all_threads_valid[i];
	cout << endl;
}
void *ThreeByThreeChecker5(void *params) {
   	int is_valid=1;

   	struct parameters *structure;
   	structure = (struct parameters *) params;

	cout <<endl<< "coordinates:" <<structure->row << structure->column<<endl;
	int gridArray[9]={0};
	for(int i=3;i<6;i++){
      		for(int j=3;j<6;j++){
			gridArray[(int)sudoku_array[i][j]-49]=1;
			cout << sudoku_array[i][j];			
		}
	}

	for(int i=0;i<9;i++){
		if(gridArray[i]==0) is_valid=0;
	}
		
	if(is_valid==1) all_threads_valid[6]=1;

	cout << endl;
	for(int i=0;i<11;i++) cout << all_threads_valid[i];
	cout << endl;
}
void *ThreeByThreeChecker6(void *params) {
   	int is_valid=1;

   	struct parameters *structure;
   	structure = (struct parameters *) params;

	cout <<endl<< "coordinates:" <<structure->row << structure->column<<endl;
	int gridArray[9]={0};
	for(int i=6;i<9;i++){
      		for(int j=3;j<6;j++){
			gridArray[(int)sudoku_array[i][j]-49]=1;
			cout << sudoku_array[i][j];			
		}
	}

	for(int i=0;i<9;i++){
		if(gridArray[i]==0) is_valid=0;
	}
		
	if(is_valid==1) all_threads_valid[7]=1;

	cout << endl;
	for(int i=0;i<11;i++) cout << all_threads_valid[i];
	cout << endl;
}
void *ThreeByThreeChecker7(void *params) {
   	int is_valid=1;

   	struct parameters *structure;
   	structure = (struct parameters *) params;

	cout <<endl<< "coordinates:" <<structure->row << structure->column<<endl;
	int gridArray[9]={0};
	for(int i=0;i<3;i++){
      		for(int j=6;j<9;j++){
			gridArray[(int)sudoku_array[i][j]-49]=1;
			cout << sudoku_array[i][j];			
		}
	}

	for(int i=0;i<9;i++){
		if(gridArray[i]==0) is_valid=0;
	}
		
	if(is_valid==1) all_threads_valid[8]=1;

	cout << endl;
	for(int i=0;i<11;i++) cout << all_threads_valid[i];
	cout << endl;
}
void *ThreeByThreeChecker8(void *params) {
   	int is_valid=1;

   	struct parameters *structure;
   	structure = (struct parameters *) params;

	cout <<endl<< "coordinates:" <<structure->row << structure->column<<endl;
	int gridArray[9]={0};
	for(int i=3;i<6;i++){
      		for(int j=6;j<9;j++){
			gridArray[(int)sudoku_array[i][j]-49]=1;
			cout << sudoku_array[i][j];			
		}
	}

	for(int i=0;i<9;i++){
		if(gridArray[i]==0) is_valid=0;
	}
		
	if(is_valid==1) all_threads_valid[9]=1;

	cout << endl;
	for(int i=0;i<11;i++) cout << all_threads_valid[i];
	cout << endl;
}
void *ThreeByThreeChecker9(void *params) {
   	int is_valid=1;

   	struct parameters *structure;
   	structure = (struct parameters *) params;

	cout <<endl<< "coordinates:" <<structure->row << structure->column<<endl;
	int gridArray[9]={0};
	for(int i=6;i<9;i++){
      		for(int j=6;j<9;j++){
			gridArray[(int)sudoku_array[i][j]-49]=1;
			cout << sudoku_array[i][j];			
		}
	}

	for(int i=0;i<9;i++){
		if(gridArray[i]==0) is_valid=0;
	}
		
	if(is_valid==1) all_threads_valid[10]=1;

	cout << endl;
	for(int i=0;i<11;i++) cout << all_threads_valid[i];
	cout << endl;
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
rc = pthread_create(&thread, NULL, ThreeByThreeChecker1, (void *)&p);
p.row = 3;
p.column = 0;
rc = pthread_create(&thread, NULL, ThreeByThreeChecker2, (void *)&p);
p.row = 6;
p.column = 0;
rc = pthread_create(&thread, NULL, ThreeByThreeChecker3, (void *)&p);
p.row = 0;
p.column = 3;
rc = pthread_create(&thread, NULL, ThreeByThreeChecker4, (void *)&p);
p.row = 3;
p.column = 3;
rc = pthread_create(&thread, NULL, ThreeByThreeChecker5, (void *)&p);
p.row = 6;
p.column = 3;
rc = pthread_create(&thread, NULL, ThreeByThreeChecker6, (void *)&p);
p.row = 0;
p.column = 6;
rc = pthread_create(&thread, NULL, ThreeByThreeChecker7, (void *)&p);
p.row = 3;
p.column = 6;
rc = pthread_create(&thread, NULL, ThreeByThreeChecker8, (void *)&p);
p.row = 6;
p.column = 6;
rc = pthread_create(&thread, NULL, ThreeByThreeChecker9, (void *)&p);

	

	cout << endl;
	for(int i=0;i<11;i++) cout << all_threads_valid[i];
	cout << endl;


   
pthread_exit(NULL);
return 0;




   
}





