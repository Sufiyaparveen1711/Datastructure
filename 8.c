//C program to remove all duplicate elements from single linked list.
#include<stdio.h>
#include<stdlib.h>

void create();
void display();
void dup();

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
    dup();
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

void dup()
{
    struct node *tmp,*ptr,*prev,*ptr1;
    int data;
    if(start==NULL)
    {
        printf("List is empty(underflow).");
        exit(0);
    }
    ptr=start;
    while(ptr!=NULL)
    {
        data=ptr->info;
        prev=ptr;
        ptr1=ptr->link;
        while(ptr1!=NULL)
        {
            if(data==ptr1->info)
            {
                tmp=ptr1;
                prev->link=ptr1->link;
                ptr1=ptr1->link;
                free(tmp);
            }
            else
            {
                prev=ptr1;
                ptr1=ptr1->link;
            }
        }
        ptr=ptr->link;
    }
    printf("\nList after removal of duplicate elements::\n");
}

