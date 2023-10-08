#include<iostream>
using namespace std;
class Shape{
	int s,l,b;
	public :
		int area(int le,int br){
			l=le,b=br;
			return (l*b);
		}
		int area(int si){
			s=si;
			return (s*s);
		}
};
int main(){
	Shape obj;
	int side,length,breadth;
	cout<<"Enter side of square, length and breadth of rectangle :";
	cin>>side>>length>>breadth;
	cout<<"Area of square is :"<<obj.area(side)<<endl;
	cout<<"Area of rectangle is :"<<obj.area(length,breadth)<<endl;
	return 0;
}