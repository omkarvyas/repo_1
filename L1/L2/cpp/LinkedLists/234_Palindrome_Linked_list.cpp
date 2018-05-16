#include<iostream>
#include<vector>
#include<stack>

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


/*Given a singly linked list, determine if it is a palindrome.*/
/*
e.g.
input Input: 1->2
Output: false
 
Example 2:

Input: 1->2->2->1
Output: true
 
 */



bool isPalindrome(ListNode* head) {

    /*traverse the whole list and find the half of it and push it on stack*/
    /*when we reach to the half of the linked list start removing the elelemnts form the stack and compare with rest of the contents in the linked list*/

    int count = 1;
    ListNode *cur = head;
    stack<ListNode*> my_stk;
    bool odd_flag = 0;
    int temp;
    /*Find the length of the linked list*/
    for (count = 1;cur->next!=NULL;++count){
    
        cur = cur->next;
    
    }

    /*See if linked list is consist of odd number of nodes or even number of nodes set a odd flag as we want to remove the node which is at center of the lined list*/
    cout <<"count = :"<<count<<endl;
    if(count%2){
    
        cout<<"count is odd"<<endl;
        count = count/2 + 1;
        odd_flag = 1;
    
    }else{
        cout<<"count is odd "<<endl;
        count = count/2;
    
    }
    cur = head;
    while(count){
    
        if(cur!=NULL){
            my_stk.push(cur);
            cout<<"pushed on stack:    " <<cur->val;
        }
        cur = cur->next;
        --count;
    
    }
    /*remove the center node from the stack*/
    if(odd_flag){
        my_stk.pop();
    
    }
    while(cur!=NULL){
        cur = cur->next;
    
        if(my_stk.empty()!=true){
            temp = (my_stk.top())->val;
            cout<<"popped element from stack: "<<temp<<endl;
            my_stk.pop();
        }
        if(cur!=NULL){
            if(temp != cur->val){
                return false;
        
            }
        }
        
    }

    return true;
                 
}







int main(){

    ListNode * head = NULL;
    int k = 4;
    head = AddNode_Front(head,1);
    head = AddNode_Front(head,2);
    head = AddNode_Front(head,2);
    head = AddNode_Front(head,1);
    if(isPalindrome(head)){
    
        cout<<"Linked list is not Palndrome"<<endl;
    }else{
    
        cout<<"Linked list is Palndrome"<<endl;
    
    }
    Print_LL(head);
    return 0;
}


