#include <stdio.h>
#include <stdlib.h>
#include "utils.h"

extern node *head;
extern node *curr;


unsigned char BitsSetTable256_f[256];
unsigned char BitsSetTable256[256]= {

#define B2(n) n,        n+1,        n+1,        n+2
#define B4(n) B2(n),    B2(n+1),   B2(n+1),    B2(n+2)
#define B6(n) B4(n),    B4(n+1),   B4(n+1),    B4(n+2)
B6(0), B6(1), B6(1), B6(2)

};




node* create_list(int val){

        node *c_node = NULL;
        c_node = (node*)malloc(sizeof(c_node));
        
        if(NULL == c_node){
                printf("Node creation failed");
                return NULL;
        
        }

        c_node -> val = val;
        c_node -> next = NULL;
        head = curr = c_node;

        return c_node;
}


/*add node to link list at the start or at the end as per the bool flag*/
int add_node_to_ll(int val, bool to_the_end){

        node *a_node = NULL;
        node *t_node = NULL;

        if(head == NULL){
            printf("Create a list first");
            create_list(-1);        
        }
        t_node = head;

/*Create a new node*/
        a_node = (node*)malloc(sizeof(a_node));
        
        if(NULL == a_node){
            printf("Node creation failed");
            return -1;

        }
        a_node -> val = val;

        if(to_the_end){
/*To add the node to the end we have to go till the end of the link list from the head node*/
            while(t_node->next != NULL){
                t_node = t_node -> next;
            }
/*When we reach to the second last node we insert our newly created node at the end and new node -> next is made NULL to terminate the link list*/            
            t_node -> next = a_node;
            a_node -> next = NULL;
                     
        }else{
/*To add node to the bigining of the linked list we have to make head next pointer to point to the newly created node and newly created node's next would point to head next*/        
        a_node->next = head->next;
        head->next = a_node;
        }

        return 0;
}



int print_ll(void){

node *temp = NULL;
unsigned int i = 0;

    if(head == NULL){
        printf("\n Nothing in Linked list \n");
        return -1;

    }
    temp = head;

    while((temp->next) != NULL){
        i = i+1;
        printf("\n Node = %d and the value = %d \n",i, temp->val);
        temp = temp -> next;
    }
    printf("\n That was a last node!!!\n");
    return 0;

}


int search_node(int val){

    node *t_node = NULL;
    unsigned int n_count = 0;

    if(head == NULL){
    
    printf("\n Empty list \n");
    return -1;
    
    }
    t_node = head;

    while(t_node->next != NULL){
    ++n_count;
    t_node = t_node->next;
        if(t_node->val == val){
            printf("\nNode Found\n");
            return n_count;
       }    
    
    }
            printf("\nNode not Found\n");
    return -1;

}


int del_node(int val){

node *c_node = NULL;
node *p_node = NULL;

/*case if head node to be deleted*/

    if(head == NULL){
    
        printf("Empty Linked list");
        return -1;
    
    }if (head->next == NULL){
        printf("This will delete the linked list's head");
        head->val = 0;
        free(head);
        return 0;
    }
    if(val == -1){
    
    printf("\n Asking to delete head\n");
    p_node = head;
    c_node = head -> next;
    free(p_node);
    head = c_node;
    
    }

    p_node = head;
    c_node = head->next;
    while(c_node != NULL){

        if(c_node->val == val){
        
        /*Found the node to be deleted*/
            p_node->next = c_node->next;
            c_node->next = NULL;
            free(c_node);
        }
        p_node = c_node;
        c_node = c_node ->next;
    }
return 0;
}



/*
 The Hamming distance between two integers is the number of positions at which the corresponding bits are different.

 Given two integers x and y, calculate the Hamming distance.

Example:


Input: x = 1, y = 4

Output: 2

Explanation:
1   (0 0 0 1)
4   (0 1 0 0)
       ^   ^
       |   | 

       The above arrows point to positions where the corresponding bits are different.

 */

int hammingDistance(int x, int y ){

    int xor_of_two_nums = 0;
    int count_n_of_ones = 0;

    xor_of_two_nums = x ^ y;
    printf("xor of 2 number = %d ", xor_of_two_nums );

    return count_n_of_ones = count_set_bits(xor_of_two_nums);

}

unsigned int count_set_bits(int numb){


unsigned int c = 0;

return c  = BitsSetTable256[numb & 0xff] +
    BitsSetTable256[(numb >> 8) & 0xff]+
    BitsSetTable256[(numb >> 16)& 0xff]+
    BitsSetTable256[(numb >> 24)& 0xff];

}




void set_bit_table_256(void){

int i = 0;

    for(i = 0; i < 256; i++){

        BitsSetTable256_f[i] = (i&1)+BitsSetTable256_f[i/2];
    }
}


































