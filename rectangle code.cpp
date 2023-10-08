#include<iostream>
using namespace std;
int main(){
	int a,b,c,d;
	cin>>a>>b>>c>>d;
	if (a==b==c==d){
		cout<<"Yes";
	}
	else if((a==c&&b==d)||(a==b&&c==d)||(a==d&&b==c)){
		cout<<"Yes";
	}
	else {
		cout<<"No";
	}
	return 0;
}