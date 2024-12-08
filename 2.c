#include<stdio.h>
int main ()
{
int array[11];
int index = 0 ;

for(int i=100; i<=120 ; i++){
    if(i % 2==0){
        array[index] = i;
        index++ ;

    }
     } 
     for(int i= 0 ; i<index ; i++){
     printf("%d" , array[i]);
     return 0;
     }
}


