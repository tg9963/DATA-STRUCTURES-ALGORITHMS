#include<iostream>
#include<vector>

using namespace std;

int main()
{
	int n;
	cin>>n;
	int big_table[n][1440];
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<1440;j++)
		{
			big_table[i][j]=0;
		}
	}
	
	vector<string> inp[n];
	int src;
	cin>>src;
	while(src!=-1)
	{
		string s;
		cin>>s;
		char h1=s[0];
		char h2=s[1];
		int h_1=h1-48;
		int h_2=h2-48;
		int res_h1=(h_1)*10+h_2;
		h1=s[3];
		h2=s[4];
		h_1=h1-48;
		h_2=h2-48;
		int res_m1=(h_1)*10+h_2;
		cin>>s;
		h1=s[0];
		h2=s[1];
		h_1=h1-48;
		h_2=h2-48;
		int res_h2=(h_1)*10+h_2;
		h1=s[3];
		h2=s[4];
		h_1=h1-48;
		h_2=h2-48;
		int res_m2=(h_1)*10+h_2;
		int first_index=res_h1*60+res_m1;
		int last_index=res_h2*60+res_m2;
		for(int i=first_index;i<last_index;i++)
		{
			big_table[src][i]=1;
		}
		inp[src].push_back(s);
		cin>>src;
	}
	int max_count_temp=0;
	int min_count_temp=0;
	int total_max_free=0;
	string max_free_in_all_leaders;
	int start_free_max=0,end_free_max=0;
	for(int i=0;i<n;i++)
	{
		int flag=0;
		for(int j=0;j<1440;j++)
		{
			if(big_table[i][j]==1)
			{
				if(flag==0)
				{
					start_free_max=j;
					flag=1;
				}	
				max_count_temp++;
				min_count_temp=0;
			}
			else
			{
				end_free_max=j;
				if(total_max_free<max_count_temp)
				{
					total_max_free=max_count_temp;
				}
				flag=0;
				max_count_temp=0;
				min_count_temp++;
			}
		}
	}
	int hour1=start_free_max/60;
	int mins1=start_free_max%60;
	cout<<hour1<<":"<<mins1<<" ";
	hour1=end_free_max/60;
	mins1=end_free_max%60;
	cout<<hour1<<":"<<mins1<<" ";
	cout<<endl;
	return 0;
}
