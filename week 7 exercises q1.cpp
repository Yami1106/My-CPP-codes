#include<iostream>
using namespace std;
class Student{
	protected :
		string name;
		int roll_no;
		void getname();
		void getno();
};
class Info: public Student{
	public :
	getname(){
		cin>>name;
	}
	getno(){
		cin>>roll_no;
	}
	void display(){
		cout<<"The student's name is:"<<name<<endl;
		cout<<"The student's roll no is :"<<roll_no<<endl;
	}
};
int main(){
	Info st1;
	st1.getname();
	st1.getno();
	st1.display();
	return 0;
}
