#include <stdio.h>

#define B2(n) n , n+1, n+1, n+2
#define B4(n) B2(n), B2(n+1), B2(n+1), B2(n+2)
#define B6(n) B4(n), B4(n+1), B4(n+1), B4(n+2)
#define COUNT_BITS B6(0), B6(1), B6(1), B6(2)


char arr[256]={COUNT_BITS};

int main(void){

int i = 0;

    for(i = 0; i <256; i++){
    
        printf(" arr[%d] = %d\t\t ",i, arr[i]);
    
    }

//        printf("\n defination of B2 %s\n ", arr);

        
        return 0;



}
