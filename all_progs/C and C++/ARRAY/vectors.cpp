#include<algorithm>
#include<iostream>
#include<vector>
using namespace std;
vector<float> bucketsort(vector<float> a)
{
	int temp;
	int n=a.size();
	vector<float> b[n];
	for(int i=0;i<n;i++)
	{
		temp=n*a.at(i);
		b[temp].push_back(a.at(i));
	}
	for(int i=0;i<n;i++)sort(b[i].begin(),b[i].end());
	int count=0;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<b[i].size();j++)
		{
			if(b[i].at(j)!=0)a.at(count++)=b[i].at(j);
		}
	} 
	return a;
}
int main()
{
	int n;
	cin>>n;
	float temp;
	vector<float> a;
	for(int i=0;i<n;i++)
	{
	cin>>temp;
	a.push_back(temp);
	} 
	a=bucketsort(a);
for(int i=0;i<n;i++)
	{
cout<<a[i]<<" 	";
	} 
	return 0;
}
