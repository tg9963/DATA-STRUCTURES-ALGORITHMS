#include<iostream>
#include<stdlib.h>
using namespace std;

int maximum(int a,int b)
{
	return (a>b?a:b);
}

int find_sum(int arr[],int n)
{
	int sum=longest_sum_sequence_non_adj(arr,n);
}

int longest_sum_sequence_non_adj(int arr[],int n)
{
	int *op=(int*)malloc(n*sizeof(int));
	op[0]=arr[0];		
	op[1]=maximum(arr[0],arr[1]);
	for(int i=2;i<n;i++)
	{
		op[i]=maximum(op[i-2]+arr[i],op[i-1]);
	}
	return op[n-1];
}

int main()
{
	int arr[]={15,5,-1,4,-3,6};
	int n=sizeof(arr)/sizeof(arr[0]);
	cout<<longest_sum_sequence_non_adj(arr,n);
	return 0;
}
