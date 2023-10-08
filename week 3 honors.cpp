#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#define MAX_SIZE 200
//define the list 
typedef struct list{
    int data;
    struct list *next;
    struct list *prev;
}list;
//method to create a list
list *create_list(int d){
	list *head= (list *)malloc(sizeof(list));
    head->data=d;
    head->next=NULL;
    head->prev=NULL;
    return head;
}
//adds a node at the begining of the list
list *add_front(int d,list *x){
    list *head=create_list(d);
    head->next=x;
    x->prev=head;
    return head;
}
//method takes array as a parameter and converts it to a list
list *arr_to_list(int d[],int size){
    list *head=create_list(d[0]);
    for(int i=1;i<size;i++){
        head->next=add_front(d[i],head);
    }
    return head;
}
//method to print the elements of the list
void print_list(list *h){
    int i=0;
    while(h!=NULL){
        if(i!=MAX_SIZE-1){
        printf("%d, ",h->data);
        }
        else{
            printf("%d",h->data);
        }
        if(i%10==9){
            printf("\n");
        }
        h=h->next;
        i++;
    }
}
//method to swap nodes fo sort algo
void swap(list *x1,list *x2){
    int temp=x1->data;
    x1->data=x2->data;
    x2->data=temp;
}
//using bubble sort algo
void sort(list *h){
    int i,j;
    list *x1,*x2;
    for(i=MAX_SIZE;i>=0;i--){
        x1=h;
        x2=x1->next;
        for(j=0;j<=i;j++){
            if(x1->data>x2->data){
                swap(x1,x2);
            }
            x1=x2;
            x2=x2->next;
        }
    }
}
//method to remove a node from the list
void remove(list *k){
    if(k!=NULL){
        //if it is the only node in the list
        if(k->next==NULL && k->prev==NULL){
            k=NULL;
    }
    //if it is the head
    else if(k->prev==NULL){
        list *temp=k->next;
        k->next=NULL;
        temp->prev=NULL;
    }
    //if it is the last node
    else if(k->next==NULL){
        list *temp=k->prev;
        k->prev=NULL;
        temp->next=NULL;
    }
    else{
        list *temp_next=k->next;
        list *temp_prev=k->prev;
        k->next=NULL;
        k->prev=NULL;
        temp_next->prev=temp_prev;
        temp_prev->next=temp_next;
    }
    }
}
void remove_copies(list *h){
    while(h->next!=NULL){
        //remove the node if data is equal
        if(h->data==h->next->data){
            remove(h->next);
        }
        else{
            h=h->next;
        }

    }
}

int main(){
    //start list with random number between 0 and 49
    list *h=create_list(rand()%49);
    int i=0;
    for(;i<MAX_SIZE-1;i++){
        h=add_front(rand()%49,h);
    }
    printf("Initial list:");
    print_list(h);
    sort(h);
    printf("\nSorted list:");
    print_list(h);
    remove_copies(h);
    printf("\nList after removing copies:");
    print_list(h);
    return 0;
}