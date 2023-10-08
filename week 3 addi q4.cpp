#include<iostream>
using namespace std;
class cube{
	private:
	int l,b,h,v;
	public :
	 cube(int l,int b,int h){
	 	v=l*b*h;
	}
	void output(){
	cout<<v<<endl;
	}
	~ cube(){
		cout<<"destructor invoked"<<endl;
	}
};
int main(){
	int a,b,c;
	cin>>a>>b>>c;
	cout<<"The volume of cube is :";
	cube c1=cube(a,b,c);
	c1.output();
	return 0;
}