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
void mirror(struct node* root)
{
    if(root == NULL)
        return;
    mirror(root->left);
    mirror(root->right);
    struct node* temp = root->left;
    root->left = root->right;
    root->right = temp;

}
void inorder(struct node* root)
{
    if(root==NULL)
        return;
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);

}
int main()
{
    struct node* root = newnode(1);
    root->left = newnode(2);
    root->right = newnode(3);
    root->left->left = newnode(4);
    root->left->right = newnode(5);
    inorder(root);
    mirror(root);
    cout<<endl;
    inorder(root);
    return(0);

}
