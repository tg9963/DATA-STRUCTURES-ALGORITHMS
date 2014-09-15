#include<iostream>

using namespace std;
 int max(int a,int b)
 {
 	return (a>b?a:b);
 }
int max_sum(int arr[],int n)
{
	int m[n];
	m[0]=arr[0];
	int maxi=m[0];
	for(int i=1;i<n;i++)
	{
		m[i]=max(m[i-1]+arr[i],arr[i]);
		if(maxi<m[i])maxi=m[i];
	}
	return maxi;
}

int main()
{
	int n;
	cin>>n;
	int arr[n];
	for(int i=0;i<n;i++)cin>>arr[i];
	
	cout<<max_sum(arr,n);
	return 0;
}
