#include<iostream>
#include<time.h>

using namespace std;

int main(){
	int guess;
	srand(time(NULL));
    int randomnumber = 1+rand() % 10;
	Game:
	cout<<"Your guess is :"<<endl;
	cin>>guess;
	if(guess==randomnumber){
		cout<<"Well guessed!"<<endl;
	}
	else{
		goto Game;
	}
	return 0;
}