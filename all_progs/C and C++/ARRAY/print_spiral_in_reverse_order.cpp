#include<iostream>
#include<stdlib.h>
#include<stack>

using namespace std;
 
void print_spiral()
{
	int n=3;
	int arr[n][n];
	int count=0;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			arr[i][j]=count++;
		}
	}
	stack<int> s;
	int start_row=0,end_row=n,start_col=0,end_col=n;
	while(start_row<end_row && start_col <end_col)
	{
		for(int i=start_col;i<end_col;i++)
		{
			s.push(arr[start_row][i]);
		}
		start_row++;
		
		for(int j=start_row;j<end_row;j++)
		{
			s.push(arr[j][end_col-1]);
		}
		end_col--;
		
		if(start_row<end_row)
		{
			for(int i=end_col-1;i>=start_col;i--)
			{
				s.push(arr[end_row-1][i]);
			}
			end_row--;
		}
		if(start_col<end_col)
		{
			for(int i=end_row-1;i>=start_row;i--)
			{
				s.push(arr[i][start_col]);
			}
			start_col++;
		}
	}
	
	
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			cout<<arr[i][j]<<" ";
		}
		cout<<endl;
	}
	
	cout<<endl<<endl;
	while(!s.empty())
	{
		cout<<s.top()<<" ";
		s.pop();
	}
	
}

int main()
{
	print_spiral();
	return 0;
}
