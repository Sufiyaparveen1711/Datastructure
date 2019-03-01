//C program to sort elements of single linked list.
#include<stdio.h>
#include<stdlib.h>

void create();
void display();
void sort();

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
    sort();
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

void sort()
{
    struct node *p1,*p2;
    int tmp;
    if(start==NULL)
    {
        printf("List is empty(underflow).");
        exit(0);
    }
   for(p1=start;p1->link!=NULL;p1=p1->link)
   {
       for(p2=p1->link;p2!=NULL;p2=p2->link)
       {
           if(p1->info>p2->info)
           {
               tmp=p1->info;
               p1->info=p2->info;
               p2->info=tmp;
           }
       }
   }
   printf("\nList after sorting::\n");
}
