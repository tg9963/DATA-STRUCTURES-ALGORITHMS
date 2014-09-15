#include<iostream>
#include<stdlib.h>
#include<string.h>

using namespace std;

int find_possible(string s)
{
	if(s.size()==1 || s.size()==2)return 1; 
	int flag[256];
	for(int i=0;i<256;i++)flag[i]=0;
	
	int n=s.size();
	int count=0;
	for(int i=0;i<n;i++)flag[s[i]]+=1;
	
	for(int i=0;i<256;i++)
	{
		if(flag[i]%2 !=0)
		{
			count++;
		}
	}
	if(n%2==1 && count==1)return 1;
	else if(n%2==1 && count%2==1 )return 0;
	else if(n%2==0 && count==0)return 1;
	else if(n%2==0 && count>0)return 0;
	
	return 0;
	
}

int main()
{
	string s;
	cin>>s;
	cout<<find_possible(s);
	return 0;
	
}
