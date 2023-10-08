#include<iostream>
using namespace std;

void swap(int a, int b){
	int temp;
	temp=a;
	a=b;
	b=temp;
	cout<<a<<"\n"<<b;
} 

int main(){
	int n1,n2;
	cin>>n1>>n2;
	swap(n1,n2);
	return 0;
}