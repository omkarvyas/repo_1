#include<iostream>
#include<stack>

using namespace std;

unsigned int number_of_digits(int x){
    
    if(x<9)return 1;
    if(x<99)return 2;
    if(x<999)return 3;
    if(x<9999)return 4;
    if(x<99999)return 5;
    if(x<999999)return 6;
    if(x<9999999)return 7;
    if(x<99999999)return 8;
    if(x<999999999)return 9;
    if(x<9999999999)return 10;
    
    
}

bool isPalindrome(int x) {
        if(x < 0)
            return false;
        if(!x)
            return true;
        bool odd_flag = 0;
        /*Check number of digits*/
        int digits = number_of_digits(x);
        /*use stack as auxilury data struct*/
        stack<int> my_stk;
        //cout<<"digits:" <<digits<<endl;
        /*half number we are intereseted if it matches the first half so push last half digits to stack*/
        if(digits%2){
            //cout<<"number of digits are odd"<<endl;
            
            digits = digits/2+1;
            odd_flag = 1;
        }else{
            //cout<<"number of digits are odd"<<endl;
            digits = digits/2;
        }
      
        while(digits){
                
            my_stk.push(x%10);
            x = x/10;
            digits--;
                        
        }
        if(odd_flag){
            
            my_stk.pop();
            
        }
        
        while(x){
            /*pop the elemnts from the stack and compare it fisrt half of the number when breaks return false.. */
            if(my_stk.empty() != true){
                
                if(x%10 != my_stk.top()){
                    
                    return false;
                
                }
                my_stk.pop();
                x = x/10;
            }
            
        }
        
            
     return true;   
}

int main(){
	int number = 0;
	
	cout<<"Enter a number:"<<endl;
	cin>>number;
	if(isPalindrome(number)){
		
		cout<<"Number: "<<number<<"   is palindrome"<<endl;
		
	}else{
		
		cout<<"Number: "<<number<<"   is not palindrome"<<endl;
	}
	
	
}




