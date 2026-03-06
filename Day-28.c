#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node *next;
};

int main()
{
    int n,i;
    scanf("%d",&n);

    struct node *head=NULL,*temp=NULL,*newnode=NULL,*last=NULL;

    for(i=0;i<n;i++)
    {
        newnode=(struct node*)malloc(sizeof(struct node));
        scanf("%d",&newnode->data);
        newnode->next=NULL;

        if(head==NULL)
        {
            head=newnode;
            last=newnode;
        }
        else
        {
            last->next=newnode;
            last=newnode;
        }
    }

    last->next=head;

    temp=head;
    do
    {
        printf("%d ",temp->data);
        temp=temp->next;
    }while(temp!=head);

    return 0;
}