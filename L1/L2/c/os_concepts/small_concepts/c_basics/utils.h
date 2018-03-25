#include <stdbool.h>

struct node{

        int val;
        struct node *next;

};

typedef struct node node;

node* create_list(int val);
int add_node_to_ll(int val, bool to_the_end);
int print_ll(void);
int search_node(int val);
int del_node(int val);

