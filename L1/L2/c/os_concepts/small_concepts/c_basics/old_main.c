/*
main.c:  main function to call all utilities, programs
  
 */

#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
#include<string.h>
#include "utils.h"

node *head;
node *curr;

typedef union {
    unsigned int value;
    struct {
        bool bit31:1;
        bool bit30:1;
        bool bit29:1;
    }bit_field;

}data_bits;



int main(){

unsigned int numb = 0;
unsigned char x = 0;
unsigned int rem = 0;

int var = 0;
char arr[8] = {0};
char *chPtr = &arr[0];
unsigned char temp = 0;
unsigned char a_c = 0;
printf("\n Input a number \n");
scanf("%d",&numb);
printf("\n input number = %d \n",numb);
var = numb_of_digits(numb);
printf("\n number of digits = %d \n",var);



    while(numb){
    rem = numb%16;
    if(rem <10){
    *chPtr = '0'+ (char)rem;
    } else if(rem == 10){
        *chPtr = 'a';
    }else if(rem == 11){
        *chPtr = 'b';
    }else if(rem == 12){
        *chPtr = 'c';
    }else if(rem == 13){
        *chPtr = 'd';
    }else if(rem == 14){
        *chPtr = 'e';
    }else if (rem == 15){
        *chPtr = 'f';
    }
    ++chPtr;
    x++;
    numb = numb/16;
    }
    chPtr = &arr[0];

    x = x-1;

    while(x){
    
        temp = arr[a_c];
        arr[a_c] = arr[x];
        arr[x] = temp;
        x--;
        ++a_c;
        
    }
    a_c= a_c + 1;
    arr[a_c] = '\0';

    printf("\n ------------------printing array contents %s ---------------------\n",chPtr);

#if 0    
printf("%c", *chPtr);
chPtr++;
printf("%c", *chPtr);
chPtr++;
printf("%c", *chPtr);
chPtr++;
printf("%c", *chPtr);
chPtr++;
printf("%c", *chPtr);
chPtr++;
printf("%c", *chPtr);
chPtr++;
printf("%c", *chPtr);
chPtr++;
insigned char temp = 0;
printf("%c", *chPtr);
chPtr++;
//    printf("\n ------------------printing array contents %s ---------------------\n",chPtr);
//    printf("\n numb = %d \n",numb);
#endif


printf("\n Hello Linux C \n");
return 0;



/*Singly Linked list related programs */        
#if 0
node *m_node = NULL;
int s_result = 0;
int d_result = 0;
m_node = create_list(-1);

printf("\n m_node value = %d \n", m_node->val);
printf("\n head node value = %d \n", head->val);
printf("\n curr  node value = %d \n", curr->val);


add_node_to_ll(10,1);
add_node_to_ll(20,1);
add_node_to_ll(30,1);
add_node_to_ll(40,1);
add_node_to_ll(50,1);
add_node_to_ll(60,1);
add_node_to_ll(70,1);
add_node_to_ll(80,1);
add_node_to_ll(90,1);
add_node_to_ll(100,1);
//add_node_to_ll(1070,0);
//add_node_to_ll(2070,0);
//add_node_to_ll(3070,0);

print_ll();
s_result = search_node(70);

printf("\n found the node s_result %d \n", s_result);

//print_ll();

s_result = search_node(330);
                                              
printf("\n s_result %d \n", s_result);printf("\n Hello Linux C \n");

d_result = del_node(-1);

if (d_result == 0){

printf("\n node deleted head \n");

}


print_ll();
#endif


/* Hamming Distance calculation*/
#if 0
//int itr = 0;
//int Hd = 0;
//set_bit_table_256();

printf("\n Other way of populating table\n ");

    for(itr = 0; itr<256;itr++){
        printf(" Bits[%d] = %d \t", itr, BitsSetTable256_f[itr]);
        if(itr%6 == 0)printf("\n");
    }

//Hd = hammingDistance(93,73);

//printf("\n hamming distance = %d \n", Hd);


#endif //0



}




//printf("\n int max limit = %d \n", INT_MAX);
//printf("\n int min = %d  \n", INT_MIN);
//printf("\n int min = %d  \n", UINT_MAX);

