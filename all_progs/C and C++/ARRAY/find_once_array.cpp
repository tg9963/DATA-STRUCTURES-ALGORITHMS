#include<iostream>
#include<vector>
using namespace std;
int find_once(vector<int> a)
{
	int i=0;
	//int temp=0;
	int ones=0,twos=0;
	int common=0;
	for(i=0;i<a.size();i++)
	{
		 	twos=twos|(ones & a[i]);
		 	ones=ones^a[i];
		 	common=~(ones & twos);
		 	ones &=common;
		 	twos &=common;
		 	cout<<"ones"<<" i "<<i<<" : "<<ones<<endl;
		 	cout<<"twos"<<" i "<<i<<" : "<<twos<<endl;
	}
	return ones;
}
int main()
{
	vector<int> a;
	a.push_back(13);
	a.push_back(13);
	a.push_back(12);
	a.push_back(13);
	a.push_back(14);
	a.push_back(14);
	a.push_back(13);

	cout<<find_once(a);
	return 0;
}
