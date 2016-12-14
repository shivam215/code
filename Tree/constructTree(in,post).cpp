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
struct node* buildTree(int* post, int* in, int l, int h)
{
    if(l>h)
        return NULL;
    static int i=6;
    int index;
    index = search(in,l,h,post[i--]);
    struct node* tnode = (struct node*)malloc(sizeof(struct node));
    tnode->data = in[index];
    tnode->right = buildTree(post,in,index+1,h);
    tnode->left = buildTree(post,in,l,index-1);
    return tnode;


};
void postorder(struct node* root)
{
    if(root==NULL)
        return;
    postorder(root->left);
    postorder(root->right);
    cout<<root->data<<" ";

}
int main()
{
    int in[7],post[7];
    int i;
    for(i=0;i<7;i++)
    {
        cin>>post[i];
    }
    for(i=0;i<7;i++)
    {
        cin>>in[i];
    }
    struct node* root = buildTree(post,in,0,6);
    postorder(root);
    return(0);
}
