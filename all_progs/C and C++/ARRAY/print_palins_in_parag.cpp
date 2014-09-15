#include<iostream>
#include<string.h>
#include<vector>
#include<algorithm>
using namespace std;

void print_strings(vector<string> inp)
{
	for(vector<string>::iterator it=inp.begin();it!=inp.end();it++)
	{
		cout<<*it<<endl;
	}
}

void print_util(vector<string> inp,int count)
{
	vector<string>::iterator it;
	for(it=inp.begin();it!=inp.end();it++)
	{
		for(vector<string>::iterator jt=it+1;jt!=inp.end();jt++)
		{
			if(*it==*jt)
			{
				jt=inp.erase(jt);
			}
		}
	}
	vector<string> copy_string(inp.begin(),inp.end());
	inp.erase(inp.begin(),inp.end());
	for(it=copy_string.begin();it!=copy_string.end();it++)
	{
		 string temp=*it;
		 sort(temp.begin(),temp.end());
		 inp.push_back(temp);
	}
	int i=0,j=0;
	print_strings(inp);
	
	
	for(it=inp.begin();it!=inp.end();it++)
	{
		i++;
		int flag=0;
		for(vector<string>::iterator jt=it+1;jt!=inp.end();jt++)
		{
			j++;
			if(*it==*jt)
			{
				if(flag==1)
				{
					cout<<copy_string[j]<<" ";
				}
				else
				{
					cout<<"\n"<<copy_string[i]<<" "<<copy_string[j]<<" ";
					flag=1;
				}
			}
		}
	}
	
}


void print_palins(string s)
{
	vector<string> inp;
	string temp="";
	int count=0;
	for(int i=0;i<s.size();i++)
	{
		if(s[i]==' ')
		{
			inp.push_back(temp);
			count++;
			temp="";
		}
		else
		{
			temp+=s[i];
		}
	}
	inp.push_back(temp);
	print_util(inp,count++);
}

int main()
{
	string s;
	getline(cin,s);
	print_palins(s);
	return 0;
}
