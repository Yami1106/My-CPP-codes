#include<bits/stdc++.h>
using namespace std;
int main(){
	int a,b;
	cin>>a>>b;
	try{
		if(b!=0){
			cout<<"quotient:"<<a/b;
		}
		else{
			throw b;
		}
	}
	catch(int i){
		cout<<"division by zero not allowed!";
	}
	return 0;
}