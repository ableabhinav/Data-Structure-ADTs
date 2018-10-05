#include<stdio.h>
#include<stdlib.h>
typedef struct NODE
{
    void* data;
    struct NODE* link;
}Node;
typedef struct HEAD
{
    int counter;
    Node* top;
}head;
void initialise(head* h)
{
    h->counter=0;
    h->top==NULL;
}
Node* createNode(void* value)
{
    Node* temp=(Node* )malloc(sizeof(Node));
    temp->data=value;
    temp->link=NULL;
    return temp;
}
//PUSH
void stackPush(head* h,void* item)
{
   Node* temp=createNode(item);
   if(h->top==NULL)
   {
    h->top=temp;
    h->counter++;
    return;
   }
   temp->link=h->top;
   h->top=temp;
   h->counter++;
   return ;
}
//pop
void stackPop(head* h)
{
    if(h->top==NULL)
    {
        printf("Stack UnderFlow!!!\n");
        return;
    }
    Node* temp=h->top;
    h->top=temp->link;
    free(temp);
    h->counter--;
    return ;
}
//destroy
void stackDestroy(head* h)
{
    if(h->top==NULL)
    {
        return;
    }
    Node* temp=h->top;
    h->top=temp->link;
    free(temp);
    h->counter--;
    return stackDestroy(h);
}
//display
/*void display(head* h)
{
     if(h->top==NULL)
     {
        printf("Stack is Empty!!!\n");
        return ;
     }
     Node* temp=h->top;
     while(temp!=NULL)
     {
        printf("%c\n",temp->data);
        temp=temp->link;
     }
     return;
}*/
void* stackTop(head* h)
{
    if(h->top==NULL)
    {
        return '\0';
    }
    void* d=h->top->data;
    return d;
}
int count(head* h)
{
    return h->counter;
}
/*
void menu()
{
    int choice;
    head h;
    initialise(&h);
    void* d;int t;
     do
       {    
            printf("\n1.Push into Stack.\n2.Pop from the stack.\n3.Stack Top Element.\n4.Display.\n5.Destroy Stack.\n6.Stack Count \n7.Exit");
            scanf("%d",&choice);
            switch(choice)
            {
                case 1:
                    printf("Enter the element\n");
                    scanf(" %c",&d);
                    stackPush(&h,d);
                    break;
                case 2:
                    
                    stackPop(&h);
                    printf("Top element is popped...\n");
                    break;
                case 3:
     
                    t=stackTop(&h);
                    if(t=='\0')
                        break;
                    printf("%c is the top element...\n",t);
                    break;
                case 4:
                    display(&h);
                    break;
                case 5:
                    stackDestroy(&h);
                    printf("The stack has been destroyed...\n");
                    break;
                case 6:
                    t=count(&h);
                    if(t==0)
                    {
                        printf("The stack is Empty!!!\n");
                        break;
                    }
                    printf("The stack has %d elements...\n",t);
                    break;
                    
             }
        }while(choice<=6);
      return 0;
}
*/
















