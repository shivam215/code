#include <bits/stdc++.h>
using namespace std;
int k;
struct node
{
    int data;
    struct node* left;
    struct node* right;
    node(int d)
    {
        data = d;
        left=NULL;
        right = NULL;
    }
};
void findkth(struct node* root,int& coun)
{
    if(root==NULL)return;
    findkth(root->left,coun);
    coun++;
    if(coun==k)
    {
        printf("%d",root->data);
    }
    findkth(root->right,coun);
}
int main()
{
    struct node* root = new node(5);
    root->left = new node(6);
    root->right = new node(7);
    root->left->left = new node(8);
    root->left->right = new node(9);
    int coun=0;
    cin>>k;
    findkth(root,coun);
    return 0;


}
