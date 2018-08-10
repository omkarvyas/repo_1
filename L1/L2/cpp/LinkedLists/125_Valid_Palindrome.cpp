#include<iostream>
#include<stack>
#include<string>
#include <algorithm>
using namespace std;

bool isPalindrome(string s) {
        if(s.empty()){
            
            return true;
        }
        stack<char> my_stk;
        bool odd_flag = 0;
        string::iterator it;
        char temp = ' ';
        int count = 0;
        
        for(string::iterator i = s.begin(); i != s.end(); i++)
        {
            if(!isalnum(s.at(i - s.begin())))
            {
                s.erase(i);
            i--;
            }
        }
        //cout<<"after removing non alphanumeric "<<s<<endl;
        transform(s.begin(), s.end(), s.begin(), ::tolower);
        cout<<s<<endl;
        
        int length = s.size();
        cout<<length<<endl;
        
      
        if(length%2){
            
            //cout<<"string is odd";
            length = (length/2)+1;
            odd_flag = 1;
        }else{
            
            length = length/2;
        }
        it = s.begin();
        while(length){
            my_stk.push(*it);
            ++it;
            --length;
            ++count;
        }
        //cout<<"*it ="<<(*it)<<endl;
        //cout<<"count = "<<count<<endl;
        
        if(odd_flag && my_stk.empty()!=true){
            //cout<<"remove the middle element of the string and make it even"<<endl;
            my_stk.pop();
        }
        
        while(it!=s.end()){
            
            if(my_stk.empty()!=true){
                temp = my_stk.top();
                //cout<<"temp ="<<temp<<endl;
                //cout<<"*it ="<<(*it)<<endl;
                my_stk.pop();
            }
            
            if((*it) != temp){
                    return false;
            }
                
                ++it;
        }
        
        return true;
                      
}


int main(){
	
	if(isPalindrome("heeh")){
		
		cout<<"string: is palindrome"<<endl;
		
	}else{
		
		cout<<"string: is not palindrome"<<endl;
	}
return 0;		
}

