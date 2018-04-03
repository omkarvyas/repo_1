#include<iostream>
#include<cstring>
#include<stack>

using namespace std;

class Solution{

    public:
        int calc(string s);


};

int Solution::calc(string s){

    stack <char> my_stk;
    int i = 0;
    int size = s.length();
    char in_char = 0;

    for(i = 0; i < size; i++){
        
        if(s[i] != ' '){
        my_stk.push(s[i]);
        i++;
        }

        if(s[i] == ')'){
        
        in_char = my_stk.top();
        if(in_char == '+'){

        
        }
        }

        cout << "Input string:i =  "<<i << " s[i] = "<<s[i]<<endl;
        
        
        
    
    }
return 0;

}


int main(){

Solution my_sol;

int ans = 0;
string s = "255 + 133";
ans = my_sol.calc(s);
return 0;

}


