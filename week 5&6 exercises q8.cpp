#include<iostream>
using namespace std;
class shape{
	int a;
	public :
		void getin(){
			cin>>a;
		}
		shape operator *(shape s){
			shape k;
			k.a=a*s.a;
			return k;
		}
		void area(){
			cout<<a;
		}
};
int main(){
	shape s1,s2,mul;
	s1.getin(),s2.getin();
	mul=s1*s2;
	mul.area();
	return 0;
}