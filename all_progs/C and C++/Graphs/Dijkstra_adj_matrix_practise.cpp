#include<iostream>
#include<stdlib.h>
#include<limits.h>
using namespace std;

struct Adjlistnode
{
	int weight;
	int dest;
	struct Adjlistnode* next;
};

struct Adjlist
{
	struct Adjlistnode *head;
};

struct Graph
{
	int v; 
	struct Adjlist* array;
};

struct Minheap_node
{
	int v;
	int dist;	
};

struct Minheap
{
	int count;
	int capacity;
	struct Minheap_node** array;
	int *pos;
};

struct Minheap_node* create_Minheap_node(int v,int dist)
{
	struct Minheap_node* node=(struct Minheap_node*)malloc(sizeof(struct Minheap_node));
	node->dist=dist;
	node->v=v;
	return node;
}


struct Minheap* create_Minheap(int capacity)
{
	struct Minheap* h=(struct Minheap*)malloc(sizeof(struct Minheap));
	h->capacity=capacity;
	h->count=0;
	h->pos=(int *)malloc(capacity*sizeof(int));
	h->array=(struct Minheap_node**)malloc(capacity*sizeof(struct Minheap*));
	return h;
}


struct Graph* create_graph(int v)
{
	struct Graph* g=(struct Graph*)malloc(sizeof(struct Graph));
	g->v=v;
	g->array=(struct Adjlist*)malloc(v*sizeof(struct Adjlist));
	
	for(int i=0;i<v;i++)
	{
		g->array[i].head=NULL;
	}
	return g;
}

struct Adjlistnode* new_Adjlistnode(int dest,int weight)
{
	struct Adjlistnode* node  =	(struct Adjlistnode*)malloc(sizeof(Adjlistnode));
	node->dest=dest;
	node->weight=weight;
	node->next=NULL;
	return node;
}
void addEdge(struct Graph* g,int src,int dest,int weight)
{
	struct Adjlistnode* node=new_Adjlistnode(dest,weight);
	node->next= g->array[src].head;
	g->array[src].head=node; 
	node=new_Adjlistnode(src,weight);
	node->next= g->array[dest].head;
	g->array[dest].head=node;
}

void swaps(struct Minheap_node** node1,struct Minheap_node** node2)
{
	struct Minheap_node* t=*node1;
	*node1=*node2;
	*node2=t;
}
void decrease_key(struct Minheap* h,int src,int dist)
{
	int i=h->pos[src];
	
	h->array[i]->dist=dist;
	
	if(i && h->array[i]->dist < h->array[(i-1)/2]->dist)
	{
		h->pos[h->array[i]->v]=(i-1)/2;
		h->pos[h->array[(i-1)/2]->v]=i;
		
		swaps(&h->array[i],&h->array[(i-1)/2]);
		i=(i-1)/2;
	}
	
}
void min_heapify(struct Minheap* h,int src)
{
	int min;
	int left=2*src+1;
	int right=2*src+2;
	if((left<(h->count)) && h->array[left]->dist<h->array[src]->dist)
		min=left;
	else min=src;
	
	if((right<(h->count)) && h->array[right]->dist<h->array[min]->dist)
		min=right;
		
	if(min!=src)
	{
		struct Minheap_node* node1=h->array[min];
		struct Minheap_node* src_node=h->array[src];
		
		h->pos[node1->v]=src;
		h->pos[src_node->v]=min;
		
		swaps(&h->array[min],&h->array[src]);
		
		min_heapify(h,min);
	}	
}


int isempty(struct Minheap* h)
{
	return h->count==0;
}
struct Minheap_node* extract_min(struct Minheap* h)
{
	if(isempty(h))
		return NULL;
	
	struct Minheap_node* node=h->array[0];
	struct Minheap_node* last_node=h->array[h->count-1];
	h->array[0]=last_node;
	
	h->pos[node->v]=h->count-1;
	h->pos[last_node->v]=0;
	
	--h->count;
	min_heapify(h,0);
	
	return node;
}

void print_dist(int dist[],int v)
{
	for(int i=0;i<v;i++)
	cout<<i<<"     "<<dist[i]<<endl;
}
int isinMinheap(struct Minheap* h,int v)
{
	return (h->pos[v]<h->count);
}
void dijkstra(struct Graph* g,int src)
{
	int dist[g->v];
	int v=g->v;
	struct Minheap* h=create_Minheap(v);
	for(int i=0;i<v;i++)
	{
		dist[i]=INT_MAX;
		h->array[i]=create_Minheap_node(i,dist[i]);
		h->pos[i]=i;
	}
	
	dist[src]=0;
	h->array[src]=create_Minheap_node(src,dist[src]);
	h->pos[src]=src;
	
	decrease_key(h,src,dist[src]);
	
	h->count=v;
	
	while(!isempty(h))
	{
		struct Minheap_node* heap_node=extract_min(h);
		
		int u=heap_node->v; 
		//struct Adjlist_node* crawl=g->array[u].head;
		struct Adjlistnode* crawl=g->array[u].head;
									
		while(crawl!=NULL)
		{
			int v=crawl->dest;
			
			if(isinMinheap(h,v) && dist[u]!=INT_MAX && dist[u]+crawl->weight<dist[v])
			{
				dist[v]=dist[u]+crawl->weight;
				
				decrease_key(h,v,dist[v]);
			}	
			crawl=crawl->next;
		}
	
	}
	print_dist(dist,v);
}

int main()
{
	int v=9;
	struct Graph* graph=create_graph(v);
	addEdge(graph, 0, 1, 4);
    addEdge(graph, 0, 7, 8);
    addEdge(graph, 1, 2, 8);
    addEdge(graph, 1, 7, 11);
    addEdge(graph, 2, 3, 7);
    addEdge(graph, 2, 8, 2);
    addEdge(graph, 2, 5, 4);
    addEdge(graph, 3, 4, 9);
    addEdge(graph, 3, 5, 14);
    addEdge(graph, 4, 5, 10);
    addEdge(graph, 5, 6, 2);
    addEdge(graph, 6, 7, 1);
    addEdge(graph, 6, 8, 6);
    addEdge(graph, 7, 8, 7);

    dijkstra(graph, 0);
	return 0;
}
