#include<iostream>
using namespace std;

int maximum(int a, int b)
{
	return (a>b?a:b);
}

 
int find_max_sum(int arr[],int n)
{
	 int inc=arr[0];
	 int exc=0;
	 int exc_new;
	 for(int i=1;i<n;i++)
	 {
	 	exc_new=maximum(inc,exc);
	 	inc=exc+arr[i];
	 	exc=exc_new;
	 }
	 return maximum(inc,exc);
}


int main()
{
	int arr[]={3,2,7,10};
	int n=4; 
	cout<<find_max_sum(arr,n);
	return 0;
}
