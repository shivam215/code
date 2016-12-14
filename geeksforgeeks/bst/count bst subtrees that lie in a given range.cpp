#include <bits/stdc++.h>
using namespace std;
int a,b;
struct node
{
    int data;
    struct node* left;
    struct node* right;
    node(int d)
    {
        data = d;
        left=NULL;
        right = NULL;
    }
};
int countbst(struct node* root,int& mn, int& mx)
{
    if(root==NULL)
    {
        return 0;
    }
    int x=INT_MAX,y=INT_MIN,temp;
    int left = countbst(root->left,x,temp);
    int right = countbst(root->right,temp,y);
    mn = min(x,root->data);
    mx = max(y,root->data);
    if(mn>=a && mx<=b)return 1+left+right;
    else return left+right;
}
int main()
{
    struct node* root = new node(10);
    root->left = new node(5);
    root->right = new node(50);
    root->left->left = new node(1);
    root->right->left = new node(40);
    root->right->right = new node(100);
    cin>>a>>b;
    int mn,mx;
    cout<<countbst(root,mn,mx);
    return 0;


}

