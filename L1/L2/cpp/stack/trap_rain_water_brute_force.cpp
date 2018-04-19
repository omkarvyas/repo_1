#include<iostream>
#include<stack>
#include<cstring>

using namespace std;


int trap_water_unit(int arr[],int size){


    int left = 0, right = 0, left_big = 0, right_big = 0,max_unit = 0;

    
    for(int i = 0;i<size;i++){
        left_big = 0;
        right_big = 0;
        
        for(left = i; left >= 0; left--){

            if(arr[left]>=left_big){

                left_big = arr[left];
            
            }
            
            
        }
    
    
        for(right = i; right <size; right++){

                if(arr[right] >=right_big){
                    
                    right_big = arr[right];
                
                }
            
            
        }
        cout<<"before min"<<endl;
        cout<<"left big" <<left_big<<endl;;
        cout<<"right big" <<right_big<<endl;
        cout<<"arr[i] = "<<arr[i]<<"i = "<<i<<endl;
        max_unit += min(left_big,right_big) - arr[i];
        cout << "max_stored unit of water = " << max_unit<<endl;
    
    
    }

return max_unit;

}




int main(){

    cout<<"Hello"<<endl;
    int arr[]={16,5,4,2,15};
    int max_stored_water = trap_water_unit(arr,sizeof(arr)/sizeof(arr[0]));

    cout<<"stored units of water"<<max_stored_water<<endl;


    return 0;


}








