#include<iostream>
using namespace std;
int get_k_element(int arr[][4],int k)
{
	int temp=k;
	int element;
	int i=0,j=3;
	while(temp)
	{
		while(i!=4 && j>=0)
		{
			if(arr[i]>)
		}
		temp--;
		if(temp==0)
		{
			cout<<"Kth smallest"element;
		}
	}
}
int main()
{
	int arr[][]={ {1,2,3,4},
				  {5,6,7,8},
				  {9,10,11,12},
				  {13,14,15,16} };
	int k;
	cout<<"Enter K";
	cin<<k;
	k=get_k_element(arr,k);
	cout<<k;
	return 0;
}
