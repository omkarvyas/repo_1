#include<iostream>
#include<stack>
#include<cstring>

using namespace std;

/*
Suppose there is a circle. There are N  petrol pumps on that circle. Petrol pumps are numbered 0 to (N-1)  (both inclusive). You have two pieces of information corresponding to each of the petrol pump: (1) the amount of petrol that particular petrol pump will give, and (2) the distance from that petrol pump to the next petrol pump.

Initially, you have a tank of infinite capacity carrying no petrol. You can start the tour at any of the petrol pumps. Calculate the first point from where the truck will be able to complete the circle. Consider that the truck will stop at each of the petrol pumps. The truck will move one kilometer for each litre of the petrol.

Input Format

The first line will contain the value of N.
The next  N lines will contain a pair of integers each, i.e. the amount of petrol that petrol pump will give and the distance between that petrol pump and the next petrol pump.

Constraints:
1<= N < 10^5;
1<= amount of petrol and distance <=10^9;

Output Format

An integer which will be the smallest index of the petrol pump from which we can start the tour.
*/

class Truck_Tour{
    
    public:
        int i;
        struct TT{
        int fuel;
        int dist;
        };
        typedef struct TT TT;
        TT arr[3];
        int find_starting_point(Truck_Tour::TT arr[], int size);
        
};



int Truck_Tour::find_starting_point(Truck_Tour::TT arr[], int size){
int rem_distance = 0;
int count = 0;
    for(int i=0;i<size;i++){
            rem_distance = 0;
            count = 0;
        for(int j = i;j<size+i;j++){
            rem_distance = rem_distance + (arr[j%size].fuel - arr[j%size].dist);
            cout<<"j =  "<<j <<"rem_d =   " <<rem_distance << "i =    " <<i<<endl;
                if(rem_distance < 0){
                    cout<<"In the rem_dist<0"<<endl;
                    break;
                }
                count++;
                if(count == size){
                    return i;
                }
        }
    
    }
return -1;
}



int main(){
    Truck_Tour x;
    x.arr[0].fuel = 12;
    x.arr[0].dist = 11;
    x.arr[1].fuel = 2;
    x.arr[1].dist = 1;
    x.arr[2].fuel = 1;
    x.arr[2].dist = 1;
    
    int result = x.find_starting_point(x.arr,(sizeof x.arr/sizeof x.arr[0]));
    cout<<"Starting Point = "<<result<<endl;
    return 0;
}


