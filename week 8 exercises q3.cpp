#include<iostream>
using namespace std;
class B;
class A{
	public :
		int a;
		A(){
			cout<<"Enter a:";
			cin>>a;
		}
		friend int sum(A,B);
};
class B{
	public :
		int b;
		B(){
			cout<<"Enter b:";
			cin>>b;
		}
		friend int sum(A,B);
};
int sum(A a1,B b1){
	return a1.a+b1.b;
	
}
int main(){
	A a1;
	B b1;
	cout<<"Sum :"<<sum(a1,b1);
	return 0;
}

