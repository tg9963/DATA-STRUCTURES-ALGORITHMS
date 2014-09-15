#include<iostream>
#include<limits>
#define V 9
using namespace std;

int min_dist_index(int dist[],bool set[])
{
	int min=INT_MAX,min_index;
	for(int i=0;i<V;i++)
	{
		if(set[i]==false && dist[i]<min)
		{  
			min=dist[i];
			min_index=i;
		}
	}
	return min_index;
}

void print_dist(int dist[V])
{
	for(int i=0;i<V;i++)
		cout<<i<<"  "<<dist[i]<<endl;
}

void dijkstra(int graph[V][V])
{
	int dist[V];
	bool set[V];
	
	for(int i=0;i<V;i++)
	{
		dist[i]=INT_MAX;
		set[i]=false;
	}
	
	dist[0]=0;
	for(int i=0;i<V-1;i++)
	{
		int m=min_dist_index(dist,set);
		set[m]=true;
		
		for(int n=0;n<V;n++)
		{
			if(!set[n] && graph[m][n] && dist[m]!=INT_MAX && (dist[m]+graph[m][n]<dist[n]) )
				dist[n]=dist[m]+graph[m][n];
		}
	}
	print_dist(dist);
}

int main()
{
	int graph[V][V]={{0, 4, 0, 0, 0, 0, 0, 8, 0},
                      {4, 0, 8, 0, 0, 0, 0, 11, 0},
                      {0, 8, 0, 7, 0, 4, 0, 0, 2},
                      {0, 0, 7, 0, 9, 14, 0, 0, 0},
                      {0, 0, 0, 9, 0, 10, 0, 0, 0},
                      {0, 0, 4, 0, 10, 0, 2, 0, 0},
                      {0, 0, 0, 14, 0, 2, 0, 1, 6},
                      {8, 11, 0, 0, 0, 0, 1, 0, 7},
                      {0, 0, 2, 0, 0, 0, 6, 7, 0}
                     };
    dijkstra(graph);
	return 0;
}
