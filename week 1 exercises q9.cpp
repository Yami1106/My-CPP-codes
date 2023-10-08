#include<iostream>
using namespace std;

int main(){
	int m,n,i,j;
	cin>>m>>n;
	int arr[m][n];
	for(i=0;i<m;i++){
		for(j=0;j<n;j++){
			arr[i][j]=i*j;
		}	
	}
	for(i=0;i<m;i++){
		for(j=0;j<n;j++){
			cout<<arr[i][j]<<" ";
	}
	cout<<"\n";
}
	return 0;
} 