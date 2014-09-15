#include <iostream>
#include<stdlib.h>
#include<math.h>
using namespace std;


int main() {
	// your code goes here
	
	long long n;
	cin>>n;
	for(long long i=0;i<n;i++)
	{
		long long x,y,x1,y1,x2,y2,a,b,c,d,e,f,g,h;
		cin>>x>>y>>x1>>y1>>x2>>y2;
		a=abs(x-x1),b=abs(x-x2),c=abs(y-y1),d=abs(y-y2);
		long long x3,x4,y3,y4;
		x3=x1;
		y3=y2;
		x4=x2;
		y4=y1;
		e=abs(x-x3);
		f=abs(x-x4);
		g=abs(y-y3);
		h=abs(y-y4);
		
		long long d1=sqrt(pow(a,2)+pow(c,2));
		long long min=d1;
		long d2=sqrt(pow(b,2)+pow(d,2));
		if(d2<min)
		{
			min=d2;
		}
		long d3=sqrt(pow(e,2)+pow(g,2));
		if(d3<min)
		{
			min=d3;
		}
		long d4=sqrt(pow(f,2)+pow(h,2));
		if(d4<min)
		{
			min=d4;
		}
		cout<<min<<endl;
	}
	
	return 0;
}
