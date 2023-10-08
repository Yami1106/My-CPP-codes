#include<iostream>
using namespace std;

int main(){
	int rows=9,i,j;
	for(i=rows;i>0;i--){
		for(j=i;j>0;j--){
			cout<<i;
		}
		cout<<"\n";
	}
	return 0;
}