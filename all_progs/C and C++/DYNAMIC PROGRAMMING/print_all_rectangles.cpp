#include<iostream>
#include<limits.h>
using namespace std;

void print_sums(int arr[][10],int n,int m)
{
	int max_sum=INT_MIN;
	int sum=0;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			sum=arr[i][j];
			for(int p=i;p<n;p++)
			{
				for(int q=j;q<m;q++)
				{
					sum+=arr[p][q];
				}
		if(sum>max_sum)
		{
			max_sum=sum;
		}
		sum=0;
		}
			}
	}
	cout<<"MAX_SUM: "<<max_sum;
}


int main()
{
	int n,m;
	cin>>n;
	cin>>m;
	int arr[n][10];
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			cin>>arr[i][j];
		}
	}
	print_sums(arr,n,m);
	return 0;
}
