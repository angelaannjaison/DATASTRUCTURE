#include <stdio.h>
int cqueue[50],n,choice,front=-1,rear=-1,item;
void enqueue();
void dequeue();
void search();
void display();

void main()
{
	printf("\nenter the size of cqueue= ");
	scanf("%d",&n);
	printf("\nIMPLEMENTATION OF CIRCULR QUEUE OPERATION USING ARRAY\n");
	printf("\n1.enqueue\t 2.dequeue\t 3.search\t 4.display\t 5.exit\n");

	do
	{	
	printf("\nenter a choice= ");
	scanf("%d",&choice);
	switch(choice)
	{
		case 1:
			enqueue();
			break;
			
		case 2:
			dequeue();
			break;
			
		case 3:
			search();
			break;
			
		case 4:
			display();
			break;
		
		case 5:
			printf("\n**************exit***********\n");
			break;
			
		default:
			printf("\nenter a valid choice\n");
			
			
			
	}
		
	}while(choice!=5);
	return;
}

void enqueue()
{
	if((rear+1)%n==front || (front==0 && rear==(n-1)))
	{
		printf("\n****************** QUEUE OVERFLOW******************\n");
	}
	else
	{
		printf("\nenter the element to be enqueued= ");
		scanf("%d",&item);
		if(rear==-1&&front==-1)
		{
			front=rear=0;
			cqueue[rear]=item;//delete garbage value
		}
		else
		{
			rear=(rear+1)%n;
		    cqueue[rear]=item;
		}
	}
}

void dequeue()
{
	if(front==-1&&rear==-1)
	printf("\n**************CIRCULAR QUEUE UNDERFLOW**************\n");
	
	else if(front==rear)
	{
		printf("\nThe element dequeued is %d\n",cqueue[front]);
		front=rear=-1;
	    
	}
	
	else
	{
		printf("\nThe element dequeued is %d\n",cqueue[front]);
		front=(front+1)%n;
		
	}
}

void search()
{
	int found=0,x,i;
	printf("\nenter the element to be searched=");
	scanf("%d",&x);
	
	if(front!=-1)
	{
		for(i=front ; i!=rear; i=(i+1)%n)
		{
			if(cqueue[i]==x)
		   {  
			  printf("\n%d is found at index %d\n",cqueue[i],i);
			  found=1;
		   }
		}
		
		if(cqueue[i]==x)//to compare the last value where rear points
		{
			printf("\n%d is found at index %d\n",cqueue[i],i);
	        found=1;
		}   
	
		    
		if(found==0)
		{
			printf("\nthe element is not found\n");
		}
	
		
		
	}
	else
	{
		printf("\n************THE CIRCULAR QUEUE IS EMPTY*************\n");
	}

}
 
void display()
{
	int i;
	if(front!=-1)
	{
		for(i=front; i!=rear; i=(i+1)%n)
		printf("%d\t",cqueue[i]);
	printf("%d",cqueue[i]);   //to display the last element in cq where rear points	
		
	}
	else
	printf("\n***********CIRCULAR QUEUE IS EMPTY*********\n");
}

