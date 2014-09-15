#include<iostream>
#include<string.h>
#include<sstream>
using namespace std;

struct lis_S
{
	int len;
	string path;
};

int max_lis(int arr[],int n)
{
	struct lis_S  lis[n];
	for(int i=0;i<n;i++)
	{
		lis[i].len=0;
		lis[i].path="";	
	}
	
	lis[0].len=1;
	stringstream ss;
	ss<<arr[0]; 
	lis[0].path=ss.str();
	for(int j=1;j<n;j++)
	{
		int max_len=0;
		for(int i=0;i<j;i++)
		{
			if(arr[i]<arr[j] && lis[i].len>max_len)
			{
				max_len=lis[i].len;
				stringstream ss;
				ss<<arr[i];
				lis[j].path+=ss.str()+" ";
			}
		}
			stringstream ss;
				ss<<arr[j];
		lis[j].len=max_len+1;
		lis[j].path+=ss.str()+" ";
	}
	
	cout<<endl;
	int max_len=INT_MIN;
	int index;
	
	for(int i=0;i<n;i++)
	{
		if(lis[i].len>max_len)
		{
			max_len=lis[i].len;
			index=i;
		}
	}
	
	for(int i=0;i<n;i++)
	{
		if(lis[i].len==max_len)
		cout<<lis[i].path<<endl; 	 
	}
	cout<<endl;
	return max_len;
}

int main()
{
	int arr[]={0,2,6,4,8,7};
	int n=sizeof(arr)/sizeof(arr[0]);
	cout<<max_lis(arr,n);
	return 0;
}
