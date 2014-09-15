#include<iostream>
#include<math.h>
#include<algorithm>
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

int main()
{
	int n;
	cin>>n;
	struct node arr[n];
	for(int i=0;i<n;i++)
	cin>>arr[i].data;
	
	for(int i=0;i<n;i++)
	{
		float a=sqrt(arr[i].data);
		int b=a;
		
		if(b-a==0)
		{
			arr[i].weight=5;
		}
		else if(arr[i].data%4==0 && arr[i].data%6==0)
		{
			arr[i].weight=4;
		}
		else if(arr[i].data%2==0)
		{
			arr[i].weight=3;
		}
		else
		{
			arr[i].weight=-1;
		}
	}
	qsort(arr,n,sizeof(struct node),comp);
	//sorts(arr,n);
	for(int i=0;i<n;i++)
	{
		if(arr[i].weight!=-1)
		{
			cout<<"<"<<arr[i].data<<","<<arr[i].weight<<">"<<endl;
		}
		
	}
}
