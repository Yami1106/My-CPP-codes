#include<iostream>
using namespace std;

int main(){
	char str[1000];
	gets(str);
	int i,n=strlen(str),letter=0,digit=0;
	for(i=1;i<=n;i++){
		if(isdigit(str[i])){
			digit++;
		}
		else if(str[i]==' '){}
		else{
			letter++;
		}
	}
	cout<<"Letters : "<<letter<<endl;
	cout<<"Digits : "<<digit;
	return 0;
}