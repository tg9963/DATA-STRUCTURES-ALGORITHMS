#include<iostream>

using namespace std;


// 2^n complexity
int fib(int n)
{
	if(n==0)return 0;
	if(n==1)return 1;
	return (fib(n-1)+fib(n-2));
}

//bottom up -> O(n)
int fib_B_DP(int n)
{
	int fib[n];
	fib[0]=0;
	fib[1]=1;
	
	for(int i=2;i<=n;i++)
	fib[i]=fib[i-1]+fib[i-2];
	
	return fib[n];
}

//Top down O(n)

int fib_T_DP(int n)
{
	static int fib_table[10];
	if(n==1)return 1;
	if(n==2)return 1;
	if(fib_table[n]!=0)return fib_table[n];
	fib_table[n]=fib_T_DP(n-1)+fib_T_DP(n-2);
	return fib_table[n];
}

int main()
{
 
	int n=7;
	cout<<fib(n);
	cout<<endl;
	cout<<fib_B_DP(n);
	cout<<endl;
	cout<<fib_T_DP(n);
	return 0;
}
