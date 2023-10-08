#include<iostream>
using namespace std;
class AddAmount{
	int amount=50;
	public :
	AddAmount(){
		amount+=0;
		cout<<amount<<endl;
	}
	AddAmount(int n){
		amount+=n;
		cout<<amount<<endl;
	}
};
int main(){
	int m;
	cout<<"Enter the amount to be added : $";
	cin>>m;
	cout<<"\n"<<"The initial amount in piggy bank is : $";
	AddAmount obj1=AddAmount();
	cout<<"\n"<<"The final amount in the piggy bank is : $";
	AddAmount obj2=AddAmount(m);
	return 0;
}