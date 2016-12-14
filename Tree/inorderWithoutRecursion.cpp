#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(false);cin.tie(0);
#define bool int
using namespace std;
struct tNode
{
    int data;
    struct tNode* left;
    struct tNode* right;
};
struct sNode
{
    struct tNode* t;
    struct sNode* next;
};
bool isEmpty(struct sNode* top)
{
    return (top==NULL)?1:0;
}
struct tNode* newnode(int data)
{
    struct tNode* node = (struct tNode*)malloc(sizeof(struct tNode));
    node->data =  data;
    node->left = NULL;
    node->right = NULL;
    return node;
};
void push(struct sNode** topref,struct tNode* t)
{
    struct sNode* newnode = (struct sNode*)malloc(sizeof(struct sNode));
    newnode->t = t;
    newnode->next = (*topref);
    (*topref) = newnode;
}
struct tNode* pop(struct sNode** topref)
{
  if(isEmpty(*topref))
  {
      cout<<"stack underflow";
      getchar();
      exit(0);
  }
  struct tNode* res = (*topref)->t;
  struct sNode* pop = *topref;
  *topref = pop->next;
  free(pop);
  return res;
}
void inorder(struct tNode* root)
{
    if(root==NULL)
        return;
    struct sNode* s = NULL;
    struct tNode* current = root;
    bool done = 0;
    while(!done)
    {
        if(current!=NULL)
        {
            push(&s,current);
            current = current->left;
        }
        else
        {
            if(!isEmpty(s))
            {
                current = pop(&s);
                cout<<current->data;
                current = current->right;
            }
            else
                done = 1;
        }
    }
}
int main()
{
    struct tNode* root = newnode(1);
    root->left = newnode(2);
    root->right = newnode(3);
    root->left->left = newnode(4);
    root->left->right = newnode(5);
    root->right->left = newnode(6);
    root->right->right = newnode(7);
    inorder(root);
    return(0);

}

