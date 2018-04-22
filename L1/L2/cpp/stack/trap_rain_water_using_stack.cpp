#include<iostream>
#include<stack>
#include<cstring>
#include<vector>
using namespace std;

/*
 
Given n non-negative integers representing an elevation map where the width of each bar is 1, compute how much water it is able to trap after raining.
https://leetcode.com/problems/trapping-rain-water/description/
problem 42.
 */




class Solution{

    public:
            int trap(vector<int>&arr){
            stack<int> mystk;
            int i = 0;
            int cur = 0;
            int max_water = 0;
            int height = 0;
            int width = 0;
                    
            while(i<arr.size()){
            
                /*if my stack is empty keep pusing the elelments to the stack; or if top element of the stack is bigger than current element keep pushing the current index to stack and increment i*/
                if(mystk.empty()== true || arr[mystk.top()] > arr[i]){
                
                    mystk.push(i);
                    i++;
                }else{
                
                    cur = mystk.top();
                    mystk.pop();
                    if(mystk.empty()!= true){
                    
                    height = min(arr[i], arr[mystk.top()]) - arr[cur];
                    width = (i-1) - mystk.top();
                    max_water = max_water + height*width;
                    
                    }
                
                }
            
            }
            return max_water;            
        }


};






int main(){

    vector<int> arr = {100,50,40,90,110};
    Solution ss;
    int result = 0;
    result =  ss.trap(arr);
    cout<<"trapped water result = "<<result<<endl;
    return 0;
}








