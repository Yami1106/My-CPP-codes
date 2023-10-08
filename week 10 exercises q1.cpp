#include<bits/stdc++.h>
using namespace std;
template <typename T,typename T1>
T bsort(T n,T1 arr[]){
	T temp=0;
	for(int i=0;i<n-1;i++){
		for(int j=i+1;j<n-i-1;j++){
			if(arr[j]>arr[j+1]){
				swap(arr[j],arr[j+1]);
		}
	}
	for(int k=0;k<n;k++){
		cout<<arr[k]<<" ";
	}
	return temp;
}
}
int main(){
	int n;
	cin>>n;
	int a[n];float ar[n];
	for(int u=0;u<n;u++){
		cin>>a[u];
	}
		for(int v=0;v<n;v++){
		cin>>ar[v];
	}
	sort(a,a+n);
	for(int k=0;k<n;k++){
		cout<<a[k]<<" ";
	}
	sort(ar,ar+n);
	cout<<"\n"
	for(int l=0;l<n;l++){
		cout<<<<ar[l]<<" ";
	}
	return 0;
}