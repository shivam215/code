#include <stdio.h>
#include <stdlib.h>
#define bool int

struct t_node
{
    int data;
    struct t_node* left;
    struct t_node* right;
};
struct s_node
{
    struct t_node* t;
    struct s_node* next;
};
struct t_node* newnode(int key)
{
    struct t_node* new_node = (struct t_node*)malloc(sizeof(struct t_node));
    new_node->data = key;
    new_node->left = NULL;
    new_node->right = NULL;
    return new_node;
};
void push(struct s_node** sref, struct t_node* t)
{
   struct s_node* new_node = (struct s_node*)malloc(sizeof(struct s_node));
   new_node->t = t;
   new_node->next = *sref;
   *sref = new_node;

}
bool isempty(struct s_node *top)
{
   return (top == NULL)? 1 : 0;
}
struct t_node* pop(struct s_node** sref)
{
    struct s_node* temp = *sref;
    struct t_node* rest = temp->t;
    *sref = temp->next;
    free(temp);
    return rest;

} ;
void inorder(struct t_node* root)
{
    struct t_node* current = root;
    struct s_node* s = NULL;
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
           if(!isempty(s))
           {
               current = pop(&s);
               printf("%d\t",current->data);
               current = current->right;
           }
           else
            done =1;
       }
    }
}
int main()
{

  /* Constructed binary tree is
            1
          /   \
        2      3
      /  \
    4     5
  */
  struct t_node *root = newnode(1);
  root->left        = newnode(2);
  root->right       = newnode(3);
  root->left->left  = newnode(4);
  root->left->right = newnode(5);

  inorder(root);

  getchar();
  return 0;
}
