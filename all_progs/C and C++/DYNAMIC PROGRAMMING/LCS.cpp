#include<iostream>
#include<string.h>
using namespace std;

// lcs O(2^n) 
int maximum(int a,int b)
{
	return (a>b?a:b);
}

int lcs(char a[],int i,int m,char b[],int j,int n)
{
	if(i==m || j==n )return 0;
	if(a[i]==b[j])
	{
		return 1+lcs(a,i+1,m,b,j+1,n);
	}
	else
	{
		return maximum(lcs(a,i+1,m,b,j,n),lcs(a,i,m,b,j+1,n));
	}
}

// LCS DP O(mn)

int lcs_dp(char a[],int m,char b[],int n)
{
	int table[m+1][n+1];
	for(int i=0;i<=m;i++)
	{
		for(int j=0;j<=n;j++)
		{
			if(i==0 || j==0)
			{
				table[i][j]=0;
			}
			else if(a[i-1]==b[j-1])
			{
				table[i][j]=1+table[i-1][j-1];
			}
			else
			{
				table[i][j]=maximum(table[i-1][j],table[i][j-1]);
			}
		}
	}
	int index=table[m][n];
	char op[index+1];
	op[index]='\0';
	int i=m,j=n;
	while(i>0 && j>0)
	{
			if(a[i-1]==b[j-1])
			{
				op[index-1]=a[i-1];
				i--;j--,index--;
			}
			else if(table[i-1][j] > table[i][j-1])
			{
				i--;
			}
			else
			{
				j--;
			}
	}
	cout<<op<<endl;
	return table[m][n];
}


int main()
{
	char a[]="Hello";
	char b[]="Halo";
	cout<<lcs(a,0,strlen(a),b,0,strlen(b));
	cout<<endl;
	cout<<lcs_dp(a,strlen(a),b,strlen(b));
	return 0;
}
