#include<iostream>
using namespace std;
class Base{
	public :
		virtual void print(){
			cout<<"I'm Base"<<endl;
		}
		void display(){
			cout<<"In Base"<<endl;
		}
};
class Derived:public Base{
	public:
	void print(){
		cout<<"I'm Derived"<<endl;
	}
	void display2(){
		cout<<"In Derived"<<endl;
	}
};
int main(){
	Base *b;
	Derived d;
	d.print();
	b->display();
	d.display2();
	return 0;
}