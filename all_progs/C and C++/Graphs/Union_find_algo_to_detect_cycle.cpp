#include<iostream>
#include<stdlib.h>
 
using namespace std;

struct edge
{
	int src,dest;
};
struct graph
{
	int v,e;
	struct edge* array;
};
struct graph* create_graph(int v,int e)
{
	struct graph* g=(struct graph*)malloc(sizeof(struct graph));
	g->v=v;
	g->e=e;
	g->array=(struct edge*)malloc(v*sizeof(struct edge));
	return g;
}
int find_set(int parent[],int src)
{
	if(parent[src]==-1)return src;
	else return find_set(parent,parent[src]);
}
void unions(int parent[],int x,int y)
{
	int x_set=find_set(parent,x);
	int y_set=find_set(parent,y);
	parent[x_set]=y_set;
}
int is_having_cycle(struct graph* g)
{
	int *parent=(int*)malloc(g->v*sizeof(int));
	for(int i=0;i<g->v;i++)
	{
		parent[i]=-1;
	}
	for(int i=0;i<g->e;i++)
	{
		int x=find_set(parent,g->array[i].src);
		int y=find_set(parent,g->array[i].dest);
		
		if(x==y)return 1;
		
		unions(parent,x,y);
	}
	return 0;
}
int main()
{
	int v=3;
	int e=2; 
	struct graph* g=create_graph(v,e);
	g->array[0].src=0;
	g->array[0].dest=1;
	g->array[1].src=1;
	g->array[1].dest=2;
	//g->array[2].src=0;
	//g->array[2].dest=2; 
//	g->array[3].src=2;
	//g->array[3].dest=3;
	
	//g->array[3].src=3;
	//g->array[3].dest=1;  
	if(is_having_cycle(g))
	{
		cout<<"Having cycle";
	}
	else
	cout<<"No cycle";
	return 0;
}
