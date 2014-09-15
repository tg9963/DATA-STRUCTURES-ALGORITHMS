#include<iostream>
#include<string.h>
#include<algorithm>
using namespace std;
int min_ops(string s)
{
	sort(s.begin(),s.end());
	int values[26];
	for(int i=0;i<26;i++)values[i]=0;
	int p=s.size();
	for(int i=0;i<p;i++)
	{
		values[s[i]-97]+=1;
	}
	string act="";
	for(int i=0;i<26;i++)
	{
		if(values[i]>0)
		{
			for(int j=0;j<=i;j++)
			{
				char ch=(i+97);
				act+=ch;
			}
		}
	}
	//cout<<act<<endl;
	int m=s.size();
	int n=act.size();
	int i=0,j=0;
	string s1="";
	string act1="";
	while(i<m && j<n)
	{
		if(s[i]==act[j])
		{
			i++;
			j++;
			continue;
		}
		if(s[i]<act[j])
		{
			s1+=s[i];
			i++;
			continue;
		}
		if(act[j]<s[i])
		{
			act1+=act[j];
			j++;
			continue;
		}
	}
	
	if(i!=m)
	{
		s1+=s.substr(i,m-i+1);
	}
	if(j!=n)
	{
		act1+=act.substr(j,n-j+1);
	}
	//cout<<s1<<endl<<act1<<endl;
	m=s1.size();
	n=act1.size();
	if(m<=n)
	{
		return m+(n-m)*2;
	}
	if(m==0)
	{
		return (n*2);
	}
	if(m>n)
	{
		return n+(m-n)*3;
	}
	return 0;
}



int main()
{
	int test;
	cin>>test;
	while(test--)
	{
		string s;
		cin>>s;
		cout<<min_ops(s)<<endl;
	}
}
