#include<iostream>
#include<stack>
#include<cstring>

using namespace std;


int find_largest_area(int arr[],int size){

int i = 0;
int j = 0;
int max_area = 0;
int cur_ele = 0;
int k = 0;
int right = 0;
int left = 0;
cout << "size = " <<size <<endl;

    while(i < size){

        for(i = 0; i<size; i++){
           right = 0;
          left = 0; 
            /*go to right elements if right element is grater than current element*/
            for(j = i+1; j<size; j++){
                if(arr[j] >= arr[i]){

                        right++;                
                
                }else 
                    break;      
            }
            for(k = i -1; k>=0; k--){
            
                if(arr[k]>= arr[i]){
                    left++;
                
                }else
                    break;
            }
            cur_ele = arr[i]*(left+right+1);
            cout <<"area = "<<cur_ele<<endl;
            if(max_area < cur_ele){
                max_area = cur_ele;
            }
        }
    
    }

    return max_area;
}




int main(){

    int arr[] = {2,2,5,6,1};
    int max_area = find_largest_area(arr,sizeof(arr)/sizeof(arr[0]));
    
    cout<<"Max Area: "<<max_area<<endl;
    return 0;


}








