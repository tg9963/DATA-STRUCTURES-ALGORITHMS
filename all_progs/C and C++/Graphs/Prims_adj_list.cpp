#include<iostream>
#include<stdlib.h>
using namespace std;

struct adj_list_node
{
	int dest;
	int weight;
	struct adj_list_node* next;
};

struct adj_list
{
	struct adj_list_node* head;
};

struct graph
{
	int capacity;
	struct adj_list* array; 	
};

struct graph* create_graph(int capacity)
{
	struct graph* g=(struct graph*)malloc(sizeof(struct graph));
	g->capacity=capacity;
	g->array=(struct adj_list*)malloc(capacity*sizeof(struct adj_list));
	for(int i=0;i<capacity;i++)
	{
		g->array[i].head=NULL;
	}
	return g;
}

struct adj_list_node* create_adj_list_node(int dest,int weight)
{
	struct adj_list_node* node1=(struct adj_list_node*)malloc(sizeof(struct adj_list_node));
	node1->dest=dest;
	node1->next=NULL;
	node1->weight=weight;
	return node1;
}
void add_edge(struct graph* g,int src,int dest,int weight)
{
	struct adj_list_node* node1=create_adj_list_node(dest,weight);
	node1->next=g->array[src].head;
	g->array[src].head=node1;
	node1=create_adj_list_node(src,weight);
	node1->next=g->array[dest].head;
	g->array[dest].head=node1;
}

struct min_heap_node
{
	int v;
	int dist;
};

struct min_heap
{
	int capacity;
	int count;
	int *pos;
	struct min_heap_node* *array;
};

struct min_heap_node* create_heap_node(int v,int dist)
{
	struct min_heap_node* node=(struct min_heap_node*)malloc(sizeof(struct min_heap_node));
	node->dist=dist;
	node->v=v;
	return node;
}

struct min_heap* create_min_heap(int capacity)
{
	struct min_heap* h=(struct min_heap*)malloc(sizeof(struct min_heap));
	h->capacity=capacity;
	h->count=0;
	h->array=(struct min_heap_node**)malloc(capacity*sizeof(struct min_heap_node*));
	h->pos=(int*)malloc(capacity*sizeof(int));
	return h;
}


void swap_nodes(struct min_heap_node** node1,struct min_heap_node** node2)
{
	struct min_heap_node* t=*node1;
	*node1=*node2;
	*node2=t;
}


void decrease_heap(struct min_heap* h,int src,int dist)
{
	int i=h->pos[src];
	h->array[i]->dist=dist;
	 
	while(i && h->array[i]->dist<h->array[(i-1)/2]->dist)
	{
		struct min_heap_node* node1=h->array[i];
		struct min_heap_node* node2=h->array[(i-1)/2];
		h->pos[node1->v]=(i-1)/2;
		h->pos[node2->v]=i;
		swap_nodes(&h->array[i],&h->array[(i-1)/2]);
		i=(i-1)/2;
	}
}

void min_heapify(struct min_heap* h,int src)
{
	int left,right,min;
	left=2*src+1;
	right=2*src+2;
	min=src;
	
	if(left<h->count && h->array[left]->dist<h->array[min]->dist)
		min=left;
	if(right<h->count && h->array[right]->dist<h->array[min]->dist)
		min=right;
		
	if(min!=src)
	{
		struct min_heap_node* min_node=h->array[min];
		struct min_heap_node* src_node=h->array[src];
		h->pos[min_node->v]=src;
		h->pos[src_node->v]=min;
		swap_nodes(&h->array[min],&h->array[src] );
		min_heapify(h,min);
	}
}

int isempty(struct min_heap* h)
{
	return h->count==0;
}
struct min_heap_node* extract_min(struct min_heap* h)
{
	if(isempty(h))return NULL;
	 struct min_heap_node* first_node=h->array[0];
	 struct min_heap_node* last_node=h->array[h->count-1];
	h->array[0]=last_node;
	h->pos[first_node->v]=h->count-1;
	h->pos[last_node->v]=0;
	--h->count;
	min_heapify(h,0);
	return first_node;
}
int isinheap(struct min_heap* h,int pos)
{
	return h->pos[pos]<(h->count);
}

void print_array(int parent[],int dist[],int v)
{
	cout<<"PRIMS "<<endl;
	cout<<"NODE    PARENT    Min_distance from 0"<<endl;
	for(int i=1;i<v;i++)
	{
		cout<<i<<"         "<<parent[i]<<"       "<<dist[i]<<endl;
	}
}


void prims(struct graph* g,int src)
{
	int v=g->capacity;
	int parent[v];
	int dist[v];
	struct min_heap* h=create_min_heap(v);
	for(int i=0;i<v;i++)
	{
		dist[i]=INT_MAX;
		parent[i]=-1;
		h->array[i]=create_heap_node(i,dist[i]);
		h->pos[i]=i;
	}
	h->count=v;
	dist[src]=0;
	parent[src]=-1;
	h->pos[src]=0;
	h->array[src]=create_heap_node(src,dist[src]);
	
	decrease_heap(h,src,dist[src]);
	
	while(!isempty(h))
	{
		struct min_heap_node* min_node=extract_min(h);
		//cout<<"min: "<<min_node->v<<endl;
		int a=min_node->v;
		
		struct adj_list_node* crawl=g->array[a].head;
		
		while(crawl)
		{
			int v=crawl->dest;
			//cout<<"v: "<<v<<endl;
			if(isinheap(h,v) && dist[a]!=INT_MAX &&  crawl->weight + dist[a] < dist[v] )
				{
					//cout<<"v: "<<v<<endl;
 					dist[v]=crawl->weight+dist[a]; 
					 parent[v]=a;
 					decrease_heap(h,v,dist[v]);
				}
			crawl=crawl->next;
		}
	}
	print_array(parent,dist,v);
}

int main()
{
	/*
	     5          3      
	0----------1-------	2
	| \				   	|
4	|  \ 			    |  4
	|	\ 	10			|
   3	 \				6
5	|	  \				|
	|	   \			|  1
	7--------4---------5	
        12        3   	
	*/
	/* order of edges does not matter, give in any order. */
	struct graph* g=create_graph(8);
	
	
	add_edge(g,0,3,4);
	add_edge(g,0,4,10);
	add_edge(g,1,2,3);
	add_edge(g,2,6,4);
	add_edge(g,6,5,1);
	add_edge(g,3,7,5);
	add_edge(g,4,5,3);
	add_edge(g,7,4,12); 
	add_edge(g,0,1,5);
	prims(g,0);
}

