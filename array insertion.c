#include <stdio.h>
void main()
{
	int a[50],size,i,pos,value;
	printf("enter the size of array = ");
	scanf("%d",&size);
	if(size<=0||size>50)
	{
		printf("invalid array");
	}
	else
	{
		printf("enter %d number of elements in the array\n",size);
		for(i=0;i<size;i++)
		{
			scanf("%d",&a[i]);
		}
		printf("enter the value of new element = ");
		scanf("%d",&value);
		printf("enter the position of new element to be inserted = ");
		scanf("%d",&pos);
		if(pos<=0 || pos>size+1)
		{
			printf("invalid position");
		}
		else
		{
			for(i=size-1;i>=pos-1;i--)
			{
				a[i+1]=a[i];
			}
			
			a[pos-1]=value;
		    size++;
		    printf("the resultant array is\n");
			for(i=0;i<size;i++)
		  {
			printf("%d\n",a[i]);
	      }
		}
		
	}
	
}
