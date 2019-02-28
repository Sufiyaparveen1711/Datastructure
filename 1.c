//C program for node creation of singly linked list and its display .

#include<stdio.h>
#include<stdlib.h>

void create();
void display();

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
