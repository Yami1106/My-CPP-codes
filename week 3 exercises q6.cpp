#include<iostream>
#include<cmath>
#include<iomanip>
using namespace std;
class tri{
	float perimeter,area,s;
	public :
		void func(int a,int b,int c){
			perimeter= (a+b+c);
			s=(a+b+c)/2;
			area=sqrt(s*(s-a)*(s-b)*(s-c));
			cout<<"Perimeter is :"<<perimeter<<endl;
			cout<<"Area is : "<<fixed<<setprecision(2)<<area<<endl;
		}
	
};
int main(){
	tri triangle;
	triangle.func(3,4,5);
	return 0;
}