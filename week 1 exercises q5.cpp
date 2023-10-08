#include<iostream>
using namespace std;

int main(){
	int i;
	cout<<"Enter the string :";
	char word[100];
	gets(word);
	int n=strlen(word);
	cout<<"The reversed string is : ";                  
	for(i=n;i>=0;i--){
		cout<<word[i];
	}
	return 0;
}