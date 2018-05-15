#include<iostream>
#include<vector>

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

    while(tmp!=NULL){
    
        cout<<"Node:"<<i<<"val:"<<tmp->val<<endl;
        tmp = tmp->next;
        i++;
    }
}



ListNode * AddNode_Front(ListNode *head, int val){
    
    ListNode *tmp = new ListNode(val);
    if(head == NULL){
    
        return tmp;
    
    }else{
    
        tmp->next=head;
    
    }

return tmp;

}


ListNode *rotate_list(ListNode *head, int k){

    ListNode *cur = head;
    ListNode *kth_Node = new ListNode(-1);
    unsigned int count = 0;
    
    while(cur->next!=NULL){
        cur = cur->next;
        count++;
    }

    cur = head;

    if(k > count){
        k = k - count -1;
    }
        cout<<"k = "<<k<<endl;    
        while(k!=0 && cur!=NULL){
        
            cur = cur->next;
            k--;
        
        }
        kth_Node = cur;
        while(cur->next!= NULL){
        
            cur = cur->next;
        
        }

        cur->next = head;
        head = kth_Node->next;
        kth_Node->next = NULL;

        return head;
    
    
    

}


int main(){

    ListNode * head = NULL;
    ListNode * out_head = NULL;
    int k = 4;
    head = AddNode_Front(head,2);
    head = AddNode_Front(head,1);
    head = AddNode_Front(head,0);
#if 0
    head = AddNode_Front(head,5);
    head = AddNode_Front(head,4);
    head = AddNode_Front(head,3);
    head = AddNode_Front(head,2);
    head = AddNode_Front(head,1);
#endif 
//    head = AddNode_Front(head,10);
    out_head = rotate_list(head,k);
    Print_LL(out_head);
    return 0;
}


