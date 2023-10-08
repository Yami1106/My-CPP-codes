#include<iostream>
#include<string>
using namespace std;
class Comp{
	char str[100];
	public :
		void getin(){
			cin>>str;
		}
		int operator ==(Comp s){
			if(strcmp(str,s.str)==0){
				return 1;
			}
			return 0;
		}
		 int operator <(Comp s){
		 	if(strcmp(str,s.str)<0){
		 		return 1;
			 }
			 return 0;
		 }
		 int operator >(Comp s){
		 	if(strcmp(str,s.str)>0){
		 		return 1;
			 }
			 return 0;
		 }
};
int main(){
	Comp s1,s2;
	s1.getin();
	s2.getin();
	if(s1==s2){
		cout<<"Strings are equal";
	}
	else if(s1<s2){
		cout<<"First string is smaller than second";
	}
	else if(s1>s2){
		cout<<"First string is greater than the second";
	}
	return 0;
}