#include <bits/stdc++.h>
using namespace std;
struct node
{
    int data;
    struct node* left;
    struct node* right;
    node(int x):data(x),left(NULL),right(NULL){};
};
int check(struct node* root)
{
    queue<struct node*> q;
    q.push(root);
    int flag=0;
    while(!q.empty())
    {
        struct node* temp = q.front();
        q.pop();
        if(temp->left)
        {
            if(flag)return 0;
            q.push(temp->left);
        }
        else flag=1;
        if(temp->right)
        {
            if(flag)return 0;
            q.push(temp->right);
        }
        else flag=1;
    }
    return 1;
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
    cout<<check(root)<<endl;
    return 0;
}
