//C program to delete a node after given location of singly linked list.
#include<stdio.h>
#include<stdlib.h>

void create();
void display();
void del_loc();

struct node
{
    int info;
    struct node *link;
};
struct node *start=NULL;

int main()
{
    create();
    display();
    del_loc();
    display();
    return 0;
}

void create()
{
    struct node *tmp,*ptr;
    int item;
    char ch='y';
    while(ch=='y'||ch=='Y')
    {
        tmp=(struct node*)malloc(sizeof(struct node));
        if(tmp==NULL)
        {
            printf("Memory overflow.");
            exit(0);
        }
        printf("Enter info value::");
        scanf("%d",&item);
        tmp->info=item;
        tmp->link=NULL;
        if(start==NULL)
            start=tmp;
        else
        {
            ptr=start;
            while(ptr->link!=NULL)
                ptr=ptr->link;
            ptr->link=tmp;
        }
        fflush(stdin);
        printf("Do u want to add more nodes::");
        scanf("%c",&ch);
    }
}

void display()
{
    struct node *ptr;
    if(start==NULL)
    {
        printf("List is empty.");
        exit(0);
    }
    else
    {
        ptr=start;
        while(ptr!=NULL)
        {
            printf("%d\t",ptr->info);
            ptr=ptr->link;
        }
    }
}

void del_loc()
{
    struct node *tmp,*prev,*ptr;
    int pos,i;
    if(start==NULL)
    {
        printf("List is empty(underflow).");
        exit(0);
    }
    printf("\nEnter the position after which u want to delete the node::");
    scanf("%d",&pos);
    if(pos<1)
    {
        printf("\nInvalid position.");
        exit(0);
    }
    prev=start;
    ptr=start->link;
    for(i=1;i<pos;i++)
    {
        prev=ptr;
        ptr=ptr->link;
        if(ptr==NULL)
        {
        printf("Invalid position.");
        exit(0);
        }
    }
    prev->link=ptr->link;
    tmp=ptr;
    printf("\nDeleted node is %d",tmp->info);
    printf("\nAfter deletion::\n");
    free(tmp);
}

