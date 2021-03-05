 
   #include<stdio.h>
int arr[20][20],queue[20],visited[20],n,i,j,f=0,r=-1;

void bfs(int v)
{
	for(i=0;i<n;i++)
	{
		if(arr[v][i] && !visited[i])//here v=sourse node and i=adjecent nodes
		queue[++r]=i;//enqueue
	}
	if(f<=r)
	{
		visited[queue[f]]=1;//dequeue
		bfs(queue[f++]);//recursion
	 } 
}

void main()
{
	int v;
	printf("\n Enter the number of vertices: ");  //formation of vertex
	scanf("%d",&n);
	
	for(i=1;i<=n;i++)//initialize queue and visited array
	{
		queue[i]=0;
		visited[i]=0;
	}
	
	printf("\n Enter graph data in matrix form:\n");//formation of edge
	for(i=1;i<n;i++)
	{
		for (j=1;j<n;j++)
		{
			scanf("%d",&arr[i][j]);
		}
		
	}
	printf("\n Enter the starting vertex:");
	scanf("%d",&v);
	bfs(v);
	printf("\n The node which are reachable are:\n");	
	for(i=1;i<=n;i++)
	{
		if(visited[i])
		{
			printf("%d\t",i);
		}
	
	}

}


