#include<stdio.h>
#include<stdlib.h>
typedef struct Node node;
struct Node {
	int data;
	 node* next;
};

node* front = NULL;
node* rear = NULL;


int main(){
	int ch;
	printf("##Queue Opearation##\n\n");
	while(1)

    {
        printf("\nChose one from the below options\n");
        printf("\n1.Enqueue\n2.Dequeue\n3.Display\n4.Exit");
        printf("\nEnter your choise :");
         scanf("%d",&ch);
    if(ch==1)
    {

        Enqueue();
    }
    else if(ch==2)
    {
        Dequeue();

    }
    else if(ch==3)
    {
        Display();
    }
    else if(ch==4)
    {
        exit(0);
    }
    else
        printf("\nWrong choise\n");



    }

}

void Enqueue() {
    int x;
	node* temp =(node*)malloc(sizeof(node));

		printf("Enter value for push :");
		scanf("%d",&x);
	temp->data =x;
	temp->next = NULL;
	if(front == NULL && rear == NULL){
		front = rear = temp;
		return;
	}
	rear->next = temp;
	rear = temp;
}


void Dequeue() {
	node* temp = front;
	if(front == NULL) {
		printf("Queue is Empty\n");
		return;
	}
	if(front == rear) {
		front = rear = NULL;
	}
	else {
		front = front->next;
	}
	free(temp);
}



void Display() {
    if(front == NULL) {
		printf("\nQueue is Empty\n");
		return;}
	node* temp = front;
	while(temp != NULL) {
		printf("%d\n",temp->data);
		temp = temp->next;
	}
	printf("\n");

}
