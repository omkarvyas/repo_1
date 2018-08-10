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

ListNode* rotateRight(ListNode* head, int k) {
    /*null check for input linked list*/        
        if(!head){
            
            return head;
        }
    /*temp veriable end init to head*/
    ListNode *end = head;
    /*have a count = 1*/
    int count = 1;
    /*traverse the input list to just before the end so we had count = 1 as initial value*/
        while(end->next){
            
            count++;
            end = end->next;
            
        }
        //cout <<"end->val:     "<<end->val<<endl;
        /* k = k%count if k = 2 and count = 5 k is still 2 if k is in multiples of count then no need to rotate, also if k is grater than count it will set ke to less than count so we can know how much exact rotation we need*/
        k = k%count;
        //cout << "new k = "<<k<<endl;
        if(k == 0){
            
            return head;
        }
    /* now count - k that gives the kth node */
    int index = count - k;
    /*current = head*/
    ListNode *current = head;
    /*prev is set to NULL*/
    ListNode *prev = NULL;
    
        for(int i = 0; i<index; ++i){
            prev = current;
            //cout<<"prev->val: "<<prev->val<<endl;
            current = current->next;
        }
        /*make it circular list*/
        end ->next = head;
        /*prev points to the location where we should append NULL*/
        prev->next = NULL;
        return current;        
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


