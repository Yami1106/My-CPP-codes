#include<iostream>
using namespace std;

int main(){
	int i,u,t,h;
	for(i=100;i<400;i++){
		u=i%10;
		t=((i%100)-u)/10;
		h=(i-(i%100))/100;
		if((u%2==0)&&(t%2==0)&&(h%2==0)){
			cout<<i<<",";
		}
	}
	if(400==400){
		cout<<"400";
	}
	return 0;
}