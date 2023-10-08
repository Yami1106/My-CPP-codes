#include<iostream>
using namespace std;

int main(){
	int i,j;
	for(i=100;i<=500;i++){
		for(j=1;j<=i;j++){
		if(i%j==0){
			cout<<"Number is not prime"<<endl;
		}
		else{
			cout<<i<<" ";
		}
		}
	}
}