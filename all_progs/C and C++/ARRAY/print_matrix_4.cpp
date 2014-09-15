#include<iostream>
#include<stdlib.h>
using namespace std;

void print_n(int n)
{
	int i,j;
	 
	int arr[2*n-1][2*n-1];
	int start_row=0,start_col=0,end_row=2*n-1,end_col=2*n-1;
	int total=n;
	
	while(start_col<end_col && start_row<end_row)
	{ 
	for(int p=start_col;p<end_col;p++)
	{
		arr[start_row][p]=total;
	}
	start_row++;
	for(int q=start_row;q<end_row;q++)
	{
		arr[q][end_col-1]=total;
	}
	end_col--;
	
	if(start_row<end_row)
	{
		for(int p=end_col;p>=start_col;p--)
		{
			arr[end_row-1][p]=total;
		}
		end_row--;
	}
	if(start_col<end_col)
	{
		for(int q=end_row;q>=start_row;q--)
		{
			arr[q][start_col]=total;
		}
		start_col++;
	}
	total--;
	}
	
	for(i=0;i<2*n-1;i++)
	{
		for(j=0;j<2*n-1;j++)
		{
			cout<<arr[i][j]<<"  ";
		}
		cout<<endl;
	}
}
int main()
{
	int n;
	cin>>n;
	print_n(n);
	return 0;
}
