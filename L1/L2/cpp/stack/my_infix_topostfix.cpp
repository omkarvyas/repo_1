#include<iostream>
#include<stack>
#include<cstring>
#include<sstream>
using namespace std;

int calculate(int op1, int op2, char operand);
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


/*Evaluation of post fix expression*/
/*
 1. Scan the expression from left to right if you get oprands convert them to the number before pushing to stack.
 2. first we encounter the operands, place them to the stack 
 3. we are unsure what to do next with them until you see the next symbol. Placing each operand on stack ensures that they are avilable if operator comes next.
 4. If we we get operands push it on stack, if we get operator pop recently pushed 2 operands. WE will have to push this result back to the stack.
 5. When the final operator is porcessed there will be only one value left on stack. Pop it and return.
 
 */


int pfix_eval(string str){

stringstream ss;

/*storing the string in to string stream*/

ss << str;

string temp;
int found;
char operand = 0;
int op1 = 0;
int op2 = 0;
int eval = 0;

stack <int> my_int_stack;


    while(!ss.eof()){
/*extracintg word by word from stream */
        ss>>temp;
        cout<<"temp before operation: "<<temp<<endl;


/*checking the given word is integer or not*/
        if(stringstream(temp) >>found){
            cout << found << " ";
            my_int_stack.push(found);
        
        }else{
            
            op1 = my_int_stack.top();
            my_int_stack.pop();
            op2 = my_int_stack.top();
            my_int_stack.pop();

            if(temp == "+"){
        
                 cout<<"found addition "<<temp<<endl;
                 operand = '+';
        
            }else if(temp == "-"){
        
                 cout<<"found subtraction "<<temp<<endl;
                 operand = '-';
        
            }else if(temp == "*"){
        
                 cout<<"multiplication "<<temp<<endl;
                 operand = '*';
        
            }else if(temp == "/"){
        
                 cout<<"divide "<<temp<<endl;
                 operand = '/';
        
            }else if(temp == "^"){
        
                 cout<<"power "<<temp<<endl;
                 operand = '^';
        
            }else{
                cout<<"Error temp is not valid temp == "<<temp<<endl;
                return 0;
            
            }

            eval = calculate(op1,op2,operand);
            cout <<"Intermidiate evaluation eval:"<<eval<<endl;
            my_int_stack.push(eval);
        
        }

    }

    eval = my_int_stack.top();
    cout<<"Fianl output:"<<eval<<endl;
    return eval;

}

int calculate(int op1, int op2, char operand){

    switch (operand){
    
            case '+': return op1+op2;
                      break;
    
            case '-': return op1-op2;
                      break;
    
            case '*': return op1*op2;
                      break;
    
            case '/': return op1/op2;
                      break;
    
            case '^': return op1^op2;
                      break;
    
    
    }


}


int main(){

char *p = NULL;

char arr[] = "(a+b)*(c+d)";

p = infix_to_post_fix(arr);
cout <<"\n"<<"Infix expression:"<<arr<<"\t\t\t"<<"to the post fix expression:"<<p<<"\n"<<endl;

/* ab+cd+* */

string exp =  "10 20 + 30 40 + *";

int v = pfix_eval(exp);


return 0;


}








