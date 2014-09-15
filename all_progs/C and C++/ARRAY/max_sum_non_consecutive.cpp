#include<iostream>
#include<stdlib.h>
using namespace std;

int find_max_sum(int arr1[],int n)
{
	int t=8*n;
	
	int arr[t];
	for(int i=0;i<t;i++)
	{
		arr[i]=arr1[i%n];
	}
	int i=arr[0];
	int e=0;
	int e_new;
	for(int j=1;j<t;j++)
	{
		e_new=(i>e)?i:e;
		
		i=e+arr[j];
		e=e_new;
	}
	i=(i>e)?i:e;
	return (i/8);
}


int main()
{
	int arr[]={13,5,-1,4,-3,6};
	int n=6;
	cout<<find_max_sum(arr,n);
}

/*

if (a.length == 1) 
return a[0];
if (a.length == 2) 
return max(a[0], a[1]);

int secondLast = a[0];
int last = max(secondLast, a[1]);
int current = last;

for (int i = 2; i < a.length; i++) {
current = max(a[i], max(secondLast + a[i], last));
secondLast = last;
last = current; 
}
return current;
}
*/

/*

int FindMaxSum(int arr[],int sum, int n)
{
  if(n>size-1) return sum;
  //cout<<sum<<"\n";
   return max(FindMaxSum(arr, sum+arr[n], n+2) , FindMaxSum(arr, sum, n+1));
}
*/
