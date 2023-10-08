#include<iostream>
using namespace std;

int main(){
	char str[1000];
	cout<<"Enter word :"<<endl;
	gets(str);
	int n= strlen(str);
	cout<<"The reversed word is :"<<endl;
	for(int i=n;i>=0;i--){
		cout<<str[i];
	}
	return 0;
}