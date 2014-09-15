#include<iostream>
#include <list>

using namespace std;

 
class Graph
{
    int V;     
    list<int> *adj;    
    void DFSUtil(int v, bool visited[],int array[]);   
public:
    Graph(int V);   
    void addEdge(int v, int w);    
    void DFS(int v,int array[]);     
};

Graph::Graph(int V)
{
    this->V = V;
    adj = new list<int>[V];
}

void Graph::addEdge(int v, int w)
{
    adj[v].push_back(w);  
}

void Graph::DFSUtil(int v, bool visited[],int array[])
{
 
    visited[v] = true;
    array[v]+=1;
  //cout << v << " ";
	list<int>::iterator i;
    for(i = adj[v].begin(); i != adj[v].end(); ++i)
        if(!visited[*i])
            DFSUtil(*i, visited,array);
 
}
void Graph::DFS(int v,int array[])
{
    
    bool *visited = new bool[V];
    for(int i = 0; i < V; i++)
        visited[i] = false;
        
    DFSUtil(v, visited,array);
}

int main()
{
	int n;
	cin>>n;
    Graph g(n+1);
    int m;
    cin>>m;
    for(int i=0;i<m;i++)
    {
    	int src,dest;
		cin>>src>>dest;
		g.addEdge(src-1,dest-1);
    }
    int q;
	cin>>q;
	int query[q];
	
	for(int i=0;i<q;i++)
	{
		cin>>query[i];
	}
    
    int array[n];
    for(int i=0;i<n;i++)
    {
    	array[i]=0;
    }
    
    for(int i=0;i<q;i++)
    {
    	g.DFS(query[i]-1,array);
    	array[query[i]-1]-=1;
    }
    int flag=0;
    for(int i=0;i<n;i++)
    {
    	if(array[i]==q)
    	{
    		cout<<i+1<<" ";
    		flag=1;
    	}
    }
    if(flag==0)
    {
    	cout<<-1;
    }
	return 0;
}
