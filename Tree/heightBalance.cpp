#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(false);cin.tie(0);
using namespace std;
struct node
{
    int data;
    struct node* left;
    struct node* right;
};
struct node* newnode(int data)
{
    struct node* node = (struct node*)malloc(sizeof(struct node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return node;
};
int heightBalance(struct node* root, int* height)
{
    if(root==NULL)
    {
        *height = -1;
        return 1;
    }
    int l_tree,r_tree;
    int lh,rh;
    l_tree = heightBalance(root->left,&lh);
    r_tree = heightBalance(root->right,&rh);
    *height = max(lh,rh)+1;
    int diff = lh-rh;
    return(l_tree&&r_tree&&(abs(diff)<=1));
}
int main()
{   int height;
    struct node* root = newnode(1);
    root->left = newnode(2);
    root->right = newnode(3);
    root->left->left = newnode(4);
    root->left->right = newnode(5);
    root->left->right->left = newnode(6);
    root->left->right->left->left = newnode(9);
    root->right->right = newnode(7);
    cout<<heightBalance(root,&height)<<endl;
    cout<<height;
}
