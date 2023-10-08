#include<iostream>
using namespace std;
class Complex{
	int re,im;
	public :
		void getin(){
			cin>>re>>im;
		}
		Complex operator +(Complex C){
			Complex k;
			k.re=re+C.re;
			k.im=im+C.im;
			return k;
		}
		void add(){
			cout<<re<<"+"<<"i"<<im<<endl;
		}
		Complex operator -(Complex C){
			//for re>C.re & im>C.im
			Complex k;
			k.re=re-C.re;
			k.im=im-C.im;
			return k;
		}
		void sub(){
			cout<<re<<"+"<<"i"<<im<<endl;
		}	
};
int main(){
	Complex x,y,sum,diff;
	x.getin(),y.getin();
	cout<<"x=";
	x.add();
	cout<<"y=";
	y.add();
	sum=x+y;
	cout<<"sum =";
	sum.add();
	diff=x-y;
	cout<<"difference =";
	diff.sub();
	return 0;
}