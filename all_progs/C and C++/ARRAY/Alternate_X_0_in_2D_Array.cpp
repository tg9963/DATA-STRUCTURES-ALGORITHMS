#include<iostream>
#include<stdlib.h>
using namespace std;
void print_matrix(int n)
{
	char array[n][n];
	int flag=0;
	int start_row,end_row,start_col,end_col;
	start_row=start_col=0;
	end_row=end_col=n;
	int i;
	while((start_row < end_row) && (start_col < end_col ))
	{
		//first row 
		for(i=start_col;i<end_col;i++)
		{
			if(flag==0)array[start_row][i]='X';
			else array[start_row][i]='0';
		}
		start_row++; 
		for(i=start_row;i<end_row;i++)
		{
			if(flag==0)array[i][end_col-1]='X';
			else array[i][end_col-1]='0';
		}
		end_col--;
		
		if(start_row<end_row)
		{
			for(i=end_col;i>=start_col;i--)
			{ 
			  if(flag==0)array[end_row-1][i]='X';
			   else array[end_row-1][i]='0';
			}
		  end_row--;
		}
		if(start_col<end_col)
		{
			for(i=end_row;i>=start_row;i--)
			{ 
			if(flag==0)array[i][start_col]='X';
			else array[i][start_col]='0';
			}
			start_col++;
		}
		if(flag==0)flag=1;
		else flag=0;
	}
	
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		cout<<array[i][j]<<" ";
		cout<<endl;
	}	
}


int main()
{
	int n;
	cout<<"Enter n: ";
	cin>>n;
	cout<<"\n";
	print_matrix(n);
	return 0;
}
