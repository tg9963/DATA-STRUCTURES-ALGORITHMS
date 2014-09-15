#include<iostream>
#include<stdlib.h>
using namespace std;

struct edge
{
	int src,dest,weight;
};

struct graph
{
	int v,e;
	struct edge* array;
};

struct subset
{
	int parent;
	int rank;
};

struct graph* create_graph(int v,int e)
{
	struct graph* g=(struct graph*)malloc(sizeof(struct graph));
	g->e=e;
	g->v=v;
	g->array=(struct edge*)malloc(g->e*sizeof(struct edge));
	return g;
}
int comp(const void* a,const void *b)
{
	struct edge* a1=(struct edge *)a;
	struct edge* b1=(struct edge *)b;
	return a1->weight> b1->weight;
}

void print_set(struct edge result[],int res)
{
	for(int i=0;i<res;i++)
	{
		cout<<result[i].src<<"  "<<result[i].dest<<"   "<<result[i].weight<<endl;
	}
	cout<<endl;
}
int find_set(struct subset *set,int i)
{
	if(set[i].parent==i)return i;
	else
	{
		//path compresion  (assigning parent of parent)
		set[i].parent=find_set(set,set[i].parent);
		return set[i].parent;
	}
}
void union_set(struct subset  *set,int x,int y)
{
	int xset=find_set(set,x);
	int yset=find_set(set,y);
	
	if(set[xset].rank < set[yset].rank)
	{
		set[xset].parent=set[yset].parent;
	}
	else if(set[xset].rank > set[yset].rank)
	{
		set[yset].parent=set[xset].parent;
	}
	else
	{
		
	//balancing using rank
		set[yset].parent=xset;
		set[xset].rank++;
	}
}
void kruskals(struct graph* g)
{
	int v=g->v;
	int e=g->e;
	struct edge result[v]; //mst ll ve atmost v-1 edges
	struct subset *set=(struct subset*)malloc(v * sizeof(struct subset));
	
	for(int i=0;i<v;i++)
	{
		set[i].parent=i;
		set[i].rank=-1;
	}
	qsort(g->array,g->e,sizeof(g->array[0]),comp);
 	
 	int res=0;
 	int i=0;
 	
	 while(res<v-1)
 	{
 		struct edge temp=g->array[i++];
 		int xset=find_set(set,temp.src);
 		int yset=find_set(set,temp.dest);
 		 	
 		
		 if(xset!=yset)
		 {
		 	result[res++]=temp;
		 	union_set(set,xset,yset);
		 }	
 	}
 	print_set(result,res);
}

int main()
{
	/*
	    1       5
	0-------1--------2
	| \    |      /  |
	|  \ 3 |    /    |
   6|  8\  |  / 2    |4
	|    \ |/        |
	3------4--------5
	   7       3
	
	*/
	int v=6,e=9;
	
	struct graph* g=create_graph(v,e);
	g->array[0].src=0;
	g->array[0].dest=1;
	g->array[0].weight=1;

	g->array[1].src=0;
	g->array[1].dest=3;
	g->array[1].weight=6;
	
	g->array[2].src=3;
	g->array[2].dest=4;
	g->array[2].weight=7;

	g->array[3].src=1;
	g->array[3].dest=4;
	g->array[3].weight=3;

	g->array[4].src=0;
	g->array[4].dest=4;
	g->array[4].weight=8;

	g->array[5].src=1;
	g->array[5].dest=2;
	g->array[5].weight=5;
	
	g->array[6].src=4;
	g->array[6].dest=5;
	g->array[6].weight=3;

	g->array[7].src=2;
	g->array[7].dest=4;
	g->array[7].weight=2;

	g->array[8].src=2;
	g->array[8].dest=5;
	g->array[8].weight=4;
	
	kruskals(g);
	return 0;
}
