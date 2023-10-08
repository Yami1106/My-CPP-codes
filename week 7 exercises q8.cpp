#include<iostream>
using namespace std;
class Base{
	private:
	string s="I am private";
	protected:
	string a="I am protected";
	public:
	string d="I am public";
	Base(){
		cout<<s<<endl;
	}			
};
class Child:public Base{
	public :
		void display(){
			cout<<a<<"\n"<<d<<endl;
		}
};
int main(){
	Child c;
	c.display();
	return 0;
}