#include<stdio.h>
int stack[100],top=-1,size,i,x,choice;
void push();
void pop();
void display();

int main()
{
	printf("enter the size of the stack : ");
	scanf("%d",&size);
	printf("\n\tIMPLIMENTATION OF STACK OPERATIONS USING ARRAY");
	printf("\n\t 1.PUSH \t 2.POP\t 3.DISPLAY\t 4.EXIT\n");
	do
	{
		printf("\nenter a choice : ");
		scanf("%d",&choice);
		switch (choice)
		{
			case 1:
				{
					push();
					break;
				}
				case 2 :
					{
						pop();
						break;
					}
					case 3:
						{
							display();
							break;
						}
						case 4:
							{
								printf("\n\tEXIT ");
								break;
							}
							default:
								{
									printf("\n\t please enter a valid choice(1/2/3/4)");
								}
								
								
			
		}
	
		
	}
		while(choice != 4);
		return 0;
}
void push()
	{
		if(top>=size-1)
		{
			printf("\nstack is over flow\n");
		}
		else
		{
			printf("enter a value to be pushed :");
			scanf("%d",&x);
			top++;
			stack[top]=x;
		}
	}
	
	void pop()
	{
		if(top<=-1)
		{
			printf("\n\tstack is under flow\n");
		}
		else
		{
			printf("The poped element is %d",stack[top]);
			top--;
			
		}
	}
	void display()
	{
		if(top>=0)
		{
			printf("elements in stack are\n");
			for(i=top;i>=0;i--)
			{
				printf("\n%d",stack[i]);
			}
		
		}
		else
		{
			printf("\n The stack is empty");
		}
	}
	
