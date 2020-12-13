#include <stdio.h>
int queue[50],size,i,choice,item;
void enqueue();
void dequeue();
void display();
int front=-1;
int rear=-1;


int main()
{
	printf("\nEnter size of an array : ");
	scanf("%d",&size);
	printf("\nIMPLEMENTATION OF QUEUE USING ARRAY\n");
	printf("\n1.ENQUEUE \t2.DEQUEUE \t3.DISPLAY \t4.EXIT\n");
	do
	{
		printf("\nEnter a choice : ");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:
				{
					enqueue();
					break;
				}
				case 2:
					{
						dequeue();
						break;
					}
					case 3:
						{
							display();
							break;
						}
						case 4:
							{
								printf("EXIT\n");
								break;
							}
							default:
								{
									printf("\nplease enter a valid choice 1/2/3/4\n");
								}
					
						
		}
	}
	while(choice != 4 );
	return 0;
}

void enqueue()
{
	if(rear==size-1)
	{
		printf("\nQueue is overflow\n");
	}
	else
	{
		printf("\nEnter an item :");
		scanf("%d",&item);
		front=0;
		rear++;
		queue[rear]=item;
	}
}

void dequeue()
{
	if(front==-1 || front>rear)
	{
		printf("\nQueue is underflow\n");
	}
	else
	{
		printf("\nThe element deleted from queue is %d\n",queue[front]);
		front++;
	}
}

void display()
{
	if(front==-1&&rear==-1)
	{
		printf("\nThe queue is empty\n");
	}
	else
	{
		printf("\nThe resultant queue is...\n");
		for(i=front;i<=rear;i++)
		{
			printf("%d\n",queue[i]);
		}
	}
}
