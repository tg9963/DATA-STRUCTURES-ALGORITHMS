#include<iostream>
#include<stdlib.h>
using namespace std;

long int maxi(int a,int b)
    {
    return (a>b?a:b);
}

int util(int arr[],int n,int start)
    {
    if(start>=n)return 0;
    int max_sum=0;
    max_sum=maxi(arr[start]+util(arr,n,start+1),util(arr,n,start+2),)
    return max_sum;
}

long int find_max(long int arr[],long int n)
    { 
    cout<<util(arr,n,0);
}

int main()
    {
    int test;
    cin>>test;
    while(test--)
        {
        long int n;
        cin>>n;
        long int arr[n];
        for(long int i=0;i<n;i++)
            {
            cin>>arr[i];
        }
        cout<<find_max(arr,n)<<endl;
    }
    return 0;
}
