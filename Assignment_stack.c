#include<stdio.h>
#include<stdlib.h>
typedef struct Node node;

struct Node
{
    int data;
    node *next;
};
node *top ;
void push();
void pop();
void display();
void clear();
void Is_empty();


int main()
{
    int key;

    while(1)
    {
        printf("##Select Stack Operation##\n\n");
        printf("\n0.Exit operation");
        printf("\n1.Push");
        printf("\n2.Pop");
        printf("\n3.Display");
        printf("\n4.Check for empty");
        printf("\n5.Clear Stack\n\n");
        printf("Enter your choise :");
        scanf("%d",&key);
      if(key==1)
    {
      push();

    }
    else if(key==2)
    {
         pop();
    }
    else if(key==3)
    {
         display();
    }
    else if(key==0)
    {
        exit(0);
    }
    else if(key==4)
    {
        Is_empty();
    }
    else if(key==5)
    {
        clear();
    }
    else
        printf("Wrong Inpur\n");

    }

    return 0;
}

void pop()
{
    if(top==NULL)
    {
        printf("stack is empty\n");
        return;
    }
    else
    {
        node *temp=top;
        top=top->next;
        temp->next=NULL;
        free(temp);
        return;


    }
}

void display()
{
    if(top==NULL)
    {
        printf("Stack is empty\n");
        return;
    }
    else
    {
        node *temp=top;
        printf("Stack is: ");
        while(temp!=NULL)
        {
            printf("\n%d\n",temp->data);
            temp=temp->next;
        }
    }
    return;
}
void push()
{
    node *temp;
    temp= (node *)malloc(sizeof(node));
    printf("\nEnter value for push :");
    scanf("%d",&temp->data);
    if(top==NULL)
    {
        top=temp;
        temp->next=NULL;
        return;
    }
    else
    {

        temp->next=top;
        top=temp;
    }
    return;
}
void Is_empty()
{
    if(top==NULL)
    {
        printf("True\n");
    }
    else
    {
        printf("False\n");
    }
    return ;
}
void clear()
{
    if(top=NULL);
       {
          return;
       }

        node *temp=top,*prev;
        while(temp!=NULL)
        {
            prev=temp;
            temp=temp->next;
            free(temp);
        }


}
