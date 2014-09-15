#include<iostream>
#include<string.h>
using namespace std;

void print_pattern(string s)
{
	if(s.size()%2==0)return ;
	
	int n=s.size();
	for(int i=0,p=n-1;i<p;i++,p--)
	{
		for(int j=0;j<i;j++)
		{
			cout<<" ";
		}
		cout<<s[i];
		for(int k=i+1;k<p;k++)
		{
			cout<<" ";
		}
		cout<<s[p]<<endl;
	}
	for(int i=0;i<n/2;i++)cout<<" ";
	cout<<s[n/2];
	cout<<endl;
	for(int i=n/2-1,p=n/2+1;i>=0 && p<n ;i--,p++)
	{
		for(int j=0;j<i;j++)
		{
			cout<<" ";
		}
		cout<<s[i];
		for(int k=i+1;k<p;k++)
		{
			cout<<" ";
		}
		cout<<s[p]<<endl;
	}
	
}
/*
pattern: (odd isze string)
p      m
 r    a
  o  r 
   g
  o  r
 r   a
p     m
 

*/

int main()
{
	string s;
	cin>>s;
	print_pattern(s);
	return 0;
}
