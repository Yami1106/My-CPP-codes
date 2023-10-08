#include<iostream>
using namespace std;
class Calc{
	int n,i,sum=0;
	public :
		void mult9(){
			for(i=100;i<200;i++){
				if(i%9==0){
					cout<<i<<" ";
					sum+=i;
				}
			}
			cout<<"\n";
			cout<<"Sum is : "<<sum<<endl;
		}
		Calc(){
			mult9();
		}
		~Calc(){
			cout<<"destructor invoked"<<endl;
		}
};
int main(){
	Calc obj;
	return 0;
}


