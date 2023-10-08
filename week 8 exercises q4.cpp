#include<iostream>
#define PI 3.14
using namespace std;
class Shape{
	public :
		virtual void Area()=0;
};
class rectangle:public Shape{
	public :
		int l,b,ar;
		rectangle(){
			cout<<"Enter length and breadth :";
			cin>>l>>b;
		}
		void Area(){
			ar=l*b;
			cout<<"Area of rectangle :"<<ar<<endl;
		}
};
class square:public Shape{
	public :
		int s,ars;
		square(){
			cout<<"Enter side of square :";
			cin>>s;
		}
		void Area(){
			ars=s*s;
			cout<<"Area of square :"<<ars<<endl;
		}
};
class circle:public Shape{
	public :
		int r;float arc;
		circle(){
			cout<<"Enter radius :";
			cin>>r;
		}
		void Area(){
			arc=PI*r*r;
			cout<<"Area of circle :"<<arc<<endl;
		}
};
int main(){
	Shape *sh;
	rectangle re;
	square sq;
	circle c;
	re.Area();
	sq.Area();
	c.Area();
	return 0;
}
