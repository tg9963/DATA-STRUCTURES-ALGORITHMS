#include<iostream>

using namespace std;

struct node
{
	int data;
	int weight;
};

void sorts(struct node a[],int n)
{
	for(int i=0;i<n;i++)
	{
		for(int j=i;j<n;j++)
		{
			if(a[i].weight>a[j].weight)
			{
				struct node temp=a[i];
				a[i]=a[j];
				a[j]=temp;
			}
		}
	}
}

int comp(const void* a,const void* b)
{
	int a_w=((struct node*)a)->weight;
	int b_w=((struct node*)b)->weight;
	return (a_w-b_w);
}

int get_min(struct node combo[],int x,int total)
{
	int curr=0;
	int total_cost=0;
	int temp_cost=0;
	for(int i=x-1;i>=0;i--)
	{
		if(combo[i].data>total)continue ;
		int temp_curr=combo[i].data;
		do
		{
			total_cost+=combo[i].weight;
			temp_curr+=combo[i].data;
		}while(temp_curr<=total);
		if(temp_curr==total)
		{
			return total_cost;
		}
		temp_curr-=combo[i].data;
		total-=temp_curr;
	}
	return total_cost;
}

int main()
{
	int test;
	cin>>test;
	while(test--)
	{
		int x,n;
		cin>>x>>n;
		struct node combo[x];
		int def=0;
		for(int i=0;i<x;i++)
		{
			cin>>combo[i].data;
			if(combo[i].data==1)
			{
				def=i;
			}
		}
		
		for(int i=0;i<x;i++)
		{
			cin>>combo[i].weight;
		}
		int total=0;
		int actual=0;
		for(int i=0;i<n;i++)
		{
			int temp;
			cin>>temp;
			total+=temp;
		}
		
		sorts(combo,x); 
		int remain=total/combo[0].data;
		actual=remain*combo[0].weight;
		int mini=get_min(combo,x,total);
		cout<<(actual-mini)<<endl;
	}
	return 0;
}
