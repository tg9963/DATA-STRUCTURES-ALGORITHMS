#include<iostream>
#include<stdlib.h>
#define M 6
#define N 6
using namespace std;

int bpm(int biper[M][N],int u,bool seen[N],int match[N])
{
	for(int i=0;i<N;i++)
	{
		if(biper[u][i] && !seen[i])
		{
			seen[i]=true;
			if(match[i]<0 || bpm(biper,match[i],seen,match))
			{
				match[i]=u;
				return true;
			}
		}
	}
	return false;
}

int get_max(int biper[M][N])
{
	int result=0;
	int match[N];
	for(int j=0;j<N;j++)match[j]=-1;
	for(int i=0;i<M;i++)
	{
		bool seen[N];
		for(int j=0;j<N;j++)seen[j]=false;
		if(bpm(biper,i,seen,match))result++;
	}
	return result;
}

int main()
{
	int biper[M][N]={
						{0, 1, 1, 0, 0, 0},
                        {1, 0, 0, 1, 0, 0},
                        {0, 0, 1, 0, 0, 0},
                        {0, 0, 1, 1, 0, 0},
                        {0, 0, 0, 0, 0, 0},
                        {0, 0, 0, 0, 0, 1}
				 };
				 
	cout<<"Max Number of elmployes get gob "<<get_max(biper);
}
