#include<iostream>
#include<cstring>
#include<stack>

using namespace std;


class Rm_d{

int stk_ptr;
    public:
    Rm_d(){
        stk_ptr = -1;
    }

    char *  remove_dups(char arr[]);



};



char * Rm_d::remove_dups(char arr[]){

    int i = 0;
    int size = strlen(arr);
    
    while(i<size) {
    
    if(stk_ptr == -1 || arr[stk_ptr] != arr[i]){
        stk_ptr++;
        arr[stk_ptr] = arr[i];
        i++;
    
    }
    while(arr[stk_ptr] == arr[i]){
    
        stk_ptr--;
        i++;
    }
    
    }
    arr[stk_ptr+1] = '\0';

    return arr;

}



int main(void){

Rm_d my_rm;

char arr[] = "careerad";
char *out_arr;
cout<<"Size of array = "<<sizeof(arr)<<endl;

out_arr = my_rm.remove_dups(arr);
cout<< "out_arr: "<<out_arr<<endl;

return -1;


}


