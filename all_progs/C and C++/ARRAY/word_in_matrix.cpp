#include<iostream>
#include<string.h>
#include<math.h>
using namespace std;

int find_remaining(char arr[][10],int st,int end,string ip)
{
	int row[]={0,-1,1,0};
	int col[]={-1,0,0,1};
	
	for(int i_s=st;i_s<ip.size();i_s++)
	{
	for(int j_s=end;j_s<ip.size();j_s++)
	{
	for(int i=0;i<4;i++)
	{
		for(int j=0;j<4;j++)
		{
			arr[i_s+row[i]][j_s+col[j]]==ip
		}
	}
	
	}
	}
	return 0;
}


int find_present(char arr[][10],int m,string ip)
{
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			if(arr[i][j]==ip[0])
			{
				if(find_remaining(arr,i,j,m,ip))return 1;
			}
		}
	}
	return 0;
}

int main()
{
	string s;
	cin>>s;
	int n=s.size();
	float a=(sqrt(n)+0.5);
	int m=a;
	char arr[m][10];
	for(int i=0;i<m;i++)
	{
		for(int j=0;j<m;j++)
		{
			char a=' ';
			if((i*m+j) < n )
			{
				a=s[i*m+j];
			}
			arr[i][j]=a;
		}
	}
	for(int i=0;i<m;i++)
	{
	
	for(int j=0;j<m;j++)
	{
		cout<<arr[i][j]<<" ";
	}
	cout<<endl;
	}
	cout<<endl;
	string temp;
	cin>>temp;
	cout<<find_present(arr,m,temp);
	return 0;
}
