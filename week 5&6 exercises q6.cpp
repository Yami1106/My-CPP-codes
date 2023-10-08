#include<iostream>
using namespace std;
class operation{
	float a;
	public :
		void getin(){
			cin>>a;
		}
		operation operator +(operation s){
			operation k;
			k.a=a+s.a;
			return k;
		}
		void add(){
			cout<<a;
		}
		operation operator -(operation s){
			operation k;
			k.a=a-s.a;
			return k;
		}
		void diff(){
			cout<<"\n"<<a;
		}
		operation operator *(operation s){
			operation k;
			k.a=a*s.a;
			return k;
		}
		void pro(){
			cout<<"\n"<<a;
		}
		operation operator /(operation s){
		operation k;
		k.a=a/s.a;
		return k;
		}
		void quo(){
		cout<<"\n"<<a;
		}
		operation operator %(operation s){
		operation k;
		k.a=int(a) % int(s.a);
		return k;
		}
		void rem(){
		cout<<"\n"<<a;
		}
		
};
int main(){
	operation op1,op2,sum,sub,mul,div,mod;
	op1.getin();
	op2.getin();
	sum=op1+op2;
	sub=op1-op2;
	mul=op1*op2;
	div=op1/op2;
	mod=op1%op2;
	sum.add();
	sub.diff();
	mul.pro();
	div.quo();
	mod.rem();
	return 0;
}