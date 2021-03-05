#include<stdio.h>

int G[20][20],i,j,stack[20],top=-1,visited[20],n,v;

void dfs(int v)
{
	for(i=1;i<=n;i++)
	{
		if(G[v][i] && !visited[i])
		stack[++top]=i;
	}
	if(top!=-1)
	{
		visited[stack[top]]=1;
		dfs(stack[top--]);//to find dfs recursively and pop simutaneously
	}
}
	void main()
	{
		printf("\nenter the number of vertices :");
		scanf("%d",&n);
		for(i=1;i<=n;i++)
		{
			stack[i]=0;
			visited[i]=0;
		}
		printf("\n Enter adjacency matrix of the graph:\n");
		for(i=1;i<=n;i++)
		{
			for(j=1;j<=n;j++)
			{
				scanf("%d",&G[i][j]);
			}
	    }
		printf("\n Enter the starting vertex:");
		scanf("%d",&v);
		dfs(v);
		for(i=1;i<=n;i++)
		{
			if(visited[i])
			printf("\n The node %d is reachable \n",i);
			else
			{
				printf("\n The node %d is not reachable \n",i);
			}
			
		}
    }
	
