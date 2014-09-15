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
		int bfs(int init)
		{
			bool *visited=new bool[v];
			int *color=new int[v];
			for(int i=0;i<v-1;i++)
			{
				visited[i]=false;
				color[i]=-1;
			}
			list<int> queue;
			queue.push_back(0);
			visited[init]=true;
			color[init]=1;
			int temp=0;
			while(!queue.empty())
			{
				temp=queue.front();
				queue.pop_front();
		 		list<int>::iterator i;
				for(i=adj[temp].begin();i!=adj[temp].end();++i)
				{
					if(visited[*i]==false)
					{
						visited[*i]=true;
						color[*i]=1-color[temp];
						queue.push_back(*i);
					}
					else
					{
						if(color[*i]==color[temp])return 0;
					}
				}
			}
			return 1;
		}
};

int main()
{
	int n;
	cin>>n;
	
    graph g(n+1);
    if(n==1)
    {
    	cout<<"No ";
    	return 0;
    }
	int m;
    cin>>m;
    
	for(int i=0;i<m;i++)
    {
    	int src,dest;
		cin>>src>>dest;
		g.add_edge(src-1,dest-1);
    }
	 if(g.bfs(0))
	 {
	 	cout<<"Yes ";
	 }
	 else
	 {
	 	cout<<"No ";
	 } 	

	return 0;
}
