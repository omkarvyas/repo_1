#include<iostream>
using namespace std;



char *temp(char arr[]){

char *out_arr = new char[10];

int i = 0;

    for(i =0; i<10; i++){
    
    out_arr[i] = arr[i];
    
    }


return out_arr;

}



int main(){


char *p =NULL;

char arr[10] = "Hello";

p = temp(arr);

cout<<"p is:"<<p<<endl;


}


