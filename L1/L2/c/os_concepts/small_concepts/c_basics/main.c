/*
main.c:  main function to call all utilities, programs
  
 */

#include<stdio.h>
#include<stdlib.h>
#include "utils.h"

node *head;
node *curr;

int main(){

//int itr = 0;
int Hd = 0;
set_bit_table_256();

#if 0
printf("\n Other way of populating table\n ");

    for(itr = 0; itr<256;itr++){
        printf(" Bits[%d] = %d \t", itr, BitsSetTable256_f[itr]);
        if(itr%6 == 0)printf("\n");
    }
#endif //0

Hd = hammingDistance(93,73);

printf("\n hamming distance = %d \n", Hd);

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


printf("\n Hello Linux C \n");
return 0;

}




