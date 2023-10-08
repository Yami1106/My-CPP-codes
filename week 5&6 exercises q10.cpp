#include<iostream>
#define PI 3.14
using namespace std;
class shape{
	double s;
	public :
		void getin(){
			cin>>s;
		}
	shape operator *(shape c){
	shape k;
	k.s=s*c.s;
	return k;
	}
	void disp(){
		cout<<s;
	}
};
int main(){
	shape sq,ci,ar,arci;
	ar=sq*sq;
	sq.getin();
	ci.getin();
	arci= PI *ci*ci;
	ar.disp();
	arci.disp();
	return 0;
}