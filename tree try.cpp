#include<bits/stdc++.h>
using namespace std;
struct Node{
	Node* left;
	int data;
	Node* right;
};
struct Node* newnode(int val){
	Node* node=new Node;
	node->data=val;
	node->left=NULL;
	node->right=NULL;
};
struct Node* insert(Node* root,int val){
	Node* node=newnode(val);
	if(root==NULL){
		root=node;
	}
	else if(node->data>root->data){
		root->right=node;
	}
	else{
		root->left=node;
	}
	return root;
};
Node* createtree(int arr[],int n){
	Node* root=NULL;
	for(int i=0;i<n;i++){
		root=insert(root,arr[i]);
	}
	return root;
};

int main(){
	int ar[]={45,32,56,12,67,44,50,33,99};
	int n = sizeof(ar) / sizeof(ar[0]);
	Node* root = createtree(ar, n);
	if(root->left!=NULL){
		cout<<root->data<<endl;
	}
	else{
		cout<<root->data;
	}
	return 0;
}