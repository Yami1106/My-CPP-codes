#include<iostream>
using namespace std;
class Marks{
	public :
	 virtual void getpercentage()=0;
};
class A:public Marks{
	public :
		float m1,m2,m3,avg;
		A(){
			cout<<"Enter marks scored by A:";
			cin>>m1>>m2>>m3;
		}
		void getpercentage(){
			avg=((m1+m2+m3)/300)*100;
			cout<<"Percentage marks for A:"<<avg<<endl;
		}
};
class B:public Marks{
	public :
		float mb1,mb2,mb3,mb4,avgb;
		B(){
			cout<<"Enter marks scored by B:";
			cin>>mb1>>mb2>>mb3>>mb4;
		}
		void getpercentage(){
			avgb=((mb1+mb2+mb3+mb4)/400)*100;
			cout<<"Percentage marks for B:"<<avgb<<endl;
		}
};
int main(){
	Marks *M;
	A a;
	B b;
	a.getpercentage();
	b.getpercentage();
	return 0;
}