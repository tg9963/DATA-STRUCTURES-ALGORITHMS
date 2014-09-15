#include<iostream>

using namespace std;

int find_set_bits(int n)
{
	int count=0;
	while(n)
	{
		count++;
		n&=n-1;
	}
	return count;
}
 

int main()
{
	int n;
	cin>>n;
	int temp;
	int count=0;
//	int c[n];
	int i=0;
	int k=n;
	while(n--)
	{
		cin>>temp;
		//count=find_set_bits(temp);
		//c[i++]=count;
	}
//	count=find_posible(c,n,0);
	n=k;
	if(n%2==0)
	{
		cout<<"Shaka :)";
	}
	else
	{
		cout<<"The other player :( ";
	}
}
