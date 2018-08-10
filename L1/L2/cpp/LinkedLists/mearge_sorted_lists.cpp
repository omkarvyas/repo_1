#include<iostream>
#include<vector>

using namespace std;

struct ListNode{
    int val;
    ListNode *next;
    ListNode(int x): val(x), next(NULL){}
};



ListNode * AddNode_Front(ListNode *head, int val){
    
    ListNode *tmp = new ListNode(val);
    if(head == NULL){
    
        return tmp;
    
    }else{
    
        tmp->next=head;
    
    }

return tmp;

}

bool compare(int a, int b){
    return a>b;

}


ListNode * mearg_2_sorted_lists(ListNode *h1, ListNode *h2){


/*create a dummy node*/
ListNode *head = new ListNode(-1);
/*create a pointer to be returend*/
ListNode *ret_head = head;

    if(h1 == NULL){
        return h2;
    }

    if(h2 == NULL){
        return h1;
    }

    if(h1 == NULL & h2 == NULL){
        return NULL;
    }
    
    while(h1!=NULL && h2!=NULL){

        /*if first link current value is small than the second list current value assign head->next = h1 and h1 = h1->next;*/
        if(h1->val < h2->val){
            head->next = h1;
            h1 = h1->next;
    
        /*else if second link current value is small than the first list current value assign head->next = h2 and h2 = h2->next;*/
        }else{
            head->next = h2;
            h2 = h2->next;
        }
        head = head->next;
    }

    /*if expression 1 evaluates to true then expression 2 is evaluated*/
    /*if expression 1 evaluates to flase then expression 3 is evaluated*/

    head->next = h1?h1:h2;
    return ret_head->next;


}



void Print_LL(ListNode *head){

    ListNode *tmp = head;
    int i =0;
    if(head == NULL){
    cout << "Empty List; head pointer is NULL"<<endl;
    return;
    
    }

    while(tmp!=NULL){
    
        cout<<"Node:"<<i<<"val:"<<tmp->val<<endl;
        tmp = tmp->next;
        i++;
    }
}



int main(){

    ListNode * head1 = NULL;
    ListNode * head2 = NULL;
    ListNode * out_head = NULL;

    head1 = AddNode_Front(head1,40);
    head1 = AddNode_Front(head1,30);
    head1 = AddNode_Front(head1,20);
    head1 = AddNode_Front(head1,10);

    head2 = AddNode_Front(head2,45);
    head2 = AddNode_Front(head2,35);
    head2 = AddNode_Front(head2,25);
    head2 = AddNode_Front(head2,10);

    out_head = mearg_2_sorted_lists(head1,head2);


    //Print_LL(head1);
    Print_LL(out_head);


    return 0;
}


