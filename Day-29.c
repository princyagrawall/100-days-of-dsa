#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node* next;
};

struct node* create(int n){
    struct node *head=NULL,*temp=NULL,*newnode;
    int x;
    for(int i=0;i<n;i++){
        scanf("%d",&x);
        newnode=(struct node*)malloc(sizeof(struct node));
        newnode->data=x;
        newnode->next=NULL;

        if(head==NULL){
            head=newnode;
            temp=head;
        }
        else{
            temp->next=newnode;
            temp=newnode;
        }
    }
    return head;
}

struct node* rotate(struct node* head,int n,int k){
    if(head==NULL || k==0)
        return head;

    k=k%n;

    struct node* temp=head;
    int count=1;

    while(temp->next!=NULL){
        temp=temp->next;
        count++;
    }

    temp->next=head;

    int steps=n-k;
    temp=head;

    for(int i=1;i<steps;i++)
        temp=temp->next;

    head=temp->next;
    temp->next=NULL;

    return head;
}

void display(struct node* head){
    while(head!=NULL){
        printf("%d ",head->data);
        head=head->next;
    }
}

int main(){
    int n,k;
    scanf("%d",&n);

    struct node* head=create(n);

    scanf("%d",&k);

    head=rotate(head,n,k);

    display(head);

    return 0;
}