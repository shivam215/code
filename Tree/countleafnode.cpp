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
int countLeafNode(struct node* root)
{
    if(root==NULL)
        return 0;
    if(root->left==NULL && root->right==NULL)
    {
        return 1;
    }
    int x=0,y=0;

    if(root->left)
        x = countLeafNode(root->left);
    if(root->right)
        y = countLeafNode(root->right);
    return(x+y);
}
int main()
{
    struct node* root = newnode(1);
    cout<<countLeafNode(root);
    return(0);


}
