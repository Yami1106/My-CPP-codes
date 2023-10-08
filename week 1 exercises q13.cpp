#include<iostream>
#include<string>
using namespace std;
int main(){
	char month[20];
	cout<<"Enter the first letter of the month in uppercase"<<endl;
	gets(month);
	if(strcmp(month,"January")==0||strcmp(month,"March")==0||strcmp(month,"May")==0||strcmp(month,"July")==0||strcmp(month,"August")==0||strcmp(month,"October")==0||strcmp(month,"December")==0){
		cout<<"31 Days"<<endl;	
	}	
	else if(strcmp(month,"February")==0){
		cout<<"28/29 Days"<<endl;
	}
	else if(strcmp(month,"April")==0||strcmp(month,"June")==0||strcmp(month,"September")==0||strcmp(month,"November")==0){
		cout<<"30 Days"<<endl;
	}
	else{
		cout<<"Month does not exist"<<endl;
	}
	return 0;
}