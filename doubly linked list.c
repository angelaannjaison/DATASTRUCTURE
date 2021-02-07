#include <stdio.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node *next;
	struct node *prev;
}*head,*tail;
int size=0;
struct node *head=NULL;
struct node *tail=NULL;
void insert_begin();
void insert_end();
void insert_atpos();
void delete_begin();
void delete_end();
void delete_atpos();
void display_forward();
void display_reverse();
void search();

void main()
{
	int ch;
	printf("\n**************doubly linked list**************\n");
	printf("\n1.insert at begining\n2.insert at end\n3.insert at position\n4.delete at begining\n5.delete at end\n6.delete at position\n7.display forward\n8.display reverse\n9.search\n10.exit\n");
	do
	{
		printf("\nenter a choice:");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:
				insert_begin();
				break;
			case 2:
				insert_end();
				break;
			case 3:
				insert_atpos();
				break;
			case 4:
				delete_begin();
				break;			
			case 5:
				delete_end();
				break;
			case 6:
				delete_atpos();
				break;
			case 7:
				display_forward();
				break;
			case 8:
				display_reverse();
				break;	
			case 9:
				search();
				break;	
			case 10:
				printf("\n***************************exit*****************************\n");	
			default:
				printf("\n invalid choice,try again");				
		}
		
	}while(ch!=10);
}

void insert_begin()
{
	
	struct node *newnode;
	newnode=(struct node*)malloc(sizeof(struct node));
	printf("enter data:");
	scanf("%d",&newnode->data);
	newnode->next=NULL;
	newnode->prev=NULL;
	if(head==NULL)
	{
		head=tail=newnode;
	}
	else
	{
		tail->next=newnode;
		newnode->prev=tail;
		tail=newnode;
		
	}
	size++;
}

void insert_end()
{
	struct node *newnode;
	newnode=(struct node*)malloc(sizeof(struct node));
	printf("enter data:");
	scanf("%d",&newnode->data);
	newnode->next=NULL;
	newnode->prev=NULL;
	tail->next=newnode;
	newnode->prev=tail;
	tail=newnode;
	size++;
}

void insert_atpos()
{
	struct node *newnode,*temp;
	int i=1,pos;
	printf("\nenter the position:");
	scanf("%d",&pos);
	if(pos<1 || pos>size)
	{
		printf("\ninvalid position\n");
	}
	else if(pos==1)
	{
		insert_begin();
	}
	else if(pos==size)
	{
		insert_end();
	}
	else
	{
		newnode=(struct node*)malloc(sizeof(struct node));
		printf("enter data:");
		scanf("%d",&newnode->data);
		temp=head;
		while(i<pos-1)
		{
			temp=temp->next;
			i++;
		}
		newnode->prev=temp;
		newnode->next=temp->next;
		temp->next=newnode;
		newnode->next->prev=newnode;
			
	}
	size++;
}

void delete_begin()
{
	struct node *temp;
	temp=head;
	if(head==NULL)
	printf("\n linkedlist is empty\n");
	else
	{
		head=head->next;
		head->prev=NULL;
		free(temp);
	}
	size--;
}

void delete_end()
{
	struct node *temp;
	temp=tail;
	if(tail==NULL)
	printf("\n linked list is empty \n");
	else
	{
		tail=tail->prev;
		tail->next=NULL;
		free(temp);
	}
	size--;
}

void delete_atpos()
{
	
	int pos,i=1;
	struct node *temp;
	temp=head;
	printf("\n enter the pos=");
	scanf("%d",&pos);
	if(pos==1)
	delete_begin();
	else if(pos==size)
	delete_end;
	else
	{
		while(i<pos)
		{
			temp=temp->next;
			i++;
		}
		temp->prev->next=temp->next;
		temp->next->prev=temp->prev;
		free(temp);
	}
	size--;
	
}
void display_forward()
{
	struct node *temp;
	if(tail==NULL)
	printf("\n**********linked list is empty*********\n");
	else
	{
		for(temp=head;temp!=NULL;temp=temp->next)
		{
			printf("%d\t",temp->data);
		}
	}
}

void display_reverse()
{
	struct node *temp;
	temp=tail;
	if(head==NULL)
	printf("\n**********linked list is empty*********\n");
	else
	{
		while(temp!=NULL)
		{
			printf("%d\t",temp->data);
			temp=temp->prev;
		}
	}
}

void search()
{
	int data;
	struct node *temp;
	temp=head;
	if(head==NULL)
	printf("\n*************DOUBLY LINKED LIST IS EMPTY***************\n");
	else
	{
    printf("Enter the number you want to search:");
    scanf("%d", &data);
    temp=head;
    printf("\t\t");
    do
	{
      if(temp->data==data)
	  {
        printf("\n\t\tThe number is found in the linked list!!");
        return;
      }
      temp=temp->next;
    }while(temp != NULL);
    printf("\n\t\tThe number is not found in the linked list!!");
  }
  }
