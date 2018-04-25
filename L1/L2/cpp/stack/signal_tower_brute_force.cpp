#include<iostream>
#include<stack>
#include<cstring>
#include<vector>

/*
 
 Verious signal towers are present in a city. Towers are aligned in a straight horizontal line(from left to right) and each tower transmits signal in the right to left direction. Tower A shall block the signla of tower B if Tower A
 is present to the left of tower B and Tower A is taller than tower B. So the range of a signal of a given tower can be defined as: {(the number of contiguous towers just to the left of the given tower whose height is less than
 or equal to the height of the given tower)+1}.


 e.g. 
input: 100,80,60,70,60,75,85
output:1,1,1,2,1,4,6

 
 
 */


using namespace std;



class Solution{

vector<int> out_arr = {};
        public:
                vector<int>signal_tower_range(vector<int> in_arr);




};


vector<int> Solution::signal_tower_range(vector<int> in_arr){

    /*Out array is of size that of input array and initialized to 1*/
    vector<int> out_arr(in_arr.size(),1);
    int i = 0;
    int j = 0;
    /*Start from rear end of an arry as we want to traverse from right to left.*/
    
    for(i = in_arr.size()-1; i>=0; i--){
       /*Check for all elements on the left hand side, when we hit an emement grater than current element we break out of inner for loop.*/ 
        for(j = i-1; j >=0;j--){


                if(in_arr[j]<=in_arr[i]){
                
                    out_arr[i] = out_arr[i]+1;
                
                }else{
                
                    break;

                }
       
        
        }
    
    
    }

    return out_arr;    

}


int main(){

    Solution s;

    vector<int> in_arr = {100,80,60,70,60,75,85};
    vector<int> out_arr = {};

    out_arr = s.signal_tower_range(in_arr);
        cout<<"output = ";
    for(int i = 0; i <out_arr.size(); i++){
        cout<<out_arr[i]<<",";
    
    }

    cout<<"."<<endl;;
    return 0;


}








