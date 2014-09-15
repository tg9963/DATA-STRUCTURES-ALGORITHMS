#include<iostream>
#include<limits.h>
#include<vector>
using namespace std;

int minimum(int a,int b)
{
	return (a>b?b:a);
}

void print_denom(int result[],int j)
{
	if(j>0)
	{
		cout<<result[j]<<" ";
		print_denom(result,j-result[j]);
	}
}

int min_coins(int denom[],int num_of_coins,int cap)
{
	if(cap<0)return -1;
	if(cap==1)return 1;
	int table[cap];
	vector<int> final;
	table[0]=0;
	table[1]=1;
	int result[cap];
	result[0]=0;
	result[1]=1;
	for(int i=0;i<cap;i++)result[i]=0;
	
	int temp=INT_MAX;
	for(int i=2;i<=cap;i++)
	{
		for(int j=0;j<num_of_coins;j++)
		{
			if(i-denom[j]>=0)
			{
				temp=minimum(temp,table[i-denom[j]]);
				if(temp==table[i-denom[j]])
				{
						result[i]=denom[j];
				}
			}
		}
		table[i]=temp+1;
		temp=INT_MAX;
	}
	//print_denom(result,cap);
	cout<<endl;
	return table[cap];
}


int main()
{
	int cap;
	cin>>cap;
	int denom[]={25,10,5,1};
cout<<min_coins(denom,4,cap);
	cout<<endl;
	return 0;
}
