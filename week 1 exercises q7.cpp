#include<iostream>
using namespace std;

int main(){
	int i,j;
	int rows=4;
	for(i=0;i<=rows;i++){
		for(j=0;j<=i;j++){
			cout<<"* ";
		}
		cout<<"\n";
	}
	for(i=rows-1;i>=0;i--){
		for(j=i;j>=0;j--){
			cout<<"* ";
		}
		cout<<"\n";
	}
	return 0;
}