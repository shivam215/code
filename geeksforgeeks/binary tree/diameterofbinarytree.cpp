#include <bits/stdc++.h>
using namespace std;
struct node
{
    int data;
    struct node* left;
    struct node* right;
    node(int x):data(x),left(NULL),right(NULL){};
};
int diameter(struct node* root,int *height)
{
    if(root==NULL)
    {
        *height=0;
        return 0;
    }
    int lh,rh,ld,rd;
    ld = diameter(root->left,&lh);
    rd = diameter(root->right,&rh);
    *height = max(lh,rh)+1;
    return max(ld,max(rd,lh+rh+1));
}
int main()
{
    int h;
    struct node* root = new node(4);
    root->left = new node(5);
    root->right = new node(6);
    root->left->left = new node(7);
    root->left->right = new node(8);
    root->right->left = new node(9);
    root->right->right = new node(10);
    cout<<diameter(root,&h)<<endl;
    return 0;
}
