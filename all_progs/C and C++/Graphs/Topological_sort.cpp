#include<iostream>
#include<list>
#include<stack>
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
		
		void add_edge(int a,int b)
		{
			adj[a].push_back(b);
		}
		
		void topological_util(int i,bool visited[],stack<int> &s)
		{
			visited[i]=true;
			list<int>::iterator it;
			
			for(it=adj[i].begin();it!=adj[i].end();++it)
			{ 
				if(!visited[*it])
					topological_util(*it,visited,s);
			}
			
			s.push(i);
		}
		
		
		void topological_sort()
		{
			bool *visited=new bool[v];
			
			for(int i=0;i<v;i++)
				visited[i]=false;
			
			stack<int> s;
			
			for(int i=0;i<v;i++)
			{
				if(visited[i]==false)
				{
					topological_util(i,visited,s);
				}
			}
			
			while(!s.empty())
			{
				cout<<s.top()<<"   ";
				s.pop();
			}
		}
		
};

int main()
{
	graph g(3); 
    g.add_edge(0,1);
    g.add_edge(1,2);
    g.add_edge(0,2); 
	g.topological_sort();
	return 0;
}
