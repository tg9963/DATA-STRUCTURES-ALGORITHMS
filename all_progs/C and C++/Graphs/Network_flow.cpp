#include<iostream>
#include<stdlib.h>
#include<queue>
#include<limits.h>
#define M 6
#define N 6
using namespace std;

bool bfs(int rgraph[M][N],int src,int tar,int parent[])
{
	int visited[M];
	for(int i=0;i<M;i++)visited[i]=-1;
	queue<int> q;
	q.push(src);
	visited[src]=1;
	parent[src]=-1;
	int temp;
	while(!q.empty())
	{
		temp=q.front();
		q.pop();
		for(int i=0;i<M;i++)
		{
			if(rgraph[temp][i]>0 && visited[i]<=0)
			{
				q.push(i);
				visited[i]=1;
				parent[i]=temp;
			}
		}
	}
	return (visited[tar]==1);
}

int ford(int graph[M][N],int src,int tar)
{
	int rgraph[M][N];
	for(int i=0;i<M;i++)
	{
		for(int j=0;j<N;j++)
		{
			rgraph[i][j]=graph[i][j];
		}
	} 
	int parent[M];
	for(int i=0;i<M;i++)parent[i]=-1;
	int max_path_flow=0;
	int count=0;
	while(bfs(rgraph,src,tar,parent))
	{
		//cout<<"c: "<<count++<<endl;
		int path_flow=INT_MAX;
		for(int i=tar;i!=src;i=parent[i])
		{
			int j=parent[i];
			path_flow=min(path_flow,rgraph[j][i]);
		}
		for(int i=tar;i!=src;i=parent[i])
		{
			int j=parent[i];
			rgraph[j][i] -=path_flow;
			rgraph[i][j]+=path_flow;
		}	
		max_path_flow +=path_flow;
	}
	return max_path_flow;
}

int main()
{
	int graph[][N]={
						{0, 16, 13, 0, 0, 0},
                        {0, 0, 10, 12, 0, 0},
                        {0, 4, 0, 0, 14, 0},
                        {0, 0, 9, 0, 0, 20},
                        {0, 0, 0, 7, 0, 4},
                        {0, 0, 0, 0, 0, 0}
	               };
	int src=0,tar=5;
	cout<<ford(graph,src,tar);
	return 0;
}

