#include<iostream>

using namespace std;

void fin_sum(int arr[],int sum,int n)
{
	int curr_sum=arr[0];
	int start=0;
	for(int i=1;i<=n;i++)
	{
		if(curr_sum==sum)
		{
			cout<<"found sub array with sum "<<sum;
			return ;
		}
		if(curr_sum < sum )
		curr_sum +=arr[i];
		else
		{
			if(arr[i]<0)
			{
				curr_sum+=arr[i];
				if(curr_sum==sum)
				{
					cout<<"found sub array with sum "<<sum;
					return ;
				}
			}
			else
			{
				while(curr_sum>sum && start < i-1)
				{
					curr_sum -=arr[start];
					start++;
				}
				if(curr_sum==sum)
				{
					cout<<"found sub array with sum "<<sum;
					return ;
				}
			}
		}
	}
}

int main()
{
	int arr[]={1,2,-3,4};
	int sum=0;
	fin_sum(arr,sum,4);
}
