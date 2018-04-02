#include <iostream>
using namespace std;
#define MAX 100

class Stack{
    int stk_ptr;
    int arr[MAX];
public:
    Stack(){
        stk_ptr = -1;
    }
    void push(int data);
    int pop();
    bool isempty();
    bool isfull();
    int top();
};

int Stack::pop(){
                   
            cout<<"in pop"<<endl;
            if(isempty()){
            
                cout<< "Stack is empty nothing can be popped"<<endl;
                return -1;
            
            }
            stk_ptr--;
        }
bool Stack::isempty(){
                
            cout<<"in isempty"<<endl;
            if(stk_ptr == -1){
                return true;
            }
            return false;
}

bool Stack::isfull(){
                 
            cout<<"in isfull"<<endl;
            if(stk_ptr == MAX){
                return true;
            }
            return false;

        
}
int Stack::top(){
            int stack_top_val = 0;
            cout<<"in top"<<endl;
            cout<<"stk_ptr:"<<stk_ptr<<endl;
            stack_top_val = arr[stk_ptr];
            return stack_top_val;
}


void Stack::push(int data){
            cout<<"in push"<<endl;
            stk_ptr++;
            cout<<"stk_ptr:"<<stk_ptr<<endl;
            arr[stk_ptr] = data;
}


int main(){
    Stack mystack;

    mystack.push(10);
    mystack.push(20);
    mystack.push(30);
    mystack.push(40);
    mystack.push(50);
    int i = mystack.pop();
    bool x = mystack.isempty();
    bool y = mystack.isfull();    
    int j = mystack.top();
    cout<< "stack top: " <<j<<endl;
    return 0;

}
