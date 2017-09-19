
typedef struct node
{
    int data;
    struct node* next;
}NODE;
typedef struct head
{	
	NODE* head;
	NODE* rear;
	int cntr;
}HEAD;
NODE* createNode(int n)
{
	NODE* temp=(NODE* )malloc(sizeof(NODE));
	temp->data=n;
	temp->next=NULL;
	return temp;
}
void addAtBegin(HEAD** pToheadStruct,int n)
{
	NODE* temp=createNode(n); //Allocating memory for a node 
	temp->next=(*pToheadStruct)->head; //adding node before the previous node
	if((*pToheadStruct)->head==NULL)
	{
		(*pToheadStruct)->rear=temp;
	}
	(*pToheadStruct)->cnt++;
	(*pToheadStruct)->head=temp;
}
void addAtEnd(HEAD** pToheadStruct,int n)
{
	NODE* temp=createNode(n);
	if((*pToheadStruct)->head==NULL)
	{
		(*pToheadStruct)->head=temp;
		(*pToheadStruct)->rear=temp;
		(*pToheadStruct)->cnt++;
		return;
	}
	(*pToheadStruct)->rear->next=temp;
	(*pToheadStruct)->rear=temp;
	(*pToheadStruct)->cnt++;
	return;
}
void disp(struct node* head)
{
	struct node* temp;
	temp=head;
	printf("\nThe list is: ");
	while(temp!=NULL)
	{
		printf("%d ",temp->data);
		temp=temp->next;
	}

}
void insert(struct node** pHead,int n, int pos)
{
	int i;
	struct node* temp1= *pHead;
	struct node* temp=(struct node*)(malloc(sizeof(struct node)));
	(*temp).data=n;
	(*temp).next=NULL;
	if(pos==1)
	{
		temp->next=*pHead;
		*pHead=temp;
					//temp1: Previous node ; temp: New node
		return;     	
	}
	for(i=0; i<n-2;i++)		
	{
		temp1=temp1->next;	
	}
	temp->next=temp1->next;
	temp1->next=temp;

}
int main()
{
	HEAD* headStruct=(HEAD* )malloc(sizeof(HEAD));
	headStruct->head=NULL;
	headStruct->rear=NULL;
	headStruct->cnt=0;
	int n,pos,ans;
	do
	{
		printf("\nEnter the Data: ");
		scanf("%d",&n);
		addAtBegin(&headStruct,n);		
		printf("\nDo you want to continue?(1/0): ");
		scanf("%d",&ans);	
	}while(ans==1);
	disp(head);
	printf("Enter data and the position were to insert: ");
	scanf("%d %d",&n,&pos);
	insert(&head,n,pos);
	disp(head);	
	return 0;
}
