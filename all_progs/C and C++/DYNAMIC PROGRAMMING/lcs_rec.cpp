#include<iostream>
#include<string.h>
using namespace std;

int man(int a,int b)
{
	return (a>b?a:b);
}

int find_lcs(string s1,string s2,int i,int j,int m,int n)
{
	if(i==m || j==n )return 0;
	else if(s1[i]==s2[j])
	{
		return 1+find_lcs(s1,s2,i+1,j+1,m,n);
	}
	else
	{
		return max(find_lcs(s1,s2,i+1,j,m,n),find_lcs(s1,s2,i,j+1,m,n));
	}
}

int lcs_dp(string s1,string s2,int m,int n)
{
	int table[m+1][n+1];
	for(int i=0;i<=m;i++)
	{
		table[i][0]=0;
	}
	for(int i=0;i<=n;i++)
	{
		table[0][i]=0;
	}
	for(int i=1;i<=m;i++)
	{
		for(int j=1;j<=n;j++)
		{
			if(s1[i-1]==s2[j-1])
			{
				table[i][j]=table[i-1][j-1]+1;
			}
			else
			{
				table[i][j]=max(table[i-1][j],table[i][j-1]);
			}
		}
	}
	for(int i=m;i>=0;i--)
	{
		for(int j=n;j>=0;j--)
		{
			if(table[i-1][j] > table[i][j-1])
			{
				i--;
			}
			else if(table[i-1][j] < table[i][j-1])
			{
				j--;	
			}
			else
			{
				cout<<s1[i-1];
				i--;j--;
			}
		}
	}
	cout<<endl;
	return table[m][n];
}



int main()
{
	string s1,s2;
	cin>>s1>>s2;
	//cout<<find_lcs(s1,s2,0,0,s1.size(),s2.size())<<endl;
	cout<<lcs_dp(s1,s2,s1.size(),s2.size());
	return 0;
}
