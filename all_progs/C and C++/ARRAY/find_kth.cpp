#include<iostream>
#include<stdlib.h>
using namespace std;

int find_kthsmallest(int arr[],int n,int k)
{
	if(n<=0 || k>n)return -1;
	int min,min_index;
	bool visited[n];
	for(int i=0;i<n;i++)visited[i]=false;
	for(int i=0;i<k;i++)
	{
		 min=INT_MAX;
		min_index=INT_MAX;
		for(int j=0;j<n;j++)
		{
			if(arr[j]<min && visited[j]==false)
			{
				min=arr[j];
				min_index=j; 
			} 
		} 
		visited[min_index]=true;
		 
	}
	return min;
}

int find_kthlargest(int arr[],int n,int k)
{
	if(n<=0 || k>n)return -1;
	int max,max_index;
	bool visited[n];
	for(int i=0;i<n;i++)visited[i]=false;
	for(int i=0;i<k;i++)
	{
		 max=INT_MIN;
		max_index=INT_MIN;
		for(int j=0;j<n;j++)
		{
			if(arr[j]>max && visited[j]==false)
			{
				max=arr[j];
				max_index=j; 
			} 
		} 
		visited[max_index]=true;
		 
	}
	return max;
}

int main()
{
	int arr[]={11,2,3,5,6};
	int n=5;
	int k=2;
	cout<<find_kthsmallest(arr,n,k);
	cout<<endl;
	cout<<find_kthlargest(arr,n,k);
	return 0;
}
