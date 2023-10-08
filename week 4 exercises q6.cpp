#include<iostream>
using namespace std;
class Swapping{
	int a,b;
	float c,d;
	public :
	void swap(int *a,int *b){
		int temp;
		temp=*a;
		*a=*b;
		*b=temp;
		cout<<"after swapping :"<<*a<<" "<<*b<<endl;
	}
	void swap(float *c,float *d){
		float temp;
		temp=*c;
		*c=*d;
		*d=temp;
		cout<<"after swapping :"<<*c<<" "<<*d;
	}
};
int main(){
	Swapping obj;
	int x,y;
	float k,m;
	cout<<"Enter the integers :";
	cin>>x>>y;
	cout<<"Enter the float values :";
	cin>>k>>m;
	obj.swap(&x,&y);
	obj.swap(&k,&m);
	return 0;
}