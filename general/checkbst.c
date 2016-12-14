#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
struct node
{
    int data;
    struct node* left;
    struct node* right;
};
struct node* newnode(int key)
{
    struct node* new_node = (struct node*)malloc(sizeof(struct node));
    new_node->data = key;
    new_node->left = NULL;
    new_node->right = NULL;
    return new_node;
};
void printtree(struct node* root)
{
    if(root==NULL)
        return;
    printtree(root->left);
    printf("%d\t",root->data);
    printtree(root->right);

}
struct node* insert(struct node* root,int key)
{
    if(root==NULL)
        return newnode(key);
    if(root->data>key)
        root->left = insert(root->left,key);
    else if(root->data<key)
        root->right = insert(root->right,key);
    return root;

};
int checkbst(struct node* root,int min,int max)
{
    if(root==NULL)
        return 1;
    return(checkbst(root->left,min,root->data-1) && checkbst(root->right,root->data+1,max) && root->data>=min && root->data<=max);
}
int main()
{
    struct node* root = NULL;
    int val;
    root = newnode(10);
    root->left = newnode(6);
    root->right = newnode(15);
    root->left->left = newnode(3);
    insert(root,11);
    printtree(root);
    if(checkbst(root,INT_MIN,INT_MAX))
        printf("tree is bst");
    else
        printf("tree is not bst");

    return(0);
}
