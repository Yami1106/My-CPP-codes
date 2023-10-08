#include<bits/stdc++.h>
using namespace std;
template<typename T>
T swap(T *a,T *b){
	T temp;
	temp=*a;
	*a=*b;
	*b=temp;
	return temp;
}
int main(){
	int a,b;
	float c,d;
	string x,y;
	cout<<"integers:";
	cin>>a>>b;
	swap(&a,&b);
	cout<<"after swap: "<<a<<" "<<b<<endl;
	cout<<"float:";
	cin>>c>>d;
	swap(&c,&d);
	cout<<"after swap: "<<c<<" "<<d<<endl;
	cout<<"string:";
	cin>>x>>y;
	swap(&x,&y);
	cout<<"after swap: "<<x<<" "<<y;
	return 0;
}
