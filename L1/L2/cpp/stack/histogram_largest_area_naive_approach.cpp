#include<iostream>
#include<stack>
#include<cstring>

using namespace std;

/* function: find_largest_area takes 2 areguments array in which we have to find the max area of rectangle formed by histograms, and size of an array 
 * it returns max area of bigest possible rectracngle. 
 *
 *
 */


int find_largest_area(int arr[],int size){

int i = 0;
int j = 0;
int max_area = 0;
int cur_area = 0;
int k = 0;
int right = 0;
int left = 0;
cout << "size = " <<size <<endl;

    while(i < size){

        for(i = 0; i<size; i++){
           right = 0;
          left = 0; 
            /*go to right elements if right element is grater than or equal to current element*/
            for(j = i+1; j<size; j++){
                if(arr[j] >= arr[i]){

                        right++;                
                
                /*if no more elemts grater than or equal to current element break and comeout of for loop*/
                }else 
                    break;      
            }
            /*go to left elements if left element is grater than or equal to current element*/
            for(k = i -1; k>=0; k--){
            
                if(arr[k]>= arr[i]){
                    left++;
                /*if no more elemts grater than or equal to current element break and comeout of for loop*/
                }else
                    break;
            }
            /*cur_area of a rectangle is how much you can go left and right and area of itself which is 1, multiplied by the height*/
            cur_area = arr[i]*(left+right+1);
            cout <<"area = "<<cur_area<<endl;
            /*to find the max area we need to update max area each time*/
            if(max_area < cur_area){
                max_area = cur_area;
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








