#include<iostream>

using namespace std;

int find_power(int n,int m)
{
	if(m==1 || n==1 )
	{
		return n;
	}
	return n*find_power(n,m-1);
}

int main()
{
	int n,m;
	cin>>n>>m;
	cout<<find_power(n,m);
	return 0;
}
