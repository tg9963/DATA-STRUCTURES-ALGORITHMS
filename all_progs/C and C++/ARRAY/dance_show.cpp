#include<iostream>
#include<stdlib.h>
#include<vector>
using namespace std;

struct tree
{
	int data;
	struct tree* left;
	struct tree* right;
	int height;	
};

struct tree* newnode(int data)
{
	struct tree* node=(struct tree*)malloc(sizeof(struct tree));
	node->data=data;
	node->left=NULL;
	node->right=NULL;
	node->height=1;
	return node;
}
struct tree* find_max(struct tree* root)
{
	//cout<<"root: "<<root->data;
	while(root && root->right)
		root=root->right;
	return root;
}
int height(struct tree* root)
{
	if(root==NULL)return 0;
	return root->height;
}
int get_balance(struct tree* root)
{
	if(root==NULL)return 0;
	
	return (height(root->left)-height(root->right));
}


int getbalance(struct tree* root)
{
	if(root==NULL)return 0;
	return (height(root->left) - height(root->right));
}
int maxi(int a,int b)
{
	if(a>b)return a;
	return b;
}
struct tree* rightrotate(struct tree* root)
{
	struct tree* x=root->left;
	struct tree* y=x->right;
	
	x->right=root;
	root->left=y;
	root->height=maxi(height(root->left),height(root->right))+1;
	
	x->height=maxi(height(x->left),height(x->right))+1;
	return x;
}

struct tree* leftrotate(struct tree* root)
{
	struct tree* x=root->right;
	struct tree* y=x->left;
	x->left=root;
	root->right=y;	
	root->height=maxi(height(root->left),height(root->right))+1;
	x->height=maxi(height(x->left),height(x->right))+1; 
	return x;
	
}
struct tree* insert_into_AVL(struct tree* root,int data)
{
	if(root==NULL)
	{
		return newnode(data);
	}
	
	if(root->data<=data)
		root->right=insert_into_AVL(root->right,data);
	
	if(root->data>data)
		root->left=insert_into_AVL(root->left,data);
		
	root->height=maxi(height(root->left),height(root->right))+1;
	int balance=getbalance(root);
	
	if(balance >1 && data<root->left->data)
	{
		//left left
		return rightrotate(root);
	}
	
	if(balance <-1 && data>=root->right->data)
	{
		//right right
		return leftrotate(root);
	}
	
	if(balance >1 && data<root->left->data )
	{
		//left right
		root->left=leftrotate(root->left);
		return rightrotate(root);
	}
	
	if(balance <-1 && data>=root->right->data)
	{
		//right right
		root->right=rightrotate(root->right);
		return leftrotate(root);
	}
	
	return root;
}
struct tree* construct(vector<int> a,int size)
{
	struct tree* root=NULL;
	for(int i=0;i<size;i++)
	{
		//cout<<i<<" \n";
		root=insert_into_AVL(root,a[i]); 
	}
	return root;
}
struct tree* delete_element(struct tree* root,int data)
{
	struct tree* max_left;
	if(root==NULL)
		return NULL;
	
	if(root->data==data)
	{
		if(root->left && root->right)
		{
			max_left=find_max(root->left);
			root->data=max_left->data;
			root->left=delete_element(root->left,root->data);
		}
		else
		{
			max_left=root;
			if(root->left==NULL)
				root=root->right;
			else if(root->right==NULL)
				root=root->left;
			free(max_left);
		}
	}
	else
	{
		if(root->data>data)
			root->left=delete_element(root->left,data);
		if(root->data<=data)
			root->right=delete_element(root->right,data);
	}
	if(root==NULL)return NULL;
	root->height=max(height(root->left),height(root->right))+1;
	int balance=get_balance(root);
	
	if(balance>1 && get_balance(root->left)>=0)
		return rightrotate(root);
	if(balance<-1 && get_balance(root->right)<=0)
			return leftrotate(root);
	if(balance>1 && get_balance(root->left)<0)
	{
		root->left=leftrotate(root->left);
		return rightrotate(root);
	}
	if(balance <-1 && get_balance(root->right)>0)
	{
		root->right=rightrotate(root->right);
		return leftrotate(root);
	}

	return root;
}
int max(int a,int b)
{
	return (a>b?a:b);
}
int get_number(struct tree* root)
{
	if(root==NULL)return 0;
	if(root->left==NULL && root->right==NULL)return 0;
	int right=0,left=0;
	if(root->right)
	{
		right=get_number(root->right);
	}
	if(root->left)
	{
		left=get_number(root->left);
	}
	return max(right,left)+1;
}

int get_max_right(struct tree* root,int data)
{
	if(root==NULL)return 0;
	if(root->data==data)
	{
		return get_number(root);
	}
	return maxi(get_max_right(root->left,data),get_max_right(root->right,data));	
}
void print_tree(struct tree* root)
{
	if(root)
	{
		print_tree(root->left);
		cout<<root->data<<"    ";
		print_tree(root->right);
	}
}
int main()
{
	int test_cases;
	cin>>test_cases;
	for(int j=0;j<test_cases;j++)
	{
	int temp,n;
	int count=INT_MIN,max_count=INT_MIN;
	cin>>n;
	vector<int> a;
	for(int i=0;i<n;i++)
	{
		cin>>temp;
		a.push_back(temp);
	}
	struct tree* root=construct(a,n);
	 print_tree(root);
	 cout<<endl;
	 for(int k=0;k<n;k++)
	{
		count= get_max_right(root,a[k]);
		cout<<count<<endl;
		if(max_count<count)count=max_count;
		delete_element(root,a[k]);	
	}
	cout<<max_count<<endl;
	}
}
