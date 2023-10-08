//   Convert this program to C++

// change to C++ io

//  change to one line comments

//  change defines of constants to const

//  change array to vector<>

//  inline any short function

#include<iostream>
#include<vector>
#include<numeric>
using namespace std;
const int N=40;

inline int sum(vector<int> v){
    return (accumulate(v.begin(),v.end(),0));
}
int main(void){
    int accum;
    vector<int> v;
    for(int i=0;i<N;i++){
        v.push_back(i);
}
accum=sum(v);
    cout<<"sum is "<<accum<<endl;
    return 0;
}
