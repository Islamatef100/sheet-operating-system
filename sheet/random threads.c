 
#include <pthread.h>
#include <stdio.h>
#include <conio.h>  
#include <stdlib.h> 
#include <sys/types.h>
#include <sys/wait.h> 
int carry= 0;
void* Rand_thread( void * param )
{   
    int x=rand();
    int myNum = *((int*)param);
    printf( "Start thread %i", myNum);
    printf("  >> the random number is %d\n",x%10 + 1);
    carry +=x%10 + 1;
}
void* MainThread( void * param )
{   
    printf("the sum  = %i\n" , carry);
}
int main()
{ 
    int * arr;
    arr[0]=1;
    arr[1]=2;
    arr[2]=3;
    arr[3]=4;
    arr[4]=5;

    
pthread_t threadM,thread2,thread3,thread4,thread5;

pthread_create( &thread2, 0, Rand_thread, &arr[0] );
pthread_join( thread2, 0 );
pthread_create( &thread3, 0, Rand_thread, &arr[1] );
pthread_join( thread3, 0 );
pthread_create( &thread4, 0, Rand_thread, &arr[2] );
pthread_join( thread4, 0 );
pthread_create( &thread5, 0, Rand_thread, &arr[3]);
pthread_join( thread5, 0 );

pthread_create( &threadM, 0, MainThread, 0);
wait(pthread_join(threadM,0));


}



