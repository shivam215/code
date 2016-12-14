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
int height(struct node* root)
{
    if(root==NULL)
        return -1;
    return max(height(root->left),height(root->right))+1;

};
void printLevel(struct node* root, int level, bool itr)
{
    if(root==NULL)
        return;
    if(level==1)
        cout<<root->data;
    else
    {
        if(itr==0)
        {
            printLevel(root->left,level-1,itr);
            printLevel(root->right,level-1,itr);
        }
        else
        {
            printLevel(root->right,level-1,itr);
            printLevel(root->left,level-1,itr);
        }
    }

}
void printspiral(struct node* root)
{
    int i;
    for(i=1;i<=(height(root)+1);i++)
    {
        printLevel(root,i,i&1);

    }
}
int main()
{
    struct node* root = newnode(1);
    root->left = newnode(2);
    root->right = newnode(3);
    root->left->left = newnode(7);
    root->left->right = newnode(6);
    root->right->left = newnode(5);
    root->right->right = newnode(4);
    printspiral(root);
    return(0);

}
