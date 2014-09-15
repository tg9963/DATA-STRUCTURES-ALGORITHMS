#include<iostream>
#include<stdlib.h>
using namespace std;
int flag=1;
int kadane (int a[], int n)
{
    int max_so_far = 0, max_ending_here = 0;
    int i;
    for(i = 0; i < n; i++)
    {
        max_ending_here = max_ending_here + a[i];
        if(max_ending_here < 0)
           {
           	max_ending_here = 0;
           	flag=0;
           } 
        if(max_so_far < max_ending_here)
            max_so_far = max_ending_here;
    }
    return max_so_far;
}

int find_max_sum(int arr1[],int n)
{
	int arr[n+1];
	for(int i=0;i<n+1;i++)
	{
		arr[i]=arr1[i];
	}
	arr[n]=arr1[0];
	int max1=kadane(arr1,n);
	int max2=kadane(arr,n+1);
	if(!flag && max1<max2)max1=max2;
	return max1;
}


int main()
{
	int arr[]={ 11, 10, -20, 5, -3, -5, 8, -13, 10};
	int n=sizeof(arr)/sizeof(arr[0]);
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
