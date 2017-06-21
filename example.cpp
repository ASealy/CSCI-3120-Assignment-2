#include <iostream>
#include <cstdlib>
#include <pthread.h>

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



int main () {
   pthread_t thread;
   struct parameters td;
   td.row = 1;
   td.column = 1;
   int rc = pthread_create(&thread, NULL, threadFunction, (void *)&td);








   pthread_exit(NULL);
}