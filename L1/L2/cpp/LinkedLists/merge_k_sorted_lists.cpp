


/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
#include <queue>
/*Comparator function will be used by priority queue if implemented as minheap*/
struct compare {
  bool operator()(ListNode *x, ListNode *y){
      
      return x->val > y->val;
  }
    
};

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        
        if(lists.size() == NULL)
            return NULL;
        
        /*Made a priority queue*/
        priority_queue<ListNode*, vector<ListNode *>, compare> min_heap;
        
        ListNode *head = NULL, *prev = NULL, *cur = NULL;
        
        
        /*push the first nodes of all linked lists to the min_heap*/
        
        for(int i = 0; i<lists.size(); i++){
            
            //cout<< lists[i]->val <<" "<<endl;
            /*push address of first elements of the lists to the min heap, only if it is not NULL*/
            if(lists[i]!=NULL)
                min_heap.push(lists[i]);
        }
        
       
        if(min_heap.size() > 0) {
            prev = head = min_heap.top();
            min_heap.pop();
            if(head->next != NULL)
                min_heap.push(head->next);
        }
        
        while(min_heap.size() >0){
            /*get the minimum element from the min heap top*/
            cur = min_heap.top();
            //cout << "cur->val = " <<cur->val<<endl;
            /*remove the top element from the min heap*/
            min_heap.pop();
            /*prev -> next to current elelemt which was minimum*/
            prev->next = cur;
            
            //cout << "prev->next = " <<prev->next->val<<endl;
            
            /*update prev with latest smallest elelement so that its next we can push to the heap*/
            prev = cur;
            
            //cout << "prev->val = " <<prev->val<<endl;
            //if(prev->next != NULL)
            //cout << "after updating the prev; prev->next = " <<prev->next->val<<endl;
            if(prev->next != NULL){
                min_heap.push(prev->next);
            }
            
            
        }
    return head;
    }
};