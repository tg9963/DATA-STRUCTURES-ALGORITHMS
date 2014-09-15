#include<iostream>
using namespace std;
int main()
{
	int *p;
	int a=5;
	p=&a;
	cout<<++*p++;
	return 0;
}
