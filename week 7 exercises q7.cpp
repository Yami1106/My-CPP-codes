#include<iostream>
using namespace std;
class Dimensions{
	public :
		int l,b;
};
class Area:public Dimensions{
	public :
		int area;
			Area(){
			cout<<"Enter length, breadth:";
			cin>>l>>b;
			area=l*b;
		}
};
class Volume:public Area,public Dimensions{
	public :
		int h,vol;
		Volume(){
			cout<<"The area is :"<<area<<" sq units"<<"\n"<<"Enter height :";
			cin>>h;
		}
		void out2(){
			vol=Area::area*h;;
			cout<<"The volume is :";
			cout<<vol<<" cubic units"<<endl;
		}
};
int main(){
	Volume v;
	v.out2();
	return 0;
}

