#include<iostream>
#define PI 3.14
using namespace std;
class Calc{
	int s;
	float r1,r2,h;
	public :
		int volume(int s){
			return (s*s*s);
		}
		float volume(float r1,float h){
			return (PI*r1*r1*h);
		}
		float volume(float r2){
			return ((4/3)*PI*r2*r2*r2);
		} 
};
int main(){
	Calc obj;
	int l;
	float ra1,ra2,h;
	cout<<"Enter length of cube :";
	cin>>l;
	cout<<"Enter radius and the height of cylinder :";
	cin>>ra1>>h;
	cout<<"Enter radius of sphere :";
	cin>>ra2;
	cout<<"Volume of cube is : "<<obj.volume(l)<<endl;
	cout<<"Volume of cylinder is :"<<obj.volume(ra1,h)<<endl;
	cout<<"Volume of sphere is : "<<obj.volume(ra2)<<endl;
	return 0;
}