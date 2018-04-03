#include<iostream>
#include<cstring>
#include<stack>

using namespace std;

int prec(char inp){

    if(inp == '^'){
    
        return 3;
        
    }if(inp == '*' || inp == '/' ){
    
        return 2;
    
    }if(inp == '+' || inp == '-'){
    
        return 1;
    }

    return 0;


}


char * infix_to_postfix(char arr[]){
    cout<<"Input string: "<<arr<<endl;
    int size = strlen(arr);
    cout<<"Input string length: "<<size<<endl;
    stack<char> mystk;
    int i = 0;
    int j = 0;
    char out_arr[100];
    int tmp = 0;
    int x = 0;
    char ch_tp =0;
    char tx = 0;
    for(i = 0; i < size;){
    
        if(arr[i] >= 'a' && arr[i] <= 'z' ){
        out_arr[j] = arr[i];
        j++;
        i++;        
        }else if(arr[i]== ')'){

            while(ch_tp != '('){
            ch_tp = mystk.top();
            if(ch_tp == '(')break;
            out_arr[j] = ch_tp;
            j++;
            mystk.pop();
            }
            mystk.pop();
            i++;

        }else{
        /*case where arr[i] could be (, ^, *, /, +, -*/

            if(mystk.empty()== true){
                mystk.push(arr[i]);
                i++;
                            
            }else{
            
                tmp = prec(arr[i]);
                
                tx = mystk.top();

                x = prec(tx);
                if(tmp<x){
                    
                    out_arr[j] = mystk.top();
                    mystk.pop();
                    mystk.push(arr[i]);
                    i++;
                    j++;

                }else{
                    mystk.push(arr[i]);
                    i++;
                
                }
            
            
            }
        
        
        }
    
    
    }
    while(mystk.empty() != true){
    
    out_arr[j] = mystk.top();
    mystk.pop();
    j++;
    
    }
    out_arr[j] = '\0';
    cout<<"out put array:"<<out_arr<<endl;
    cout<<"out put array length :"<<strlen(out_arr)<<endl;

}

int main(){

    char arr[] = "a^b*(c+d)";

    infix_to_postfix(arr);

    return 0;


}

