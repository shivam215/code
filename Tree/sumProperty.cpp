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
int checkProperty(struct node* root)
{
    if(root==NULL || (root->left==NULL&&root->right==NULL))
        return 1;
    int left_data=0,right_data=0;
    if(root->left!=NULL)
        left_data = root->left->data;
    if(root->right!=NULL)
        right_data = root->right->data;
    return((root->data==left_data+right_data)&&(checkProperty(root->left))&&(checkProperty(root->right)));
}
int main()
{
    struct node* root = newnode(10);
    root->left = newnode(8);
    root->right = newnode(2);
    root->left->left = newnode(3);
    root->left->right = newnode(5);
    root->right->left = newnode(1);
    cout<<checkProperty(root);
    return(0);


}
