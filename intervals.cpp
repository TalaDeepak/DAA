#include<iostream>
#include<vector>
using namespace std;

class Job{
    public:
        int startTime;
        int finishTime;
        int profit;
        Job(int s,int f,int p){
            startTime = s;
            finishTime = f;
            profit = p;
        }
};

int main(){
    vector<Job> profit;

    for(int i = 0 ;i<6;i++){
        int profit;
        int start;
        int finish;
        cout<<"Enter the start time for "<<i+1 <<" job "<<endl;
        cin>>start;
        cout<<"Enter the finish time for "<<i+1 <<" job "<<endl;
        cin>>finish;
        cout<<"Enter the profit for "<<i+1<<" job "<<endl;

    }
    return 0;
}