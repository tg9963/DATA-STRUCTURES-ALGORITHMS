#include<iostream>

using namespace std;
int maxi(int a,int b)
{
	return (a>b?a:b);
}

int max_value(int knapsack_cap,int items,int size[],int value[])
{
	
	int m=items+1;
	int n=knapsack_cap+1;
	int res[m][n];
	
	for(int i=0;i<m;i++)for(int j=0;j<n;j++)res[i][j]=0;
	
	for(int i=0;i<n;i++)res[0][i]=0;
	
	for(int i=1;i<m;i++)
	{
		for(int j=0;j<n;j++)
		{
			if(j-size[i-1]>=0)
			res[i][j]=maxi(res[i-1][j],value[i-1]+res[i-1][j-size[i-1]]);
			else
			res[i][j]=res[i-1][j];
		}
	}
	
	
	for(int i=0;i<m;i++)
	{
		for(int j=0;j<n;j++)
		{
			cout<<res[i][j]<<"  ";
		}
		cout<<endl;
	}
	
	cout<<endl; 
	return res[m-1][n-1];
		
}

int main()
{
	int items=4;
	int size[]={5,4,6,3};
	int value[]={10,40,30,50};
	int knapsack_cap=10;
	cout<<max_value(knapsack_cap,items,size,value);
	return 0;
}
