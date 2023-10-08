#include<iostream>
using namespace std;
class Node{
    public :
    int data;
    Node* next;
    Node(int data){
    	this->data=data;
        this->next=nullptr;
    }
    friend ostream& operator<<(ostream* out,Node& n);
    //void create_list(int data);
};
/*void Node::create_list(int data){
    Node* head;
    head=new Node(data);
    head->data=data;
}*/
class list{
    public:
    Node* head;
    list(){
        head=nullptr;
    }
    void insert(int a);
    void print();
};
void list::insert(int a){
    Node* new_node=new Node(a);
    if(head==nullptr){
        head=new_node;
        return;
    }
    Node* temp=head;
    while(temp->next!=nullptr){
        temp=temp->next;
    }
    temp->next=new_node;
}
void list::print(){
    Node* temp=head;
    if(head=nullptr){
        cout<<"List is empty";
    }
    while(temp->next!=nullptr){
        cout<<temp->data<<"->";
        temp=temp->next;
    }
}
ostream& operator<<(ostream& out,Node& n){
	out<<n<<"->";
	return out;
}
int main(){
	Node n1=6;
    list l;
    l.insert(2);
    l.insert(3);
    l.insert(9);
    l.print();
    cout<<endl;
    cout<<n1;
    return 0;
}//still have to correct the code ????

