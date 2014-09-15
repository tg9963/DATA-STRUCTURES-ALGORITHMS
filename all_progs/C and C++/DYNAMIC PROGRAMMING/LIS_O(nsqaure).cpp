#include<iostream>

using namespace std;

/// WRONG IMPLEMENTATION ///


int LIS(int arr[],int n)
{
	int longest[n];
	int max_length=INT_MIN;
	for(int i=0;i<n;i++)
	{
		int prev_index=i;
		int temp_length=1;
		for(int j=i+1;j<n;j++)
		{
			if(arr[j]>arr[prev_index])
			{
				prev_index=j;
				temp_length++;
			}
		}
		if(temp_length>max_length)
		{
			max_length=temp_length;
		}
	}
	return max_length;
}

int main()
{
	int arr[]={2,-1,7,4,3,5};
	int n=sizeof(arr)/sizeof(arr[0]);
	cout<<LIS(arr,n);
	return 0;
}
