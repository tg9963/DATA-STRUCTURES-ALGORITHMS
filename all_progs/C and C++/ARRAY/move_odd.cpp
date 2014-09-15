#include<iostream>
#include<stdlib.h>
using namespace std;

void change2(int ar[],int n)
{
int i,next=0;
for(i=0;i<n;i++)
{
  if(ar[i]%2==1)ar[next++]=ar[i];
  if(i>=next)ar[i]=0;
}
}

int main()
{
	int arr[]={2,2,1,1,5,6};
	int n=6;
	change2(arr,n);
	for(int i=0;i<n;i++)cout<<arr[i]<<" ";
	return 0;
}
