#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(false);cin.tie(0);
using namespace std;
struct node
{
    int data;
    struct node* left;
    struct node* right;
};
int search(int* in, int l, int h, int key)
{
    int i;
    for(i=l;i<=h;i++)
    {
        if(in[i]==key)
            return(i);
    }
}
struct node* buildTree(int* pre, int* in, int l, int h)
{
    if(l>h)
        return NULL;
    static int i=0;
    int index;
    index = search(in,l,h,pre[i++]);
    struct node* tnode = (struct node*)malloc(sizeof(struct node));
    tnode->data = in[index];
    tnode->left = buildTree(pre,in,l,index-1);
    tnode->right = buildTree(pre,in,index+1,h);
    return tnode;


};
void preorder(struct node* root)
{
    if(root==NULL)
        return;
    preorder(root->left);
    preorder(root->right);
    cout<<root->data<<" ";

}
int main()
{
    int in[7],pre[7];
    int i;
    for(i=0;i<7;i++)
    {
        cin>>pre[i];
    }
    for(i=0;i<7;i++)
    {
        cin>>in[i];
    }
    struct node* root = buildTree(pre,in,0,6);
    preorder(root);
    return(0);
}
