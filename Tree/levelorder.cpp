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
void levelOrder(struct node* root)
{   if(root==NULL){return;}
    vector <struct node*> q;
    q.push_back(root);
    while(!(q.empty()))
    {
        cout<<q[0]->data;
        if(q[0]->left)
            q.push_back(q[0]->left);
        if(q[0]->right)
            q.push_back(q[0]->right);
        q.erase(q.begin());

    }
}
int main()
{
    struct node* root = newnode(1);
    root->left = newnode(2);
    root->right = newnode(3);
    root->left->left = newnode(4);
    root->left->right = newnode(5);
    levelOrder(root);
    return(0);
}
