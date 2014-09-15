#include<iostream>
#include<string.h>
using namespace std;

int Minimum(int a,int b,int c)
{
	int min=a;
	if(b<a)
	{
		min=a;
	}
	if(c<min)
	{
		min=c;
	}
	return min;
	
}

int EditDistance(string X,string Y, int m, int n )
{
    // Base cases
    if( m == 0 && n == 0 )
        return 0;
 
    if( m == 0 )
        return n;
 
    if( n == 0 )
        return m;
 
    // Recurse
    int left = EditDistance(X, Y, m-1, n) + 1;
    int right = EditDistance(X, Y, m, n-1) + 3;
    int corner = EditDistance(X, Y, m-1, n-1) + ((X[m-1] != Y[n-1])?2:0);
 
    return Minimum(left, right, corner);
}


int min_ops(string s)
{
	int values[26];
	for(int i=0;i<26;i++)values[i]=0;
	
	for(int i=0;i<s.size();i++)
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
	cout<<act<<endl;
	return EditDistance(act,s,act.size(),s.size());	
}



int main()
{
	int test;
	cin>>test;
	while(test--)
	{
		string s;
		cin>>s;
		cout<<min_ops(s);
	}
}
