#include<iostream>
using namespace std;



int main(){

struct t{

    int a;
    int b;
    int c;


};

typedef struct t t;

t ct;

int arr[3] = {1,2,3};


void *ptr = &ct;
void *p = arr;
void *temp;

ct.a = 10;
ct.b = 20;
ct.c = 30;


cout<<"Struct contents: ptr->a"<<ct.a <<endl;
cout<<"Struct contents: ptr->b"<<ct.b <<endl;
cout<<"Struct contents: ptr->c"<<ct.c <<endl;

cout<<"arr[0]"<<arr[0]<<endl;
cout<<"arr[1]"<<arr[1]<<endl;
cout<<"arr[2]"<<arr[2]<<endl;

cout<<"address of array arr: "<<&arr<<endl;
cout<<"address of struct ct: "<<&ct<<endl;

p = &arr;
ptr = &ct;

temp = p;
p = ptr;
ptr = temp;



cout<<"Struct contents: ptr->a"<<(int)*p <<endl;
//cout<<"Struct contents: ptr->b"<<(int)*(p++) <<endl;
//cout<<"Struct contents: ptr->c"<<(int)*(p+2) <<endl;

cout<<"arr[0]"<<(int)*ptr<<endl;
//cout<<"arr[1]"<<(int)*(ptr++)<<endl;
//cout<<"arr[2]"<<(int)*(ptr+2)<<endl;


cout<<"address of array arr: "<<&arr<<endl;
cout<<"address of struct ct: "<<&ct<<endl;



return 0;










}
