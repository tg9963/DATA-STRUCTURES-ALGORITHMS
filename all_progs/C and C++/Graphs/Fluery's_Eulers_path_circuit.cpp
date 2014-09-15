#include<iostream>
#include<stdlib.h>
#include<list>
using namespace std;

class graph
{
	int v;
	list<int> *adj;
	public:
		graph(int v)
		{
			this->v=v;
			adj=new list<int>[v];
		}
		void addedge(int src,int dest)
		{
			adj[src].push_back(dest);
			adj[dest].push_back(src);
		}
		void find_odd_vertices(int *odd_vertex,int *number)
		{
			for(int i=0;i<v;i++)
			{
				
				if(adj[i].size()%2==1)
				{
					*odd_vertex=i;
					(*number)++;
				}
			}
		}
		int dfs(int src,bool visited[])
		{
			  visited[src] = true;
 			 int count = 1;
 
  				// Recur for all vertices adjacent to this vertex
  				list<int>::iterator i;
  				for (i = adj[src].begin(); i != adj[src].end(); ++i)
      				if (*i != -1 && !visited[*i])
          				count += dfs(*i, visited);
 
  			return count;

 		}
		void rmv_edge(int src,int dest)
		{
			list<int>::iterator i;
			for(i=adj[src].begin();i!=adj[src].end();i++)
			{
				if(*i==dest)
				{
					*i=-1;
				}
			}
			for(i=adj[dest].begin();i!=adj[dest].end();i++)
			{
				if(*i==src)
				{
					*i=-1;
				}
			} 
		}
		bool isvalid(int u,int a)
		{
			 
			int count=0;
			list<int>::iterator i;
			for(i=adj[u].begin();i!=adj[u].end();i++)
			{
				if(*i!=-1)count++;
			}
			if(count==1)return true;
		 	bool visited[v];
			for(int i=0;i<v;i++)visited[i]=false;
			
			int dfs_count1=dfs(u,visited);
			rmv_edge(u,a);
			for(int i=0;i<v;i++)visited[i]=false;
			int dfs_count2=dfs(u,visited);
		 	addedge(u,a);
			return ( dfs_count1>dfs_count2 ? true:false );
		}
		
		void find_eulers_util(int vertex)
		{
			list<int>::iterator i;
			for(i=adj[vertex].begin(); i!=adj[vertex].end() ;++i)
			{
				int temp=*i;
				//cout<<temp<<endl;
				if(temp!=-1 && isvalid(vertex,temp))
				{
					cout<<vertex<<" - "<<temp<<"  ";
					rmv_edge(vertex,temp);
					find_eulers_util(temp);
				}
				
			}
			/*
			for(i=adj[vertex].begin(); i!=adj[vertex].end() ;++i)
			{
				int temp=*i;
				cout<<"temp: "<<temp<<endl;
				if(temp!=-1 && isvalid(vertex,temp))
				{
					cout<<vertex<<" - "<<temp<<"  ";
					rmv_edge(vertex,temp);
					find_eulers_util(temp);
				}
			}
			*/
		}
		
		 
		void find_eulers()
		{
			int odd_vertex=0,number=0;
			find_odd_vertices(&odd_vertex,&number);
			if(number>2 || number==-1)
			{
				cout<<"No Euler path/circuit possible ";
				return ;
			}
			odd_vertex=2;
			find_eulers_util(odd_vertex);
		}
		void print_edges()
		{
			for(int i=0;i<v;i++)
			{
				list<int>::iterator j;
				for(j=adj[i].begin();j!=adj[i].end();j++)
				{
					cout<<i<<" - "<<*j<<endl;
				}
				
			}
		}
};

int main()
{
	graph g(4);
	g.addedge(0,1);
	g.addedge(0,2);
	g.addedge(1,2);
	g.addedge(2,3);
//	g.print_edges();
	g.find_eulers();
	return 0;
}
