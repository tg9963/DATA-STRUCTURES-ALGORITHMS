#include<iostream>
#include<stdlib.h>
using namespace std;

int main()
{
	int test;
	cin>>test;
	while(test--)
	{
		int n;
		cin>>n;
		long long first[n];
		long long second[n];
		long long min1,min2;
		cin>>first[0];
		min1=first[0];
		for(int i=1;i<n;i++)
		{
			cin>>first[i];
			if(first[i]<min1)
			{
				min1=first[i];
			}
		}
		cin>>second[0];
		min2=second[0];
		for(int i=1;i<n;i++)
		{
			cin>>second[i];
			if(second[i]<min2)
			{
				min2=second[i];
			}
		}
		cout<<abs(min1-min2)<<endl;
	}
	return 0;
}
