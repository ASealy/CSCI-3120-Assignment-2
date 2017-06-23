#include <iostream>
#include <cstdlib>
#include <pthread.h>
#include <string>
#include <fstream>
using namespace std;

//this is the char array for the sudoku board, it is char because it was read from the text file as a string 
char sudoku_array [9][9]={0};
//this is the array to check if each region is valid 
static int all_threads_valid[11]={0};

//these coordinates parameters are passed to the threads
struct parameters
{
   int row;
   int column;
};

//this is the row checker thread that checks if each row is valid 
//this will be the only thread that is commented as the others follow the same implementation
void *RowChecker(void *params) {
   //this int is to see if the region is valid 
   int is_valid=1;
   //a new struct is dynamically initialized according to the parameters 
   struct parameters *structure;
   structure = (struct parameters *) params;

   //each row is then checked 
   for(int i=0;i<9;i++){
      int columnsArray[9]={0};
      for(int j=0;j<9;j++){
         //the value of the on the sukudo board is used as an index to set the columnsArray index to 1 if that number is present
         columnsArray[(int)sudoku_array[i][j]-49]=1;
      }
      //then the columnsArray is checked to see if it is all 1s. if it is all 1s it is valid sudoku region 
      for(int j=0;j<9;j++){
         if(columnsArray[j]==0) is_valid=0;
      }
   }
   //if this region is valid, all_threads_valid[0] is set to 1
   if(is_valid==1) all_threads_valid[0]=1;

   //this is the last thread to run for some reason so we can check the entire all_threads_valid array to see if all other regions are valid 
   int valid_sudoku=0;
   for(int i=0;i<10;i++){
      if(all_threads_valid[i]==0) valid_sudoku=1;
   }
   //if the other regions are valid, print a valid message, otherwise print an invalid message 
   if(valid_sudoku==0) cout << endl << "This sudoku solution is valid!" << endl << endl;
   else cout << endl <<"This sudoku solution is NOT valid!" << endl << endl;
}




void *ColumnChecker(void *params) {
   int is_valid=1;
   struct parameters *structure;
   structure = (struct parameters *) params;

   for(int i=0;i<9;i++){
      int rowsArray[9]={0};
      for(int j=0;j<9;j++){
         rowsArray[(int)sudoku_array[j][i]-49]=1;
      }
      for(int j=0;j<9;j++){
         if(rowsArray[j]==0) is_valid=0;
      }

   }
   if(is_valid==1) all_threads_valid[1]=1;
}

void *ThreeByThreeChecker1(void *params) {
   int is_valid=1;

   struct parameters *structure;
   structure = (struct parameters *) params;

   int gridArray[9]={0};
   for(int i=0;i<3;i++){
      for(int j=0;j<3;j++){
         gridArray[(int)sudoku_array[i][j]-49]=1;
      }
   }

   for(int i=0;i<9;i++){
      if(gridArray[i]==0) is_valid=0;
   }

   if(is_valid==1) all_threads_valid[2]=1;
}

void *ThreeByThreeChecker2(void *params) {
   int is_valid=1;

   struct parameters *structure;
   structure = (struct parameters *) params;

   int gridArray[9]={0};
   for(int i=3;i<6;i++){
      for(int j=0;j<3;j++){
         gridArray[(int)sudoku_array[i][j]-49]=1;
      }
   }

   for(int i=0;i<9;i++){
      if(gridArray[i]==0) is_valid=0;
   }

   if(is_valid==1) all_threads_valid[3]=1;
}

void *ThreeByThreeChecker3(void *params) {
   int is_valid=1;

   struct parameters *structure;
   structure = (struct parameters *) params;

   int gridArray[9]={0};
   for(int i=6;i<9;i++){
      for(int j=0;j<3;j++){
         gridArray[(int)sudoku_array[i][j]-49]=1;
      }
   }

   for(int i=0;i<9;i++){
      if(gridArray[i]==0) is_valid=0;
   }

   if(is_valid==1) all_threads_valid[4]=1;
}

void *ThreeByThreeChecker4(void *params) {
   int is_valid=1;

   struct parameters *structure;
   structure = (struct parameters *) params;

   int gridArray[9]={0};
   for(int i=0;i<3;i++){
      for(int j=3;j<6;j++){
         gridArray[(int)sudoku_array[i][j]-49]=1;
      }
   }

   for(int i=0;i<9;i++){
      if(gridArray[i]==0) is_valid=0;
   }

   if(is_valid==1) all_threads_valid[5]=1;
}

void *ThreeByThreeChecker5(void *params) {
   int is_valid=1;

   struct parameters *structure;
   structure = (struct parameters *) params;

   int gridArray[9]={0};
   for(int i=3;i<6;i++){
      for(int j=3;j<6;j++){
         gridArray[(int)sudoku_array[i][j]-49]=1;
      }
   }

   for(int i=0;i<9;i++){
      if(gridArray[i]==0) is_valid=0;
   }

   if(is_valid==1) all_threads_valid[6]=1;
}

void *ThreeByThreeChecker6(void *params) {
   int is_valid=1;

   struct parameters *structure;
   structure = (struct parameters *) params;

   int gridArray[9]={0};
   for(int i=6;i<9;i++){
      for(int j=3;j<6;j++){
         gridArray[(int)sudoku_array[i][j]-49]=1;
      }
   }

   for(int i=0;i<9;i++){
      if(gridArray[i]==0) is_valid=0;
   }

   if(is_valid==1) all_threads_valid[7]=1;
}

void *ThreeByThreeChecker7(void *params) {
   int is_valid=1;

   struct parameters *structure;
   structure = (struct parameters *) params;

   int gridArray[9]={0};
   for(int i=0;i<3;i++){
      for(int j=6;j<9;j++){
         gridArray[(int)sudoku_array[i][j]-49]=1;
      }
   }

   for(int i=0;i<9;i++){
      if(gridArray[i]==0) is_valid=0;
   }

   if(is_valid==1) all_threads_valid[8]=1;
}

void *ThreeByThreeChecker8(void *params) {
   int is_valid=1;

   struct parameters *structure;
   structure = (struct parameters *) params;

   int gridArray[9]={0};
   for(int i=3;i<6;i++){
      for(int j=6;j<9;j++){
         gridArray[(int)sudoku_array[i][j]-49]=1;
      }
   }

   for(int i=0;i<9;i++){
      if(gridArray[i]==0) is_valid=0;
   }

   if(is_valid==1) all_threads_valid[9]=1;
}

void *ThreeByThreeChecker9(void *params) {
   int is_valid=1;

   struct parameters *structure;
   structure = (struct parameters *) params;

   int gridArray[9]={0};
   for(int i=6;i<9;i++){
      for(int j=6;j<9;j++){
         gridArray[(int)sudoku_array[i][j]-49]=1;
      }
   }

   for(int i=0;i<9;i++){
      if(gridArray[i]==0) is_valid=0;
   }

   if(is_valid==1) all_threads_valid[10]=1;
}






//main functions 
int main (int argc, char** argv) {

   //this is an implementation for converting a text file to a C++ string 
   std::ifstream stream("sudoku_solution.txt");
   std::string sudoku_string((std::istreambuf_iterator<char>(stream)),(std::istreambuf_iterator<char>()));
   int count=0;
   for(int i=0;i<9;i++){
      for(int j=0;j<9;j++){
         sudoku_array[i][j]=sudoku_string[count];
         count=count+2;
      }count++;
   }

   //this is where the threads are created
   // as per the instructions, i made 2 threads for row and columns and 9 threads for the grid regions 
   pthread_t thread1;
   //this is struct parameters which is used again for each thread, it gets updated for the grid regions 
   struct parameters p;
   p.row = 0;
   p.column = 0;
   //pthread_create is called with the specific thread and parameters 
   int rc = pthread_create(&thread1, NULL, RowChecker, (void *)&p);

   pthread_t thread2;
   p.row = 0;
   p.column = 0;
   rc = pthread_create(&thread2, NULL, ColumnChecker, (void *)&p);

   pthread_t thread3;
   p.row = 0;
   p.column = 0;
   rc = pthread_create(&thread3, NULL, ThreeByThreeChecker1, (void *)&p);

   pthread_t thread4;
   p.row = 3;
   p.column = 0;
   rc = pthread_create(&thread4, NULL, ThreeByThreeChecker2, (void *)&p);

   pthread_t thread5;
   p.row = 6;
   p.column = 0;
   rc = pthread_create(&thread5, NULL, ThreeByThreeChecker3, (void *)&p);

   pthread_t thread6;
   p.row = 0;
   p.column = 3;
   rc = pthread_create(&thread6, NULL, ThreeByThreeChecker4, (void *)&p);

   pthread_t thread7;
   p.row = 3;
   p.column = 3;
   rc = pthread_create(&thread7, NULL, ThreeByThreeChecker5, (void *)&p);

   pthread_t thread8;
   p.row = 6;
   p.column = 3;
   rc = pthread_create(&thread8, NULL, ThreeByThreeChecker6, (void *)&p);

   pthread_t thread9;
   p.row = 0;
   p.column = 6;
   rc = pthread_create(&thread9, NULL, ThreeByThreeChecker7, (void *)&p);

   pthread_t thread10;
   p.row = 3;
   p.column = 6;
   rc = pthread_create(&thread10, NULL, ThreeByThreeChecker8, (void *)&p);

   pthread_t thread11;
   p.row = 6;
   p.column = 6;
   rc = pthread_create(&thread11, NULL, ThreeByThreeChecker9, (void *)&p);

   pthread_exit(NULL);
   return 0;

}