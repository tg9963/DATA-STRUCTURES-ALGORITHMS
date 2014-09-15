#include<iostream>
using namespace std;


//O(n) 
int fact(int n)
{
	if(n==0 || n==1)return 1;
	return n*fact(n-1);
}


//Bottom up O(n)-> not useful

int fact_DP(int n)
{
	int f[n+1];
	f[0]=f[1]=1;
	
	for(int i=2;i<=n;i++)
	{
		f[i]=i*f[i-1];
	}
	return f[n];
}

//top down->useful sometimes O(1) and worst case O(n)

int top_down(int n)
{
	static int fact_table[10];
	if(n==1 || n==0 )return 1;
	fact_table[0]=1;
	fact_table[1]=1;
	if(fact_table[n]!=0)return fact_table[n];
	fact_table[n]=n*top_down(n-1);
	
	return fact_table[n];
}



int main()
{
	int n=5;
	cout<<fact(n);
	cout<<endl;
	cout<<fact_DP(n);
	cout<<endl;
	cout<<top_down(n);
	return 0;
}
