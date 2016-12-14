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
void reverselinklist(struct node** headref)
{  if(*headref==NULL)return;

    struct node* first = *headref;
    struct node* rest = first->next;
    if(rest==NULL)
    {
        return;
    }
    reverselinklist(&rest);
    first->next->next = first;
    first->next = NULL;
    *headref = rest;
}
void printlist(struct node* headref)
{
    while(headref!=NULL)
    {
        printf("%d\t",headref->data);
        headref= headref->next;
    }
    printf("\n");
}
int main()
{
    struct node* head = NULL;
    push(&head,1);
    push(&head,2);
    push(&head,3);
    push(&head,4);
    printlist(head);
    reverselinklist(&head);
    printlist(head);
    return(0);

}
