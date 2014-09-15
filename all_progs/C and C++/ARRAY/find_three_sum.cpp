#include<iostream>
#include<algorithm>
using namespace std;

int find_three_max_sum(int arr[],int n)
{
	if(n==0)return 0;
	sort(arr,arr+n);
	if(n>=3)
	{
		return arr[n-3]+arr[n-2]+arr[n-1];
	}
	else if(n==2)
	{
		return arr[n-2]+arr[n-1];	
	}
	else if(n==1)
	{
		return arr[n-1];
	}
	return 0;
}


int main()
{
	int arr[]={1,5,7,-8,6};
	int n=sizeof(arr)/sizeof(arr[0]);
	cout<<find_three_max_sum(arr,n);
	return 0;
}
