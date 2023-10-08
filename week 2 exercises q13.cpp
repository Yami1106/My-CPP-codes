#include<iostream>
using namespace std;

int fibo(int n){
	if(n==1||n==2){
		return 1;
	}
	else{
		return fibo(n-2)+fibo(n-1);
	}
}

int main(){
	int k,i;
	cin>>k;
	for(i=1;i<=k;i++)
	cout<<fibo(i)<<" ";
	return 0;
}