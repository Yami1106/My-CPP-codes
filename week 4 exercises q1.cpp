#include<iostream>
using namespace std;
class Student{
	string name;
	public :
		Student(string s){
			name=s;
				cout<<name<<endl;
			}
			Student(){
				cout<<"Unknown"<<endl;
			}
};
int main(){
	cout<<"Enter the name of students :";
	Student obj=Student("Sam");
	Student obj2;
	return 0;
}