#include<iostream>
#include<string>
#include<cstring>>
using namespace std;
class func{
	char s[100];
	int n,i;
	public :
		void get_str(){
			cin>>s;
		}
		void print_str(){
			n=strlen(s);
			for(i=0;i<=n;i++)
			putchar(toupper(s[i]));
			cout<<"\n";
			for(i=0;i<=n;i++)
			putchar(tolower(s[i]));
		}
	
};
int main(){
	func word;
	word.get_str();
	word.print_str();
	return 0;
}