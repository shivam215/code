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
void deleteTree(struct node* root)
{
    if(root == NULL)
        return;
    deleteTree(root->left);
    deleteTree(root->right);
    cout<<"deleted node is"<<" "<<root->data<<endl;
    free(root);
}
int main()
{
   struct node* root = newnode(1);
   root->left = newnode(2);
   root->right = newnode(3);
   deleteTree(root);
   root = NULL;
   return(0);

}
