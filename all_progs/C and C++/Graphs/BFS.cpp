#include<iostream>
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
		void add_edge(int start,int end)
		{
			adj[start].push_back(end);
		} 
		void bfs(int init)
		{
			bool *visited=new bool[v];
			for(int i=0;i<v;i++)
			{
				visited[i]=false;
			}
			list<int> queue;
			queue.push_back(0);
			visited[init]=true;
			int temp=0;
			while(!queue.empty())
			{
				temp=queue.front();
				queue.pop_front();
				cout<<temp<<"  ";
				list<int>::iterator i;
				for(i=adj[temp].begin();i!=adj[temp].end();++i)
				{
					if(visited[*i]==false)
					{
						visited[*i]=true;
						queue.push_back(*i);
					}
				}
			}
		}
};

int main()
{
	
	graph g(4);
	g.add_edge(0, 1);
    g.add_edge(0, 2);
    g.add_edge(1, 2);
    g.add_edge(2, 0);
    g.add_edge(2, 3);
    g.add_edge(3, 3);
	g.bfs(0);	

	return 0;
}
