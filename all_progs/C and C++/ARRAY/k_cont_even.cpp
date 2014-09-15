#include<iostream>

using namespace std;

int find_pos(int arr[],int n,int k)
{
	int count=0;
	
	for(int i=0;i<n;i++)
	{
		if(arr[i]%2==0)
		{
			count++;
			if(count==k)return 1;
		}
	}
	if(count==k)return 1;
	else return 0;
}


int main()
{
	int test;
	cin>>test;
	while(test--)
	{
		int n,k;
		cin>>n;
		cin>>k;
		int arr[n];
		for(int i=0;i<n;i++)cin>>arr[i];
		if(find_pos(arr,n,k))
		{
			cout<<"YES";
		}
		else cout<<"NO";
		
		cout<<endl;
	}
	return 0;
}
