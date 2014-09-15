#include<iostream>
#include<vector>
#include<map>
using namespace std;


void func(vector<int>& inp,int n,int q,int query[])
{
	
}

int main()
{
	int n;
	vector<int> inp[n];
	cin>>n;
	int m;
	cin>>m;
	for(int i=0;i<m;i++)
	{
		int src,dest;
		cin>>src>>dest;
		inp[src].push_back(dest);
	}
	int q;
	cin>>q;
	int query[q];
	
	for(int i=0;i<q;i++)
	{
		cin>>query[i];
	}
	func(inp,n,q,query);
	
	return 0;
}
