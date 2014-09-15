#include<iostream>
#include<algorithm>
using namespace std;

int main()
{
	int test;
	cin>>test;
	while(test--)
	{
		int n;
		cin>>n;
		int temp;
		int m[n];
		int total=0;
		for(int i=0;i<n;i++)
		{
			cin>>temp;
			m[i]=temp;
			total+=temp;
		}
		int avg=total/n;
		int count=0;
		for(int i=0;i<n;i++)
		{
			if(m[i]>avg)
			{
				count++;
			}
		}
		cout<<count<<endl;
	}
	return 0;
}
