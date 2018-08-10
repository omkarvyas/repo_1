#include<iostream>

using namespace std;

struct ListNode{
    int val;
    ListNode *next;
    ListNode(int x): val(x), next(NULL){}
};


void Print_LL(ListNode *head){

    ListNode *tmp = head;
    int i =0;
    if(head == NULL){
    cout << "Empty List; head pointer is NULL"<<endl;
    return;
    
    }

    cout<<"Linked List Contents:   ";
    while(tmp!=NULL){
    
        //cout<<"Node:   "<<i<<"val:  "<<tmp->val;
        cout<<tmp->val << " " ;
        tmp = tmp->next;
        i++;
    }
    cout<<endl;
}




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




ListNode* reverse(ListNode *head){

    if(head == NULL){
        return head;
    }
    ListNode *cur = head;
    ListNode *prev = NULL;
    ListNode *NP = NULL;


    while(cur!=NULL){
    
        NP = cur->next;
        cur->next = prev;
        prev = cur;
        cur = NP;
    
    }

    return prev;

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




ListNode *Reverse_LL_K_G(ListNode *head, int k){

    ListNode *cur = NULL;
    ListNode *prev = NULL;
    ListNode *khead = NULL;
    ListNode *knext = NULL;
    ListNode *dummy = NULL;

    dummy = new ListNode(-1);

    dummy->next = head;
    cur = dummy;
    prev = dummy;
    int i = 0;
    while(cur->next!= NULL){

        i++;
        cur = cur->next;
        if(i == k){
        
            knext = cur->next;
            khead = prev->next;
            cur->next = NULL;
            prev->next = reverse(khead);
            khead->next = knext;
            prev = cur = khead;
            i = 0;
        }
    
    
    
    }

    return dummy->next;

}


ListNode *Revese_LL_k_Groups(ListNode *head, int k){

ListNode *cur = NULL;
ListNode *prev = NULL, *khead=NULL, *knext=NULL, *dummy;
dummy = new ListNode(-1);
dummy->next = head;
cur = prev = dummy;
int i = 0;

    while(cur->next!=NULL){
        i++;
        cur = cur->next;
        if(i == k){
            knext = cur->next;
            khead = prev->next;
            cur->next = NULL; /*Break the link*/
            prev->next = reverse(khead); /*Reverse K nodes*/
            khead->next = knext;
            cur = prev = khead;
            i = 0;
        }
    
    }
    return dummy->next;

}





int main(){

    ListNode * head = NULL;
    head = AddNode_End(head,10);
    head = AddNode_End(head,11);
    head = AddNode_End(head,12);
    head = AddNode_End(head,13);
    head = AddNode_End(head,20);
    head = AddNode_End(head,30);
    head = AddNode_End(head,40);
    head = AddNode_End(head,50);
    head = AddNode_End(head,60);
    head = AddNode_End(head,70);
    head = AddNode_End(head,80);
    head = AddNode_End(head,90);
    head = AddNode_End(head,91);
    head = AddNode_End(head,92);
    head = AddNode_End(head,93);
    cout<<"Full List"<<endl;
    Print_LL(head);


//    head = Revese_LL_k_Groups(head,3);
    head = Reverse_LL_K_G(head,3);
    //head = Reverse_LL(head);
    //cout<<"Reverse List"<<endl;
    Print_LL(head);
    return 0;
}


