#include <bits/stdc++.h>
using namespace std;
struct node
{
    int data;
    struct node* left;
    struct node* right;
    node(int x):data(x),left(NULL),right(NULL){};
};
int convert(struct node* root)
{
    if(root==NULL)return 0;
    if(root->left==NULL && root->right==NULL)
    {
        int temp = root->data;
        root->data=0;
        return temp;
    }
    int l = convert(root->left);
    int r = convert(root->right);
    int temp = root->data;
    root->data = l+r;
    return temp+root->data;
}
void print(struct node* root)
{
    if(root)
    {
        print(root->left);
        printf("%d\t",root->data);
        print(root->right);
    }
}
int main()
{
    struct node* root = new node(10);
    root->left = new node(-2);
    root->right = new node(6);
    root->left->left = new node(8);
    root->left->right = new node(-4);
    root->right->left = new node(7);
    root->right->right = new node(5);
    convert(root);
    print(root);
    return 0;
}
