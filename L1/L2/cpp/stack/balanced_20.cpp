#include<iostream>
#include<stack>
#include<string>
#include<cstdio>

using namespace std;

class Solutions{
int stk_ptr;
    public:
        Solutions(){
        stk_ptr = -1;
        }
        stack <char> my_stack;
        bool isValid(string s){
            cout << s <<endl;
            int size = s.size();
            int i = 0;
            char ele = 0;
            cout << "\n string length:" <<s.size()<<endl;
            char arr[size+1];
            sprintf(arr,"%s",s.c_str());
            cout<<"arr:"<<arr;
            
            for(i = 0; i <size; i++){
            
                if(arr[i] == '(' || arr[i] == '[' || arr[i] == '{'){
                    my_stack.push(arr[i]);            
                }

                if(arr[i] == ')'){
                    if(my_stack.empty() != true){
                        ele = my_stack.top();
                            if(ele != '('){
                                return false;
                            }
                        my_stack.pop();
                    }else{
                            return false;
                    }
               
                }else if(arr[i] == ']'){
                    if(my_stack.empty() != true){
                        ele = my_stack.top();
                            if(ele != '['){
                                return false;
                            }
                        my_stack.pop();
                    }else{
                        return false;
                    }
                
                }else if(arr[i] == '}'){
                    if(my_stack.empty() != true){
                        ele = my_stack.top();
                            if(ele != '{'){
                                return false;
                            }
                        my_stack.pop();
                    }else{
                        return false;
                    }
                               
                }
            }
            if(my_stack.empty() == true){
                return true;
            }else{
                return false;
            }
        }
};

int main(){


Solutions my_sol;

string s = "{([x+y]*b)a+b}";

bool x = my_sol.isValid(s);
        if(x){
        
        cout<<"Balanced braces" <<endl;
        
        }else{
                
        cout<<"not balanced braces" <<endl;
        
        }

return 0;

}







