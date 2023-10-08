#include<iostream>
using namespace std;
class node{
    public:
    int data;
    node* next;
    node(){
    	data=0;
	}
    node(int data){
        this->data=data;
        this->next=nullptr;
    }
};
class list{
    public:
    node* head= new node();
    void insert_at_front(int x,node** head);
};
//method to create a single element list
void list::insert_at_front(int x,node** head){
    node* new_node= new node;
    new_node->data=x;
    (*head)=new_node;
}
// method to insert elements in fornt of created list
/*void node::insertf(int x,node** head){
    node* newnodef=new node;
    newnodef->data=x;
    newnodef->next=*head;
    (*head)=newnodef
}*/
int main(){
	node* head;
    list l;
    l.insert_at_front(5,&head);
    l.insert_at_front(3,&head);
}
