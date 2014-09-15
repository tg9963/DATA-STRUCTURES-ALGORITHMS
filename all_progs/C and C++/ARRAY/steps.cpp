#include<iostream>

using namespace std;

void print_pattern(int n)
{
	if(n%2==0)
	{
		for(int i=0;i<n;i++)
		{
			cout<<" ";
		}
		cout<<n<<endl;
		n--;
	}
	
	while(n>0)
	{
		for(int i=0;i<n-1;i++)
		{
			cout<<" ";
		}
		if(n-1!=0)
		cout<<n-1<<endl;
		for(int i=0;i<n-1+1;i++)
		{
			cout<<" ";
		}
		cout<<n<<endl;
		n=n-2;
	}
	
	
}

int main()
{
	int n;
	cin>>n;
	print_pattern(n);
	return 0;
}
