#include<stdio.h>
#include<stdlib.h>
typedef struct NODE 
{
    void *data;
    struct NODE* link;
}Node;
typedef struct HEAD
{
    int counter;
    Node* rear;
    Node* front;
}head;
void createQueue(head* h)
{
    h->counter=0;
    h->rear=NULL;
    h->front=NULL;
    return ;
}
Node* createNode(void *value)
{
    Node* temp=(Node* )malloc(sizeof(int));
    temp->link=NULL;
    temp->data=value;
    return temp;
}
void enqueue(head* h,void *item)
{
    Node* temp=createNode(item);
    if(h->front==NULL)
    {
        h->front=temp;
        h->rear=temp;
        h->counter++;
        return ;
    }
    h->rear->link=temp;
    h->rear=temp;
    h->counter++;
    return ;
}
void dequeue(head* h)
{
    if(h->front==NULL)
    {
        printf("The queue is empty!!!\n");
        return ;   
    }
    void *x;
    Node* temp=h->front;
    h->front=temp-> link;
    if(h->counter==1)
    {
        h->rear=NULL;
        h->front=temp->link;
        x=temp->data;
        free(temp);
        h->counter--;
        return ;
    }
    x=temp->data;
    free(temp);
    h->counter--;    
    return ;
}
void display(head* h,void (*fptr)(void* ))
{
     if(h->front==NULL)
     {
        printf("Queue is Empty!!!\n");
        return ;
     }
     printf("count: %d\n",h->counter);
     Node* temp=h->front;
     while(temp!=NULL)
     {
       (*fptr)(temp->data);
        temp=temp->link;
     }
     printf("X\n");
     return;
}

void printInt(void* n)
{
    printf("%d-",*(int *)n);
}
void printFloat(void* n)
{
    printf("%f-",*(float *)n);
}
void printChar(void* n)
{
    printf("%c-",*(char *)n);
}
void printDouble(void* n)
{
    printf("%lf-",*(double *)n);
}
/*int main()
{	
	head h;
	createQueue(&h);
	int* data;
	int i;
	int choice;
	do
	{
		printf("1.Enqueue\n2.Dequeue\n3.Display\n");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:
				printf("Enter the data: ");
				data=(int *)malloc(sizeof(int));
				scanf("%d",data);
				enqueue(&h,data);
				break;
			case 2:
				dequeue(&h);
				break;
			case 3:
				display(&h,printInt);
				break;
		}
	}while(choice<=3);
	return 0;
}*/
