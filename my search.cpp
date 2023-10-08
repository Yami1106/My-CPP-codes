#include<iostream>
using namespace std;
void swap(int& x,int& y){
    int temp;
    temp=x;
    x=y;
    y=temp;
}
void bubble_sort(int arr[],int n){
    for (int i = 0; i < n - 1; i++)
        for (int j = 0; j < n - i - 1; j++)
            if (arr[j] > arr[j + 1])
                swap(arr[j], arr[j + 1]);
}
/*void linear_search(int arr[],int size,int key){
    for(int i=0;i<10;i++){
        if(arr[i]==key){
            cout<<"element found";
        }
        else{
            cout<<"element not found"<<endl;
        }
    }
}*/
void binary_srch(int arr[],int size,int key){
    bubble_sort(arr,size);
    if(key==arr[size/2]){
        cout<<"Element found";
    }
    else{
    if(key>arr[size/2]){
        int temp[size/2];
        for(int i=size/2;i<=size;i++){
            for(int j=0;j<=size/2;j++){
                temp[j]=arr[i];
            }
        }
        binary_srch(temp,size/2,key);
    }
    if(key<arr[size/2]){
        int temp2[size/2];
        for(int i=0;i<size/2;i++){
            temp2[i]=arr[i];
        }
        binary_srch(temp2,size/2,key);
    }
    }
}
int main(){
    int n;
    cin>>n;
    int arr[n],key;
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    cin>>key;
    bubble_sort(arr,n);
    cout<<"sorted array is :"<<endl;
    for(int i=0;i<n;i++){
    	cout<<arr[i]<<" ";
	}
	cout<<endl;
    binary_srch(arr,n,key);
}