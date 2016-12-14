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
    return(node);
};
void printInorder(struct node* root)
{
    if(root==NULL)
        return;
    printInorder(root->left);
    cout<<root->data<<'\t';
    printInorder(root->right);
}
void printPostorder(struct node* root)
{
    if(root==NULL)
        return;
    printPostorder(root->left);
    printPostorder(root->right);
    cout<<root->data<<'\t';
}
void printPreorder(struct node* root)
{
    if(root==NULL)
        return;
    cout<<root->data<<'\t';
    printPreorder(root->left);
    printPreorder(root->right);

}
int main()
{
    struct node* root = newnode(1);
    root->left = newnode(2);
    root->right = newnode(3);
    root->left->left = newnode(4);
    root->left->right = newnode(5);
    printInorder(root);
    cout<<endl;
    printPreorder(root);
    cout<<endl;
    printPostorder(root);
    return(0);

}
