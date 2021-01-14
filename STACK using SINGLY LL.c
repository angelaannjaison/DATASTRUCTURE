#include<stdio.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node *next;
};

struct node *newnode;
struct node *top=NULL;
int size;
void push();
void pop(); 
void display();
void search();

int main()
{
	int choice;
	printf("\nEnter the size of stack = ");
	scanf("%d",&size);
	printf("\nIMPLEMENTION OF STACK OPERATIONS USING ARRAY\n \n 1.PUSH\t 2.POP\t 3.DISPLAY\t 4.SEARCH\t \n");
	do
	{
		printf("\nEnter a choice : ");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:push();break;
			case 2:pop();break;
			case 3:display();break;
			case 4:search();break;
			case 5:printf("\n************Exit************\n");break;
			default:printf("\nInvalid choice!Try again\n");
		}
	}
	while(choice!=5);
	return 0;
}

void push()
{
	newnode=(struct node *)malloc(sizeof(struct node)); 
	printf("\nEnter the data to be pushed : ");
	scanf("%d",&newnode->data);
	newnode->next=top;
	top=newnode;//top points to the node 
}


void pop()
{
	struct node *temp;
	temp=top;
	if(top==NULL)
	{
		printf("\n*************underflow**********\n");
	}
	else
	{
		printf("\n The poped data is %d",top->data);
		top=top->next;
		free(temp);
	}
}

	
void display()
{
	struct node *temp;
	if(top==NULL)
	{
		printf("\n*********UNDERFLOW**********\n");
	}
	else
	{
		temp=top;
		for(temp=top;temp!=NULL;temp=temp->next)
		{
			printf("data=%d\t",temp->data);
		}
	}
}

void search()
{
	int val,found=0;
	struct node *temp;
	temp=top;
	printf("\nEnter the value to be searched : ");
	scanf("%d",&val);
    if(top==NULL)
	{
	    printf("\n***********UNDERFLOW************\n");
		return;
	}
	
	else
	{
		for(temp=top;temp->next!=NULL;temp=temp->next)
		{
			if(temp->data==val)
			{
				printf("\nThe data %d is found in the stack!!\n",val);
			    found=1;    
			}
		
		}
		if(temp->data==val)
		{
			printf("\nThe data %d is found in the stack!!\n",val);
			found=1;
		}
		if(found==0)
		{
			printf("\n The data %d is not found in the stack\n",val);
		}
			
	}

}

