#include<iostream>
#include<stdlib.h>
#include<list>
using namespace std;
int get_max_in_window(int a[],int b[],int n,int w)
{
 	list<int> queue;	
	for(int i=0;i<w;i++)
	{
		while(!queue.empty()  && a[i]>=a[queue.back()])
		{	
	 		  queue.pop_back();
		}
		queue.push_back(i);
	}  
	
	for(int i=w;i<n;i++)
	{
	 	b[i-w]=a[queue.front()];
		while(!queue.empty()  && a[i]>=a[queue.back()])
		{
			queue.pop_back();
		}	
	 	while(!queue.empty() && queue.front()<=(i-w))
		{
	 		queue.pop_front();
	 	}
		queue.push_back(i);
	}
	b[n-w]=a[queue.front()];
	return 1;
}

int main()
{
	int n;
	cout<<"\nEnter n: ";
	cin>>n;
	int a[n];
	cout<<"\nEnter array: ";
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}
	int w;
	cout<<"\nEnter window: ";
	cin>>w;
	if(w>n)
	{
		cout<<"Not possible ";
		return 0;
	}
	int b[n-w];
	if(get_max_in_window(a,b,n,w))
	{
		cout<<"\nMax array: ";
		for(int i=0;i<=(n-w);i++)
		{
			cout<<b[i]<<"   ";
		}
	}
	return 0;
}
