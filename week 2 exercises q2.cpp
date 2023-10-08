#include<iostream>
using namespace std;

int main(){
	int a;
	cin>>a;
	if(a!=0){
		if(a>0){
			cout<<"Entered number is positive"<<endl;
		}
		else {
			cout<<"Entered number is negative"<<endl;
		}
	}
	else{
		cout<<"The number is 0"<<endl;
	}
	return 0;
}