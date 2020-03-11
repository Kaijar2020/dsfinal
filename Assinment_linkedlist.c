#include<stdio.h>
#include<stdlib.h>
typedef struct Node node;
struct Node
{
    int data;
    node *next;
};
node *head;
void inser_last();
void inser_first();
void inser_in_position();
void delete_last();
void delete_first();
void delete_in_position(int pos);
void display();
void clear();


int main()
{
    int ch;
    while(1)
    {
        printf("\nSelect Linked List operation :\n\n");
        printf("1.Inser in last\n");
        printf("2.Inser in first\n");
        printf("3.Inser in n position\n");
        printf("4.Delete in last\n");
        printf("5.Delete in first\n");
        printf("6.Delete in  n position\n");
        printf("7.Delete specific list\n");
        printf("8.Display list\n");
        printf("9.Clear list\n");
        printf("10.End the operation\n\n");
       printf("\nEnter your choise:");
       scanf("%d",&ch);
       if (ch==1)
       {
           inser_last();

       }
       else if(ch==2)
       {
           inser_first();
       }
     else  if(ch==3)
     {    int list,n;
            printf("Enter value for insert and position : ");
          scanf("%d%d",&list,&n);
          inser_in_position(list,n);
       }
       else if(ch==4)
       {
           delete_last();
       }
        else  if(ch==5)
      {
           delete_first();
         }
       else if(ch==6)
       {
           int x;
           printf("\nEnter position for delete :");
           scanf("%d",&x);
           delete_in_position(x);

       }

       else if(ch==7)
       {
           int x;
           printf("\nEnter value for delete :");
           scanf("%d",&x);
           delete_specific_value(x);

       }
       else if(ch==8)
       {
           display();
       }
      else  if(ch==9)
       {
           clear();
       }
       else if(ch==10)
       {
           exit(0);
       }
       else
       {
           printf("Wrong Input.Try Again!!\n");
       }

    }

    return 0;
}
void display()
{
    printf("List is ");
    if(head==NULL)
    {
        printf("empty\n");
    }
    node *temp=head;

    while(temp!=NULL)
    {
        printf("%d ",temp->data);
        temp=temp->next;

    }
}
void inser_first()
{
    node *temp;

        temp=(node *)malloc(sizeof( node));
        if(temp==NULL)
        {
                printf("\nOut of Memory Space\n");
                return;
        }
        printf("\nTake element for Insert in first : " );
        scanf("%d",&temp->data);
        temp->next =NULL;
        if(head==NULL)
        {
                head=temp;
        }
        else
        {
                temp->next=head;
                head=temp;
        }
}

void inser_last()
{
    node *temp;
    temp=(node *)malloc(sizeof(node));
    printf("Enter node data: ");
    scanf("%d",&temp->data);
    temp->next=NULL;
    if(head==NULL)
    {
        head=temp;
    }
    else
    {
        node *list=head;
        while(list->next!=NULL)
        {
            list=list->next;
        }
        list->next=temp;
    }
}
void inser_in_position(int value,int pos)
{
    int i;

    node* temp1  = (node*) malloc(sizeof( node));
    temp1->data = value;
    temp1->next = NULL;
    if(pos == 1)
    {
        temp1->next = head;
        head = temp1;
        return;
    }
    node* temp2 = head;
    for(i=0;i<pos-2;i++)
    {
        temp2 = temp2->next;
    }

    temp1->next = temp2->next;
    temp2->next = temp1;
}
void delete_first()
{
    if(head==NULL)
    {
        printf("Under Flow\n");
        return;
    }
    node *temp=head;
    head=head->next;
    free(temp);
}
void delete_last()
{
    if(head==NULL)
    {
        printf("\nList is empty\n");
        return;
    }
    if(head->next==NULL)
    {
        free(head);
        head=NULL;
        return;
    }
    node *temp=head;
    while(temp->next->next)
    {
        temp=temp->next;
    }
    free(temp->next);
    temp->next=NULL;
}
void delete_in_position(int pos)
{
    if(head==NULL)
    {
        printf("List is empty\n");
        return ;
    }
    node *temp=head,*prev;
    int i=0;
    if(pos==1)
    {
        head=head->next;
        free(temp);
        return;
    }
    i=1;
    while(temp->next!=NULL)
    {
        prev=temp;
        temp =temp->next;
        i++;
        if(pos==i)
        {
            prev->next=temp->next;
            free(temp);
            return ;
        }
    }
    printf("Index out of range\n");
}
void delete_specific_value(int key)
{
    if(head==NULL)
    {
        printf("List is empty\n");
        return;
    }
    node *temp=head,*previous;
    if(head->data==key)
    {
        head=head->next;
        free(temp);
        return;
    }
    while(temp->data!=key)
    {
        previous=temp;
        temp=temp->next;
        if(temp==NULL)
        {
            printf("\nNOt found\n");
            return;
        }
    }
    previous->next=temp->next;
    free(temp);
}
void clear()
{

        node *temp=head;
        node *prev;
        while(temp!=NULL)
        {
            prev=temp;
            temp=temp->next;
            free(prev);
         }
        free(temp);
        head =NULL;

}

