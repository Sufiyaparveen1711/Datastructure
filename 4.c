//C program for insertion of a node after given location of single linked list.
#include<stdio.h>
#include<stdlib.h>

void create();
void display();
void inst_loc();

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
    inst_loc();
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

void inst_loc()
{
    struct node *tmp,*ptr;
    int item,pos,i;
    tmp=(struct node*)malloc(sizeof(struct node));
    if(tmp==NULL)
    {
        printf("Memory overflow.");
        exit(0);
    }
    printf("\nEnter info value u want to insert::");
    scanf("%d",&item);
    printf("\nEnter the position after which u want to insert the node::");
    scanf("%d",&pos);
    tmp->info=item;
    ptr=start;
    for(i=1;i<pos;i++)
    {
        if(ptr==NULL)
        {
            printf("Enter correct location");
            exit(0);
        }
        ptr=ptr->link;
    }
    tmp->link=ptr->link;
    ptr->link=tmp;
    printf("After insertion::\n");

}
