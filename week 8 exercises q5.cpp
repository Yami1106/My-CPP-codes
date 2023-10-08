#include<iostream>
using namespace std;
class polygon{
	public :
		virtual void area()=0;
};
class triangle:public polygon{
	public :
		int b,h;float art;
		triangle(){
			cout<<"Enter base and height :";
			cin>>b>>h;
		}
		void area(){
			art=0.5*b*h;
			cout<<"Area of triangle :"<<art<<endl;
		}
};
class rectangle:public polygon{
	public :
		int l,b,ar;
		rectangle(){
			cout<<"Enter length and breadth :";
			cin>>l>>b;
		}
		void area(){
			ar=l*b;
			cout<<"Area of rectangle :"<<ar<<endl;
		}
};
int main(){
	polygon *p;
	triangle t;
	rectangle r;
	t.area();
	r.area();
	return 0;
}