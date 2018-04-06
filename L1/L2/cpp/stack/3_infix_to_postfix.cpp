#include<iostream>
#include<stack>
#include<cstring>

using namespace std;


/*Create a precedence*/

int precedence(char inp){

    if(inp == '^')return 3;
    else if(inp == '*' || inp == '/')return 2;
    else if(inp == '+' || inp == '-')return 1;
    else return 0; 

}

int main(){

    cout<<"Hello"<<endl;
    return 0;


}








