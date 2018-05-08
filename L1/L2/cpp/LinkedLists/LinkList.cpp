#include<iostream>

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





ListNode * Add_To_Positon(ListNode *head, int val, int pos){

    ListNode *cur = head;
    ListNode *post = NULL;
    ListNode *tmp = new ListNode(val);
    if(head == NULL || pos < 0){
    
        cout<<"Cannot add a node to asked position as Linked List is empty or invalid position was provided";
        return NULL;
    
    }

    if(pos == 0){
        cout<<"Incerting at 0th location"<<endl;
        tmp->next = head;
        return tmp;
    
    
    }
    
    cout<<"Position before entring while loop:"<<pos<<endl;        
    while(pos){
        cur = cur->next;
        if(cur == NULL && pos > 0){
            cout<<"Position in while loop:"<<pos<<endl;        
            cout<<" Invalid position "<<endl;
            return NULL;
        }
        pos--;
    }
    post = cur->next;
    cur->next = tmp;
    tmp->next = post;
    return head;

}



ListNode * Delete_Front(ListNode *head){

    ListNode *tmp = NULL;

    if(head == NULL){
    
        cout<<"Cannot Delet any node from empty Linked List";
        return NULL;
    
    }

    if(head->next == NULL){
    
    delete(head);
    return NULL;
    
    }
    tmp = head->next;
    delete(head);
    return tmp;


}


ListNode * Delete_End(ListNode *head){

    ListNode *tmp = NULL;

    if(head == NULL){
    
        cout<<"Cannot Delet any node from empty Linked List";
        return NULL;
    
    }
    
    if(head->next == NULL){
    
        delete(head);
        return NULL;
    
    }

    tmp = head;
    while(tmp->next->next!=NULL){
    
        tmp = tmp->next;
    
    }

    delete(tmp->next);
    tmp->next = NULL;
    return head;


}


void Delete_This_Node(ListNode *Node){

    ListNode *tmp;

    if(Node->next == NULL || (Node==NULL)){
    
        cout<<"this node can not be deleted"<<endl;
        exit 0;
    
    }

    

    cout << "i/p Node->val"<<Node->val<<endl;
    Node->val = Node->next->val;

    cout << "after copy Node->val"<<Node->val<<endl;

    tmp = Node->next;
    Node->next = tmp->next;
    delete(tmp);

    cout << "before return Node->val"<<Node->val<<endl;

    return;

}




void Print_LL(ListNode *head){

    ListNode *tmp = head;
    int i =0;
    if(head == NULL){
    cout << "Empty List; head pointer is NULL"<<endl;
    return;
    
    }

    while(tmp->next!=NULL){
    
        cout<<"Node:"<<i<<"val:"<<tmp->val<<endl;
        tmp = tmp->next;
        i++;
    }
}



int main(){

    ListNode * head = NULL;

    head = AddNode_Front(head,10);
    head = AddNode_Front(head,20);
    head = AddNode_Front(head,30);
    head = AddNode_Front(head,40);
    head = AddNode_End(head,999);
    head = AddNode_End(head,888);
    head = AddNode_End(head,777);
    head = AddNode_End(head,666);
    cout<<"Full List"<<endl;
    Print_LL(head);
//    head = Delete_End(head);
//    head = Delete_Front(head);
//    cout<<"Delete 1 at front and one at end"<<endl;
//    Print_LL(head);
//    head = Add_To_Positon(head,1001,1);
//    head = Add_To_Positon(head,2001,0);
//    head = Add_To_Positon(head,3001,7);
//    cout<<"added 1001 to 1, 2001 0 and 3001 to 7th location"<<endl;

//    Print_LL(head);

    cout<<endl;

    cout<<"after deleting head->next->next:"<<(head->next->next)->val<<endl;
    Delete_This_Node(head->next->next);
    
    Print_LL(head);
    return 0;
}


