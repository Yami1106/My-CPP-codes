#include<iostream>
using namespace std;
class Swap{
	int a;
	public :
		void getin(){
			cin>>a;
		}
		Swap operator +(Swap s){
			Swap k;
			k.a=a+s.a;
			return k;
		}
		Swap operator -(Swap s){
			Swap k;
			k.a=a-s.a;
			return k;
		}
		void disp(){
			cout<<a;
		}
};
int main(){
	Swap x,y,sum=x,diff=y;
	cout<<"Enter x :";
	x.getin();
	cout<<"Enter y :";
	y.getin();
	sum=x+y;
	diff=sum-y;
	sum=sum-diff;
	cout<<"After swapping x:";
	sum.disp();
	cout<<"\n"<<"After swapping y:";
	diff.disp();
	return 0;
}
