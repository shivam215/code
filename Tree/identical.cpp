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
int identical(struct node* t1, struct node* t2)
{
    if(t1==NULL && t2==NULL)
        return 1;
    else if(t1==NULL && t2!=NULL)
        return 0;
    else if(t1!=NULL && t2==NULL)
        return 0;
    else
    {
        return(identical(t1->left,t2->left) && identical(t1->right,t2->right) && (t1->data==t2->data));
    }
}
int main()
{
    struct node* root1 = newnode(1);
    struct node* root2 = newnode(1);
    root1->left = newnode(3);
    root1->right =  newnode(4);
    root2->left = newnode(3);
    root2->right = newnode(4);
    root2->left->right = newnode(1);
    cout<<identical(root1,root2);
    return(0);
}
