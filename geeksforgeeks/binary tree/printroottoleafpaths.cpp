#include <bits/stdc++.h>
using namespace std;
int path[100];
struct node
{
    int data;
    struct node* left;
    struct node* right;
    node(int x):data(x),left(NULL),right(NULL){};
};
void print(struct node* root,int pathlen)
{
    if(root==NULL)return;
    if(root->left==NULL&&root->right==NULL)
    {
        path[pathlen] = root->data;
        for(int i=0;i<=pathlen;i++)
        {
            cout<<path[i]<<' ';
        }
        cout<<endl;
        return;
    }
    path[pathlen] = root->data;
    print(root->left,pathlen+1);
    print(root->right,pathlen+1);
}
int main()
{
    struct node* root = new node(4);
    root->left = new node(5);
    root->right = new node(6);
    root->left->left = new node(7);
    root->left->right = new node(8);
    root->right->left = new node(9);
    root->right->right = new node(10);
    print(root,0);
    return 0;
}
