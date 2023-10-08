#include<iostream>

int main(){
	int i;
	for(i=1000;i<=2000;i++){
		if((i%8==0)&&(i%5==0)){
			std::cout<<i<<std::endl;
		}
	}
	return 0;
}