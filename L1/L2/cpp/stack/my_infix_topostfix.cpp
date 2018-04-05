#include<iostream>
#include<stack>
#include<cstring>

using namespace std;

/*
 This program does infix to post fix conversion 

 1. create stack to keep operators out_arr to print the output 
 2. scan each element left to right 
 3. if arr[i] =  operator like a, b ,c .. z put it in out array
 4. if arr[i] = '(' push to stack
 5. if arr[i] = ')' pop everything on stack till you hit '(' and put in out array, and pop '(' and disacrd.
 6. if arr[i] = operands like *, +, ^, - push to stack however remove all elemnts from stack if the predence of the elemts on stack is grater than or equal to precedence of arr[i] and append it to the out_arr[j].
 7. when input string is completely processed remove all elemtns from the stack and append it to out array
 
 
 */

/*Create a precedence*/

int precedence(char inp){

    if(inp == '^')return 3;
    else if(inp == '*' || inp == '/')return 2;
    else if(inp == '+' || inp == '-')return 1;
    else return 0; 

}



char * infix_to_post_fix(char arr[]){

/*arr is input array, out_arr is output array*/

int size = strlen(arr);
char *out_arr = new char[size+1];
/*index variables*/
int i = 0;
int j = 0;
/*create stack*/
stack<char> mystk;
char tmp = 0;
char ele = 0;
int prec_i = 0;
int prec_s = 0;

    for(i = 0; i<size; i++){
    
 /*3. if arr[i] =  operator like a, b ,c .. z put it in out array */
        if(arr[i] >= 'a' && arr[i] <= 'z'){
        
            out_arr[j] = arr[i];
            j++;
 /*4. if arr[i] = '(' push to stack */
        }else if(arr[i] == '('){
        
            mystk.push(arr[i]);
        
 /*5. if arr[i] = ')' pop everything on stack till you hit '(' and put in out array, and pop '(' and disacrd.*/
        }else if(arr[i] == ')'){
        

            while(tmp != '('){
            
                tmp = mystk.top();
                if(tmp == '('){
                tmp = 0;
                mystk.pop();
                    break;
                }else {
                    out_arr[j] = tmp;
                    j++;
                    mystk.pop();
                }
            
            }
            
            
        
 /*6. if arr[i] = operands like *, +, ^, - push to stack however remove all elemnts from stack if the predence of the elemts on stack is grater than or equal to precedence of arr[i] and append it to the out_arr[j]. */
        }else{
        
            if(mystk.empty() == true){
                mystk.push(arr[i]);
            }else{
                cout<<"arr[i]:"<<arr[i]<<endl;
                cout<<"out_arr[j]:"<<out_arr[j]<<"j ="<<j<<endl;
                cout<<"precedence of arr[i]:"<<precedence(arr[i])<<endl;
                cout<<"precedence of mystk.top():"<<precedence(arr[i])<<endl;

            /*check the precedence of arr[i] check the predence of stack top element*/
                while(precedence(arr[i]) <= precedence(mystk.top())){


                    out_arr[j] = mystk.top();
                    j++;
                    mystk.pop();            
                    if(mystk.empty()==true){
                        break;
                    }
    
                }
                mystk.push(arr[i]);
            
            }
        
        
        }

    
    }
    while(mystk.empty() != true){
        out_arr[j] = mystk.top();
        j++;
        mystk.pop();
    
    }
    out_arr[j+1] = '\0';



return out_arr;



}




int main(){

char *p = NULL;

char arr[] = "(a+b)*(c+d)";

p = infix_to_post_fix(arr);
cout <<"out put = "<<p<<endl;
    return 0;


}








