#include <stdio.h>
struct node
{
    int data;
    struct node* next;
};
void push(struct node** headref, int key)
{
    struct node* new_node = (struct node*)malloc(sizeof(struct node));
    new_node->data = key;
    new_node->next = *headref;
    *headref = new_node;
}
struct node* sortedintersect(struct node* a, struct node* b)
{
    struct node* result = NULL;
    struct node** lastref = &result;
    while(a!=NULL && b!=NULL)
    {
        if(a->data == b->data)
        {
            push(lastref,a->data);
            lastref = &(*lastref)->next;


            a = a->next;
            b = b->next;
        }
        else if(a->data > b->data)
            b = b->next;
        else
            a = a->next;
    }
    return result;
};
void printlist(struct node* headref)
{
    while(headref!=NULL)
    {
        printf("%d\t",headref->data);
        headref= headref->next;
    }
}
int main()
{
  /* Start with the empty lists */
  struct node* a = NULL;
  struct node* b = NULL;
  struct node *intersect = NULL;

  /* Let us create the first sorted linked list to test the functions
   Created linked list will be 1->2->3->4->5->6 */
  push(&a, 6);
  push(&a, 5);
  push(&a, 4);
  push(&a, 3);
  push(&a, 2);
  push(&a, 1);

  /* Let us create the second sorted linked list
   Created linked list will be 2->4->6->8 */
  push(&b, 8);
  push(&b, 6);
  push(&b, 4);
  push(&b, 2);

  /* Find the intersection two linked lists */
  intersect = sortedintersect(a, b);

  printf("\n Linked list containing common items of a & b \n ");
  printlist(intersect);

  getchar();
}
