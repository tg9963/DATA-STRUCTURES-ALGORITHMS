#include<iostream> 
#include<math.h>
using namespace std;

void print_in_order(int arr[],int n,int k,int part_indexes[])
{
	int i=0;
  
	while(i<(k+1))
	{ 
	int now=(part_indexes[i]-1)*k;
	int end=now+k;
	while(now<end && now<n)
	{
		cout<<arr[now++]<<"  ";
	}
	i++;
	}
	
}

int main()
{
	int n;
	cout<<"N: ";
	cin>>n;
	
	int arr[n];
	for(int i=0;i<n;i++)
	cin>>arr[i];
	int k;
	cout<<"\npartition size: \n";
	cin>>k;
	if(k>n)return 0;
	int part_indexes[k];
	int size=(int)(ceil(n/k));
	int temp;
	for(int i=0;i<size+1;i++)
	{
		cin>>temp;	
		part_indexes[i]=temp;
	}
	
	cout<<endl;
	print_in_order(arr,n,k,part_indexes);
	return 0;
}
