#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
int dfs(int v, int n, int a[20][20], int *visited)
{
	int i;
		visited[v] = 1;
	for (i = 1; i <= n; i++)
	{
		if (a[v][i] && !visited[i])
		{
			printf("\n%d->%d\t", v, i);
			dfs(i, n, a, visited);
		}
	}
}
int bfs(int v, int n, int a[20][20], int *visited)
{
	int i, r = -1, f = 0, q[20];
	visited[v] = 1;
	q[++r] = v;
	while (f <= r)
	{
		v = q[f++];
		printf("%d", v);
		for (i = 1; i <= n; i++)
		{
			if (a[v][i] & !visited[i])
			{
				q[++r] = i;
				visited[i] = 1;
			}
		}
	}
}
void main()
{
	int a[20][20], visited[20], n, v, i, j, ch,count;
	printf("\nEnter the number of nodes:");
	scanf("%d", &n);
	printf("\nEnter graph data of matrix:");
	for (i = 1; i <= n; i++)
	{
		for (j = 1; j <= n; j++)
		{
			scanf("%d", &a[i][j]);
		}
	}
	while (1)
	{
		for (i = 1; i <= n; i++)
			visited[i] = 0;
		printf("\n1.BFS\n2.DFS\n3.Exit");
		printf("\nEnter choice:");
		scanf("%d", &ch);
		switch (ch)
		{
		case 1:printf("\nEnter the starting vertex:");
			scanf("%d",&v);
			bfs(v, n, a, visited);
			if ((v<1) || (v>n))
			{
				printf("\nBfs not possible");
			}
			else
			{
				printf("\nThe reachable nodes are:");
				for (i = 1; i <= n; i++)
				{
					if (visited[i] == 1)
					{
						printf("%d\t", i);
					}
				}
			}
			break;
		case 2:	count=dfs(1, n, a, visited);
			if (count >= (n - 1))
				printf("\nGraph is connected.");
			else
				printf("\nGraph is diconnected.");
			break;
		case 3:exit(0);
		}
	}
	getch();
}
