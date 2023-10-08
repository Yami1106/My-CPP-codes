#include<iostream>
using namespace std;
class Pro{
	protected :
		string s="I am a protected data member";
};
class Print:public Pro{
	public:
	void disp(){
		cout<<s;
	}
};
int main(){
	Print p;
	p.disp();
	return 0;
}

	
	