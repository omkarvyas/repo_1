/*
  LeetCode 239 Sliding Window Maximum

  Given an array nums, there is a sliding window of size k which is moving from the very left of the array to the very right. 
  You can only see the k numbers in the window. Each time the sliding window moves right by one position.
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
You may assume k is always valid, ie: 1 . k . input array's size for non-empty array.
Could you solve it in linear time?

*/

#include<iostream>
#include<stack>
#include<cstring>
#include<vector>
#include<deque>
using namespace std;

class Solution {
        public:
                vector<int> maxSlidingWindow(vector<int>& nums, int k) {

                        vector <int> out_arr;
                        if(nums.empty()==true){
                            out_arr = {0};
                        
                            return out_arr;
                        }
                        deque<int> myqueu;
                        int i;
                        int max = 0;
                        if(k == 1){
                        
                            for(i = 0;i<nums.size();i++){
                        
                                out_arr.push_back(nums[i]);
                        
                            }
                            return out_arr;
                        
                        }
    
                        for(i = 0; i<(nums.size()-(k-1));i++){
                                max = 0;
                            for(int l = i; l < k+i; l++){
                                cout<<"nums[l]"<<nums[l]<<endl;
                                if(max<nums[l]){
                                    max = nums[l];
                                }
                            }
                            cout<<"Max = " <<max<<endl;
                            out_arr.push_back(max);
                        }

                        cout<<"size of input array = "<<nums.size()<<endl;
                        cout<<"k = "<<k<<endl;
                        return out_arr;
                                    
                }
};


int main(){


    Solution my_sol;
    vector<int> input_arr = {1,-1};
    int Window_size = 1;
    vector<int> out_arr = my_sol.maxSlidingWindow(input_arr, Window_size);
    int size = out_arr.size();
            cout<<"Max number array:";
        for(int i = 0; i<size;i++){
    
            cout<<out_arr[i];
    
        }
    cout<<endl;;
    return 0;


}








