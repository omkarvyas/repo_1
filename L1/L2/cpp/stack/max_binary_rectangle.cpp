#include<iostream>
#include<stack>
#include<cstring>
#include<vector>




using namespace std;

class Solution{

    public:
            int maximalRectangle(vector<vector<char>>& matrix);
            int findout_max_area(int arr[], int size);

};

int Solution::maximalRectangle(vector<vector<char>>& matrix){


            
int row =0, col =0;
int no_of_cols = matrix[0].size();
int no_of_rows = matrix.size();
int temp_area = 0;
int max_area = 0;
int i = 0;
int j = 0;
cout<<"matrix size it is number of rows= "<< matrix.size()<<endl;
cout<<"matrix[].size it is number of coloms= "<< matrix[0].size()<<endl;

int arr[no_of_cols];

    for( j = 0; j<no_of_rows;j++){
        for( i = 0; i<no_of_cols;i++){
    
            
            if (j == 0)
            {
                arr[i] = matrix[j][i] - '0';
            
            }

            if(j>0 && matrix[j][i]!= '0'){
            
                arr[i] = arr[i]+matrix[j][i] - '0';
            
            }
    
        }
    temp_area = findout_max_area(arr,sizeof(arr)/sizeof(arr[0]));
    if(max_area<temp_area){
    
    max_area = temp_area;
    
    }
    cout<<"temp_area= " <<temp_area<<endl;
    cout<<"i = "<<i<<endl;
    cout<<"j= "<<j<<endl;
    }




#if 0
    for(row = 0; row<no_of_rows; row++){
        for(col = 0; col<no_of_cols;col++){
           cout<<"row = \t"<<row<<"col = \t"<< col << "\t matrix[row][col] \t "<<matrix[row][col]<<endl;
        }
        cout<<"\n";
    }
#endif


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


    vector < vector <char> > matrix {{'1', '0', '1', '0', '0'},
                                     {'1', '0', '1', '1', '1'},
                                     {'1', '1', '1', '1', '1'},
                                     {'1', '0', '0', '1', '0'}};
    Solution s1;
    int max_area = s1.maximalRectangle(matrix);
    cout<<"Max area"<<max_area<<endl;
    return 0;


}








