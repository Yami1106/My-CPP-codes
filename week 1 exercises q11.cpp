#include<iostream>
#include<string>
using namespace std;
int main(){
	char password[18];
	int i,j,countdigi=0,countspec=0,countcap=0,countsm=0;
	gets(password);
	int n=strlen(password);
	if(n>=6&&n<=16){
		for(i=0;i<=n;i++){
			if(isupper(password[i])){
				countcap++;
			}
			if(islower(password[i])){
				countsm++;
			}
			if(password[i]=='$'||password[i]=='@'||password[i]=='#'){
				countspec++;
			}
			if(isdigit(password[i])){
				countdigi++;
			}
		}
			if(countcap>=1&&countsm>=1&&countdigi>=1&&countspec>=1){
			cout<<"Valid Password"<<endl; 
	}
		else{
		cout<<"Not a Valid Password"<<endl;
	}
	}
	else{
		cout<<"Not a Valid Password"<<endl;
	}
	return 0;
	
}