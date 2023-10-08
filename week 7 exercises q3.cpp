#include<iostream>
using namespace std;
class Number{
	protected:
		int no;
		Number(){
		cout<<"Enter number:";
		cin>>no;
	}
};
class square:public Number{
	public :
	int sq;
	void calc1(){
	sq=no*no;
	cout<<"The square of number is :"<<sq<<endl;
}
};
class cube:public Number{
	public:
	int cu;
	void calc2(){
		cu=no*no*no;
		cout<<"The cube of number is:"<<cu<<endl;
	}
};
int main(){
	square s;
	s.calc1();
	cube c;
	c.calc2();
	return 0;
}

