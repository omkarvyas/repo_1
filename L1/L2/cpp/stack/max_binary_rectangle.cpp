#include<iostream>
#include<stack>
#include<cstring>
#include<vector>
/*
 
 Given a 2D binary matrix filled with 0's and 1's, find the largest rectangle containing only 1's and return its area.

 For example, given the following matrix:
 
 1 0 1 0 0
 1 0 1 1 1
 1 1 1 1 1
 1 0 0 1 0
 
 max area in above exampe is 6.
 
 */



using namespace std;

class Solution{

    public:
            int maximalRectangle(vector<vector<char>>& matrix);
            int findout_max_area(int arr[], int size);

};

int Solution::maximalRectangle(vector<vector<char>>& matrix){
if(matrix.empty()){

    return 0;

}
int temp_area = 0;
int max_area = 0;
int i = 0;
int j = 0;

cout<<"matrix size it is number of rows= "<< matrix.size()<<endl;
cout<<"matrix[].size it is number of coloms= "<< matrix[0].size()<<endl;

/*take one auxilary array arr, here we are taking one dimentional arr to store temp row of given matrix*/

vector<int> arr(matrix[0].size(),0);

/*Convert this array in to a histogram if we get consecutive 1's then add if we get 0 then reset the arr value of that index to zero*/
    
    for( i = 0; i<matrix.size();i++){
        for( j = 0; j<matrix[0].size();j++){
   
               if(matrix[i][j] == '0') {
               
                    arr[j] = 0;
               
               }else{
               
                    arr[j]++;
               }
         }
    temp_area = findout_max_area(&arr[0],arr.size());
        if(max_area<temp_area){
    
            max_area = temp_area;
    
        }
    }

return max_area;
}


int Solution::findout_max_area(int arr[], int size){

    int i = 0;
    int cur = 0;
    int cur_area = 0;
    int max_area = 0;
    stack<int> mystk;
    while(i<size){
    
    /*If stack is empty push it to the stack*/
    /*If next element is bigger than current elelemtn push to stack*/

        if(mystk.empty() == true || arr[i] >= arr[mystk.top()]){
        
            mystk.push(i);
            i++;

        }else{
    
        /*If next element is smaller than current element pop from the stack*/

            cur = mystk.top();
            mystk.pop();

                if(mystk.empty()!= true){
                
                    cur_area = arr[cur]*((i-1)-mystk.top());

                }else{
                
                    cur_area = arr[cur]*i;
                }
     
                cout<<"cur_area"<<cur_area<<endl;
                
                if(max_area<cur_area){
                    
                    max_area = cur_area;
                
                }
        
        }
    
    }
    
    /*If stack is not empty afte the full aray parsing then repete the steps as initial while loop*/
    while(mystk.empty() == false) {
    
        cur = mystk.top();
        mystk.pop();

            if(mystk.empty()!= true){
                cur_area = arr[cur]*((i-1)-mystk.top());
            }else{
            
                cur_area = arr[cur]*i;
            
            }
     
            cout<<"cur_area"<<cur_area<<endl;
    
                if(max_area<cur_area){
                
                    max_area = cur_area;
                }
    }
    
    
    return max_area;


}




int main(){
//    vector < vector <char> > matrix {{'0','1'},
//                                     {'1','0'}};

    vector < vector <char> > matrix {{'1', '0', '1', '0', '0'},
                                     {'1', '0', '1', '1', '1'},
                                     {'1', '1', '1', '1', '1'},
                                     {'1', '0', '0', '1', '0'}};


    Solution s1;
    int max_area = s1.maximalRectangle(matrix);
    cout<<"Max area"<<max_area<<endl;
    return 0;


}








