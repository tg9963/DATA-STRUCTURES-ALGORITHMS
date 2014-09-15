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
	int count=0,k=0;
	while(n--)
	{
		cin>>temp;
		count+=find_set_bits(temp);
	    k=find_set_bits(temp);
	}
	if(count%2==1 && k%2==0)
	{
		cout<<"Shaka :)";
	}
	else
	{
		cout<<"The other player :( ";
	}
}
