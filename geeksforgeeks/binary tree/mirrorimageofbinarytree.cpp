#include <bits/stdc++.h>
using namespace std;
struct node
{
    int data;
    struct node* left;
    struct node* right;
    node(int d)
    {
        data=d;
        left=NULL;
        right=NULL;
    }
};
struct node* f(struct node* root)
{
    if(root==NULL)return NULL;
    struct node* temp =new node(root->data);
    temp->left = f(root->right);
    temp->right = f(root->left);
    return temp;
};
void print(struct node* root)
{
    if(root==NULL)return;
    printf("%d\t",root->data);
    print(root->left);
    print(root->right);
}
int main()
{
    struct node* root = new node(1);
    root->left = new node(2);
    root->right = new node(3);
    root->left->left = new node(4);
    root->left->right = new node(5);
    root->right->left = new node(6);
    root->right->right = new node(7);
    struct node* temp = f(root);
    print(temp);
    return 0;


}
