#include<iostream>
using namespace std;

void print_pattern(int n)
{
	int remain=n;
	int i;
	int t=0;
	for(int count=0;;count++)
	{
		for(int i=0;i<count;i++)
		{
			cout<<++t<<" ";
		}
		remain=n-t;
		if(remain<count+1)
		{
			for(int i=t;i<n;i++)
			{
				cout<<++t<<" ";
			}
			break;
		}
		cout<<endl;
	}
}


int main()
{
	int n;
	cin>>n;
	print_pattern(n);
	return 0;
}
