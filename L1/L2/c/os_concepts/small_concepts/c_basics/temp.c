#include <stdio.h>
#include <stdlib.h>

#define B2(n) n , n+1, n+1, n+2
#define B4(n) B2(n), B2(n+1), B2(n+1), B2(n+2)
#define B6(n) B4(n), B4(n+1), B4(n+1), B4(n+2)
#define COUNT_BITS B6(0), B6(1), B6(1), B6(2)


char arr[256]={COUNT_BITS};

int main(void){

unsigned int i = 0;
unsigned int j = 0;
unsigned int k = 0;
unsigned int l = 0;
unsigned int x = 0;
unsigned int *rarr = NULL;
unsigned int numb = 0;


    printf("\n input a positive number :");
    scanf("%u",&numb);
    printf("\n input  number :%u",numb);

    rarr = (unsigned int *)calloc(numb+1,(sizeof(unsigned int)));
    if(rarr == NULL){
    printf("Could not allocate any memory");
    return 0;
    }
    rarr[0] = 0;

        for(i = 1; i<=numb; ++i){
            rarr[i] = rarr[(i&(i-1))]+1;
        }
    
//    i = i-1;
    
    for(l = 0; l<i;l++){
    printf("\n rarr[%u] = %u\n",l,rarr[l]);
    }
    
    

        return 0;



}
