#include<iostream>
#include<vector>
#include<sstream>
using namespace std;

void print_all_cities(int graph[100][100],int n)
{
	for(int i=0;i<n;i++)
	{
		if(graph[i][i]==1)
		{
			cout<<i<<"  ";
		}
	}
	cout<<endl;
}

void delete_route(int graph[100][100],int src,int dest,int* n)
{
	if(graph[src][src]==1 && graph[dest][dest]==1)
	{
			if (graph[src][dest]!=0)
			{
				cout<<"\n Route Found \n";
				graph[src][dest]=0;
				graph[dest][src]=0;
				cout<<"\n Route Deleted \n";
				int count1=0,count2=0;
				for(int i=0;i<(*n);i++)
				{
					if(graph[src][i]>0)
					{
						count1++;
					}
					if(graph[dest][i]>0)
					{
						count2++;
					}
				}
				if(count1==1)
				{
					graph[src][src]=0;
					(*n)--;
				}
				if(count2==1)
				{
					graph[dest][dest]=0;
				(*n)--;
				}
			}
			else
			{
				cout<<"\n\nRoute Not found\n\n";
			}
		
	}
	else
	{
		cout<<"\n\nRoute Not found\n\n";
	}
}

void add_route(int graph[100][100],int src,int dest,int* n,int weight)
{
	if(graph[src][dest]==0 )
	{
		if(graph[dest][dest]==0)
		{
			graph[dest][dest]=1;
			(*n)++;
		}
		graph[src][dest]=weight;
		graph[dest][src]=weight;
		
	}
	else
	{
		graph[src][dest]=weight;
	}
	
}

int busy_city(int graph[100][100],int n)
{
	int max_deg=INT_MIN;
	int max_city;
	for(int i=0;i<n;i++)
	{
		int count=0;
		for(int j=0;j<n;j++)
		{
			if(graph[i][j]>1)
			{
				count++;
			}
		}
		if(max_deg<count)
		{
			max_deg=count;
			max_city=i;
		}
	}
	return max_city;
}

void find_city(int graph[100][100],int n,int k)
{
	if(k>n)
	{
		cout<<"\n city not found \n";
		return ;
	}
	if(graph[k][k]==1)
	{
		cout<<"\n city found \n";
	}
}



int min_dist(int dist[],bool set[],int n)
{
	int min=INT_MAX,min_index;
	for(int i=0;i<n;i++)
	{
		if(set[i]==false && dist[i]<min)
		{  
			min=dist[i];
			min_index=i;
		}
	}
	return min_index;
}



int shortest_dist(int graph[100][100],int src,int dest,int n)
{
	int dist[n];
	bool set[n];
	
	for(int i=0;i<n;i++)
	{
		dist[i]=INT_MAX;
		set[i]=false;
	}
	
	dist[src]=0;
	
	for(int i=0;i<n;i++)
	{
		int m=min_dist(dist,set,n);
		set[m]=true;
		for(int j=0;j<n;j++)
		{
			if(m!=j && !set[j] && graph[m][j] && dist[m]!=INT_MAX && (dist[j]<dist[m]+graph[m][j]))
			{
				dist[j]=dist[m]+graph[m][j];
			}
		}
	}
	return dist[dest];
}





static int rec[100];
static int path[100];
static int path_len;

void print_path(int path[],int path_len)
{
	for(int i=0;i<path_len;i++)
	{
		cout<<path[i]<<" ";
	}
}


int find_paths_util(int graph[100][100],int n,int src,int dest)
{
	if(src==dest || graph[src][dest]>1)
	{
		path[path_len++]=src;
		print_path(path,path_len);
	//	cout<<dest<<"  ";
		return 1;
	}
	
		for(int j=0;j<n;j++)
		{
			if((j!=src) && graph[src][j]>1)
			{
				rec[src]=1;
				if(rec[j]!=1 && find_paths_util(graph,n,j,dest) )
				{
					//possible[src]=1;
					path[path_len++]=j;
				}
				rec[src]=0;
			}
		}
		return 0;
}



void find_all_routes(int graph[100][100],int n,int src,int dest)
{
	if(graph[src][src]!=1 || graph[dest][dest]!=1)
	{
		cout<<"\n\n No route \n\n";
		return ;
	}
	string s;
	stringstream ss;
	ss<<src;
	s=" "+src;
	path[path_len++]=src;
	if(find_paths_util(graph,n,src,dest))
	{
		cout<<src<<" ";
	}
	else
	{
		cout<<"\n No path \n";
	}
}

int main()
{
	int choice;
	int n;
	cout<<"Enter the number of Cities: ";
	cin>>n;
	int graph[100][100];
	for(int i=0;i<100;i++)
	{
		for(int j=0;j<100;j++)
		{
			graph[i][j]=0;
		}
	}
	cout<<" Enter the edges: \n\n\n";
	while(1)
	{
		cout<<" Enter source, destination, weight: ";
		int src,dest,weight;
		cin>>src>>dest>>weight;
		if(graph[src][dest]==0 || graph[dest][dest]==0)
		{
			n++;
		}
		graph[src][src]=1;
		graph[dest][dest]=1;
		graph[src][dest]=weight;
		graph[dest][src]=weight;
		char ch;
		cout<<" Continue? (y/n): ";
		cin>>ch;
		if(ch!='y')
		{
			break;
		}
		cout<<endl;
	}	
	while(1)
 {
	cout<<"\n\n\n Enter the choice \n\n";
	cout<<" 1. List cities \n"<<" 2.Delete Route \n"<<" 3.Add Route \n"<<" 4.Busy Route \n"<<" 5.Find city \n"<<" 6.Find all Routes \n"<<" 7. Shortest path \n"<<" 8.Exit \n";
	cin>>choice;	
	switch(choice)
	{
		case 1:
			cout<<" \n\n\nListing the cities.......\n\n\n";
			print_all_cities(graph,n);
			cout<<endl<<endl;
			break;
		case 2:
			cout<<" Enter the src and dest of the route ";
			int src;
			int dest;
			cin>>src>>dest;
			delete_route(graph,src,dest,&n);
			break;
		case 3:
			cout<<" \n\n Enter the source and dest \n\n";
			cin>>src;
			cin>>dest;
			cout<<"\n\nEnter the weight between "<<src<<"  "<<dest<<" : ";
			int weight;
			cin>>weight;
			add_route(graph,src,dest,&n,weight);
			cout<<"\n\nRoute added successfully\n";
			break;
		case 4:
			cout<<" Busy city is : "<<busy_city(graph,n)<<endl;
			break;
		case 5:
			cout<<" Enter the city: ";
			int k;
			cin>>k;
			find_city(graph,n,k);
			break;
		case 6:
			//src,dest;
			cin>>src>>dest;
			cout<<" All routes between "<<src<<" "<<dest<<" : \n\n";
			find_all_routes(graph,n,src,dest);
			break;
		case 7:
			cin>>src>>dest;
			cout<<shortest_dist(graph,src,dest,n);
			break;
		case 8:
			break;
		default:
			cout<<"Invalid choice!! \n\n";
			break;
	}
	cout<<" Continue? (y/n): ";
		char ch;
		cin>>ch;
		if(ch!='y')
		{
			break;
		}
	
}
	return 0;
}
