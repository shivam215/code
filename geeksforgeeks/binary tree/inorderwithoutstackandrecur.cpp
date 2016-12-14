#include <bits/stdc++.h>
using namespace std;
struct node
{
    int data;
    struct node* left;
    struct node* right;
    node(int x):data(x),left(NULL),right(NULL){};
};
int main()
{
    struct node* root = new node(4);
    root->left = new node(5);
    root->right = new node(6);
    root->left->left = new node(7);
    root->left->right = new node(8);
    root->right->left = new node(9);
    root->right->right = new node(10);
    struct node* cur = root;
    while(cur!=NULL)
    {
        if(cur->left==NULL)
        {
            printf("%d\t",cur->data);
            cur = cur->right;
        }
        else
        {
            struct node* temp = cur->left;
            while(temp&&temp->right!=NULL&&temp->right!=cur)
            {
                temp = temp->right;
            }
            if(temp->right==NULL)
            {
                temp->right = cur;
                cur = cur->left;
            }
            else
            {
                temp->right = NULL;
                printf("%d\t",cur->data);
                cur = cur->right;
            }
        }
    }
    return 0;
}
