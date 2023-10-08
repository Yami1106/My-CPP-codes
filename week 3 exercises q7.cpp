#include<iostream>
#include<iomanip>
using namespace std;
class average{
	public :
	static int func(int a,int b,int c){
		return (a+b+c)/3;
	}
};

int main(){
	int l,m,n;
	cin>>l>>m>>n;
	cout<<"The average is :"<<average::func(l,m,n)<<endl;
	return 0;
}