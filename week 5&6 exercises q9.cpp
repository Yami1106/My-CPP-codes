#include<iostream>
using namespace std;
class palindrome{
	public :
	int n,temp;
		void getin(){
			cin>>n;
		}
		palindrome operator /(palindrome s){
			palindrome k;
			k.n=n/10;
			return k;
		}
		palindrome operator %(palindrome s){
			palindrome k;
			k.n=n%10;
			return k;
		}
};
int main(){
	palindrome p;
	p.getin();
	int temp=p.n,r,sum;    
	while(p.n>0)
	{
	r=p.n%10;
	sum=(sum*10)+r;
	 p.n=p.n/10;
	  }
	  if(temp==sum)    
	   cout<<"Number is Palindrome.";    
	    else
		 cout<<"Number is not Palindrome."; 
		 return 0;
}