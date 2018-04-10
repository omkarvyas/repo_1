#include<iostream>
#include<stack>
#include<cstring>

using namespace std;

void find_next_big_ele(int arr[],int size){

int i = 0;
int cur = 0;
int top_ele = 0;

cout << "size =:"<<size<<endl;

stack<int> mystk;


mystk.push(arr[i]);
i++;

    while(i<size){

        cur = arr[i];
        top_ele = mystk.top();

        while(cur > top_ele){
        
            cout<< top_ele << "next big element -->" << cur << endl;
            mystk.pop();
                if(mystk.empty()==true){
                    break;
                }

            top_ele = mystk.top();
        }
            mystk.push(cur);
            i++;
        
        }

        while(mystk.empty()== false){

            top_ele = mystk.top();
            cout << top_ele << "-->" << -1<<endl;
            mystk.pop();
        
        
        }



}









int main(){

    int arr[] = {0,1,4,6,26};
        
      find_next_big_ele(arr,(sizeof(arr)/sizeof(arr[0])));
        return 0;


}








