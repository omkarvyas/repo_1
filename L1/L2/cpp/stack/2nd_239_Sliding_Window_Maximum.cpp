/*
 Given an array nums, there is a sliding window of size k which is moving from the very left of the array to the very right. You can only see the k numbers in the window. Each time the sliding window moves right by one position.

 For example,
 Given nums = [1,3,-1,-3,5,3,6,7], and k = 3.

 Window position                Max
 ---------------               -----
 [1  3  -1] -3  5  3  6  7       3
  1 [3  -1  -3] 5  3  6  7       3
  1  3 [-1  -3  5] 3  6  7       5
  1  3  -1 [-3  5  3] 6  7       5
  1  3  -1  -3 [5  3  6] 7       6
  1  3  -1  -3  5 [3  6  7]      7

  Therefore, return the max sliding window as [3,3,5,5,6,7].

Note: 
You may assume k is always valid, ie: 1 . k . input array's size for non-empty array.

Follow up:
Could you solve it in linear time?
 
 
 */

#include<iostream>
#include<stack>
#include<cstring>
#include<deque>
#include<vector>
using namespace std;

class Solution {
                public:
                      vector<int> maxSlidingWindow(vector<int>& nums, int k) {
                        
                            vector<int> out_arr;
                            deque<int> mydque;
                            int size;
                            int i = 0, j =0;

                            if(nums.empty()==true || k == 1){
                            
                                return nums;
                            
                            }

                            /*for loop for only first 3 elements */
                            for(i = 0; i < k ;i++){
                            /*When mydque is empty or the next number is less than the current element push it on to the mydque at BACK*/
                                if(mydque.empty()==true || nums[i]<mydque.back()){
                                
                                    mydque.push_back(i);
                                
                                }else{
                            /*When next coming elemnt is bigger than that of the last element on the mydqueue pop all the elements from the mydeque as we got the big element */
                                    while(nums[i]>=nums[mydque.back()]){
                                    
                                        mydque.pop_back();
                                            if(mydque.empty() == true){
                                                break;
                                            }
                                    
                                    }
                            /*When we come here this would mean either my slider size queue mydeque is empty or we got the next big element and now so we have to push this new element to mydeque*/
                                    mydque.push_back(i);

                                }
                            
                            
                            }

                            for(int l = k; l<nums.size();l++){
                            /*As we reached here it means first window size elements are done and we can print and use first big element in first window size*/
                                cout<<"nums[mydque.front()]" << nums[mydque.front()]<<endl;
                                out_arr.push_back(nums[mydque.front()]);
                            /*Check if the window size is reached*/
                                if((l - mydque.front()) == k){
                                
                            /*Once Window size k is reached discard the front element of my deque*/
                                    mydque.pop_front();

                                
                                }

                            /*When mydque is empty or the next number is less than the current element push it on to the mydque at BACK*/
                                if(mydque.empty()==true || nums[l]<mydque.back()){
                                
                                    mydque.push_back(l);
                                
                                }else{
                            /*When next coming elemnt is bigger than that of the last element on the mydqueue pop all the elements from the mydeque as we got the big element */
                                    while(nums[l]>=nums[mydque.back()]){
                                    
                                        mydque.pop_back();
                                            if(mydque.empty() == true){
                                                break;
                                            }
                                    
                                    }
                            /*When we come here this would mean either my slider size queue mydeque is empty or we got the next big element and now so we have to push this new element to mydeque*/
                                    mydque.push_back(l);

                                }
                            
                            }
                                cout<<"nums[mydque.front()]" << nums[mydque.front()]<<endl;
                                out_arr.push_back(nums[mydque.front()]);
                      return out_arr;
            
                      }


};









int main(){

    
    Solution my_sol;
    vector<int> input_arr = {1,3,-1,-3,5,3,6,7};
    int Window_size = 3;
    vector<int> out_arr = my_sol.maxSlidingWindow(input_arr, Window_size);
    int size = out_arr.size();
            cout<<"Max number array:";
        for(int i = 0; i<size;i++){
    
            cout<<out_arr[i];
    
        }
    cout<<endl;;
    return 0;


}








