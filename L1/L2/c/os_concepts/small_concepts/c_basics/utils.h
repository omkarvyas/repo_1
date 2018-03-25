#ifndef UTILS_H
#define UTILS_H

#include <stdbool.h>

struct node{

        int val;
        struct node *next;

};

typedef struct node node;

/*Look up table for 256 numbers which has set bits e.g 0 = 0; 1 = 0001 set bits are 1; 2 = 0010 set bits = 1; 3 = 0011 set bits are 2; 4 = 1000 set bits = 1;*/
extern unsigned char BitsSetTable256[256];
extern unsigned char BitsSetTable256_f[256];
node* create_list(int val);
int add_node_to_ll(int val, bool to_the_end);
int print_ll(void);
int search_node(int val);
int del_node(int val);
int hammingDistance(int x, int y);
void set_bit_table_256(void);
unsigned int count_set_bits(int numb);

#endif //UTILS_H

