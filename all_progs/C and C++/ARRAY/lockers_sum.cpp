#include<iostream>
using namespace std;

int main()
{
	int arr[1000];
	int n=1000;
	for(int i=0;i<n;i++)
	{
		arr[i]=0;
	}
	for(int i=1;i<=1000;i++)
	{
		
		for(int j=1;j<=1000;j++)
		{
			
		if(j%i==0)
		{
			if(arr[j]==0)
			{
				arr[j]=1;
			}
			else if(arr[j]==1)
			{
				arr[j]=0;
			}
		}
		
	}
		 
	}
	
	for(int i=0;i<1000;i++)
	{
		if(arr[i]==1)
		{
			cout<<i<<endl;
		}
	}
	
	return 0;
}
