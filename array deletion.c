#include <stdio.h>
void main()
{
	int arr[50],i,size,pos;
	printf("enter the size of the array = ");
	scanf("%d",&size);
	if(size<=0||size>50)
	{
		printf("invalid size! try again");
	}
	else 
	{
		printf("enter %d number of elements in an array\n",size);
		for(i=0;i<size;i++)
		{
			scanf("%d",&arr[i]);
		}
		printf("enter the position of element to be deleted = ");
		scanf("%d",&pos);
		if(pos<=0 || pos>size+1)
		{
			printf("invalid position");
		}
		else
		{
			for(i=pos-1;i<size-1;i++)
			{
				arr[i]=arr[i+1];
			}
			size--;
			printf("resultant array is\n");
			for(i=0;i<size;i++)
			{
				printf("%d\n",arr[i]);
			}
		
		}
	}
	
	
}
