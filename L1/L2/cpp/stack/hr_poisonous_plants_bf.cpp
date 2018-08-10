#include<iostream>
#include<stack>
#include<cstring>
#include<vector>
/*
 There are n  plants in a garden. Each of these plants has been added with some amount of pesticide. After each day, if any plant has more pesticide than the plant on its left, being weaker than the left one, it dies. You are given the initial values of the pesticide in each plant. Print the number of days after which no plant dies, i.e. the time after which there are no plants with more pesticide content than the plant to their left.
 

input:

The input contains of an integer n. The next line contains n integers, describing the array p where p denotes the amount of pesticide in plant i.
 
Output:
Output an integer equal to the number of days after which no plants die.
 Initially all plants are alive.

 Plants = {(6,1), (5,2), (8,3), (4,4), (7,5), (10,6), (9,7)}

 Plants[k] = (i,j) => jth plant has pesticide amount = i.

 After the 1st day, 4 plants remain as plants 3, 5, and 6 die.

 Plants = {(6,1), (5,2), (4,4), (9,7)}

 After the 2nd day, 3 plants survive as plant 7 dies.

 Plants = {(6,1), (5,2), (4,4)}

 After the 3rd day, 3 plants survive and no more plants die.

 Plants = {(6,1), (5,2), (4,4)}

 After the 2nd day the plants stop dying.

 
 */



using namespace std;

int no_plants_would_die(vector<int> in, int no_of_plants){

        if(in.size()==0){
        
            return 0;
        
        }
int i = no_of_plants;

}

int main(){

    vector<int> arr = {6,5,8,4,7,10,9};
    int after_these_days = no_plants_would_die(arr,arr.size());
    cout<<"After these many dayes: "<<after_these_days<<"No plants would die"<<endl;
    return 0;



}








