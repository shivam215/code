#include<iostream>

using namespace std;

struct node
{
	int val;
	node *left,*right;
	node(int val)
	{
		this->val=val;
		left=right=NULL;
	}
};

void print(node *root,int l,int r)
{
	if(l||(!r&&root->left==NULL&&root->right==NULL))
	cout<<root->val<<' ';

	if(root->left!=NULL)	print(root->left,l,0);
	if(root->right!=NULL)	print(root->right,0,r);

	if(!l&&r)
	cout<<root->val<<' ';
}

int main()
{
	struct node *root		 = new node(20);

	root->right			 = new node(22);
	root->right->left = new node(24);
	root->right->left->left = new node(4);
	root->right->right	 = new node(25);

	print(root,1,1);
	cout<<endl;

	return 0;
}
