#include<iostream>

using namespace std;

int main()
{
	int n;
	cin>>n;
	int count=0;
	for(int i=1;i<=n/2;i++)
	{
		for(int j=0;j<=n/2-i+1;j++)
		{
			cout<<" ";
		}
		for(int j=i;j>=1;j--)
		{
			cout<<i<<" ";
		}
		cout<<endl;
	}
	count=n/2;
	int count2=0;
	for(int i=n/2+1;i<=n+1;i++)
	{
		for(int j=0;j<=count2;j++)
		{
			cout<<" ";
		}
		for(int j=0;j<=count;j++)
		{
			cout<<i<<" ";
		}
		cout<<endl;
		count--;
		count2++;
	}
	return 0;
}
