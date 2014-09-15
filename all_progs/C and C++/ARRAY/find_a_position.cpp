#include<iostream>
using namespace std;

int find_pos(int arr[],int n)
{
	int sum=0;
	for(int i=0;i<n;i++)
	{
		sum+=arr[i];
	}
	int left_sum=arr[0];
	//cout<<sum<<endl;
	int right_sum=0;
	for(int i=1;i<n;i++)
	{
		right_sum=sum-left_sum-arr[i];
		if(left_sum==right_sum)
		{
			return i;
		}
		left_sum+=arr[i];
	} 
	return 0;
}


int main()
{
	int arr[]={2,3,8,1,13};
	int n=sizeof(arr)/sizeof(arr[0]);
	cout<<"at position "<<find_pos(arr,n)+1;
	return 0;
}
