#include<iostream>
#include<stack>
#include<cstring>

using namespace std;


int findout_max_area(int arr[], int size){

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

    int arr[] = {20,20,12,9,0,21};
    int max_area = findout_max_area(arr, sizeof(arr)/sizeof(arr[0]));
    cout<<"max_area = "<< max_area;
    cout<<"Hello"<<endl;
    return 0;


}








