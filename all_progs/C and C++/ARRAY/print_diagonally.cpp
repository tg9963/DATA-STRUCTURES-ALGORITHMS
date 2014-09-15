#include<iostream>
using namespace std;

void print_arr(int arr[][10],int n)
{
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			cout<<arr[i][j]<<" ";
		}
		cout<<endl;
	}
}


void print_diagonally(int arr[][10],int n)
{
	 int count=0;
	 int m=n;
	 cout<<endl<<endl;
	 for(int k=0;k<n;k++)
	 {
	 	for(int i=0,j=count;i<n && j<m ;i++,j++)
	 	{
	 		cout<<arr[i][j]<<" ";
	 	}
	 	count++;
	 }
}

void print_in_stripes(int arr[][10],int n)
{
	for(int k=0;k<2*n;k++)
	{
		int j=0;
		for(int i=k;i>=0;i--)
		{
			j=n-i;
			cout<<arr[i][j]<<"  ";
		}
	}
}

int main()
{
	int n;
	cin>>n;
	int arr[n][10];
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			arr[i][j]=i*n+j;
		}
	}
	print_arr(arr,n);
	print_in_stripes(arr,n);
	return 0;
}
