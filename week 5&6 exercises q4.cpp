#include<iostream>
using namespace std;
class Inc{
	int i=0;
	public :
		void operator ++(){
			++i;
		}
		void op1(){
			cout<<"count ="<<i<<endl;
		}
		void operator ++(int){
			i++;
		}
		void op2(){
		cout<<"count ="<<i<<endl;
		}
};
int main(){
	Inc count;
	++count;
	count.op1();
	count++;
	count.op2();
	return 0;
}