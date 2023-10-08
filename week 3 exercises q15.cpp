#include<iostream>
using namespace std;

class math{
	public :
	void fac(int n);
};
void math::fac(int n){
	int i,res=1;
	for(i=n;i>0;i--){
		res*=i;
	}
	cout<<res<<endl;
}
int main(){
	math calc;
	int a;
	cin>>a;
	cout<<"Factorial is :";
	calc.fac(a);
	return 0;
}