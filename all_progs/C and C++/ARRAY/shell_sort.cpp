#include<iostream>

using namespace std;

void shell_sort(int arr[],int n)
{
	int h=0;
	int k,temp,j;
	for(h=0;h<n;h=3*h+1)
	{
		for(;h>=0;h=h/3)
		{
			for(int i=h+1;i<n;i++)
			{
				//cout<<i<<" ";
				temp=arr[i];
				j=i;
				while(j>=h && arr[j-h]>temp)
				{
					arr[j]=arr[j-h];
					j -=h;
				}	
				arr[j]=temp;
			}
		}
	}
}

int main()
{
	int arr[]={1,9,6,2,5,3};
	int n=6;
	shell_sort(arr,n);
	for(int i=0;i<n;i++)cout<<arr[i]<<"  ";
	return 0;
}
