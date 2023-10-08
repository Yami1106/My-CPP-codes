#include <iostream>
using namespace std;

int main() {
    int a,b,option;
    cin>>a>>b;
    cin>>option;
    switch(option){
        case 1: cout<<"SUM is : "<<(a+b);break;
        case 2: cout<<"DIFF is : "<<(a-b);break;
        case 3: cout<<"PRODUCT is : "<<(a*b);break;
        case 4: cout<<"QUOTIENT is : "<<(a/b);break;
        case 5 : cout<<"MOD is : "<<(a%b);break;
    }
    return 0;
}
