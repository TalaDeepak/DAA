#include<iostream>
#include <string.h>
#include <chrono>

using namespace std;

int gap = 2; // cost of gap
int misMatch =3; // cost of mismatch in the string 

int n; // will store the size of first string 
int m; // will store the size of second string

int t[5][5]; // dp array used for memoization 


int stringMatching(string &s1,string &s2,int i ,int j){
    if(i == n){
        return gap*(m-j);
    }
    if(j == m){
        return gap*(n-i);
    }

    if(t[i][j] != -1){
        return t[i][j];
    }

    if(s1[i] == s2[j]){
        return t[i][j] = stringMatching(s1,s2,i+1,j+1);
    }

    int mis = misMatch + stringMatching(s1,s2,i+1,j+1); // when we decided to keep the mismatch

    int gap1 = gap + stringMatching(s1,s2,i+1,j); // when we shift the second strign and created a gap 
    int gap2 = gap + stringMatching(s1,s2,i,j+1); // when we shift the first string and created a gap

    return t[i][j] = min(min(mis,gap1),gap2);

}

void someFunction() {
    // Simulate some work
    for (volatile int i = 0; i < 1e7; ++i);
}

int main(){
    string s1;
    string s2;
    cout<<"Enter first string"<<endl;
    cin>>s1;
    cout<<"Enter second string "<<endl;
    cin>>s2;

    n = s1.size();
    m = s2.size();
    
    auto start = chrono::high_resolution_clock::now();

    cout<<stringMatching(s1,s2,0,0)<<endl;
    // someFunction();

    auto end = chrono::high_resolution_clock::now();
    chrono::duration<double> duration = end - start;

    cout << "Execution time: " << duration.count() << " seconds\n";

    return 0;
}