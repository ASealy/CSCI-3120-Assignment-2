#include <iostream>
#include <cstdlib>
#include <pthread.h>

using namespace std;

typedef struct
{
   int row;
   int column;
} parameters;

void *PrintHello(void *threadarg) {
   struct parameters *my_data;

   my_data = (struct parameters *) threadarg;

   cout << "Row: " << my_data->row;
   cout << "Column: " << my_data->column;

   pthread_exit(NULL);
}

int main () {
   pthread_t threads[5];
   struct parameters td[5];
	
   int rc;
  

   for(int i=0; i < 5; i++ ){
      cout <<"main() : creating thread, " << i << endl;
      td[i].row = i;
      td[i].column = i;

      rc = pthread_create(&threads[i], NULL, PrintHello, (void *)&td[i]);
		
      if (rc){
         cout << "Error:unable to create thread," << rc << endl;
         exit(-1);
      }
   }
	
   pthread_exit(NULL);
}