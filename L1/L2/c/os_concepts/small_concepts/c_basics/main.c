/*
main.c:  main function to call all utilities, programs
  
 */

#include<stdio.h>
#include<stdlib.h>
#include "utils.h"

node *head;
node *curr;

int main(){

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

printf("\n Hello Linux C \n");
return 0;

}




