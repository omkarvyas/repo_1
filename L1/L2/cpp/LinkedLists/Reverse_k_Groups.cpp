#include<iostream>

using namespace std;

struct ListNode{
    int val;
    ListNode *next;
    ListNode(int x): val(x), next(NULL){}
};




ListNode * AddNode_End(ListNode *head, int val){

    ListNode *tmp = new ListNode(val);
    ListNode *cur = head;
    if(head == NULL){
    
        return tmp;
    
    }
    while(cur->next != NULL){
    
        cur = cur->next;
    
    }
    cur->next = tmp;
    return head;
}

ListNode *Reverse_LL(ListNode *head){

    ListNode *cur = head;
    ListNode *prev = NULL;
    ListNode *Next = NULL;
    
    while(cur!=NULL){
    
        Next = cur->next;
        cur->next = prev;
        prev = cur;
        cur = Next;
        
    }
    return prev;



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

    ListNode * head = NULL;
    head = AddNode_End(head,10);
    head = AddNode_End(head,20);
    head = AddNode_End(head,30);
    head = AddNode_End(head,40);
    head = AddNode_End(head,50);
    head = AddNode_End(head,60);
    head = AddNode_End(head,70);
    head = AddNode_End(head,80);
    head = AddNode_End(head,90);
    cout<<"Full List"<<endl;
    Print_LL(head);
    head = Reverse_LL(head);
    cout<<"Reverse List"<<endl;
    Print_LL(head);
    return 0;
}


