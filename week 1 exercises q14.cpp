#include<iostream>
using namespace std;

int main(){
	int x,y,sum=0;
	cout<<"Enter two numbers"<<endl;
	cin>>x>>y;
	sum=x+y;
	if(sum>=105&&sum<=200){
		sum=200;
	}
	cout<<"The sum is :"<<sum<<endl;
	return 0;
}