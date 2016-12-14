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
int diameter(struct node* root, int* height)
{
    if(root==NULL)
    {
        *height = -1;
        return 0;
    }
    if(root->left==NULL && root->right==NULL)
    {
        *height = 0;
        return 1;
    }
    int lh,rh;
    int ldiameter,rdiameter;
    ldiameter = diameter(root->left,&lh);
    rdiameter = diameter(root->right,&rh);
    *height = max(lh,rh)+1;
    return(max(lh+rh+3,max(ldiameter,rdiameter)));

}
int main()
{   int height;
    struct node* root = newnode(1);
    root->left = newnode(2);
    root->right = newnode(3);
    root->left->left = newnode(4);
    root->left->right = newnode(5);
    root->left->right->left = newnode(6);
    root->left->right->right = newnode(7);
    root->right->right = newnode(8);
    root->right->right->right = newnode(9);
    root->right->right->right->left = newnode(10);
    root->right->right->right->right = newnode(11);
    root->right->right->right->left->left = newnode(12);
    root->right->right->right->left->right = newnode(13);
    cout<<diameter(root,&height);
    cout<<height;
    return(0);


}
