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
void swap(int* a, int* b)
{
    int t;
    t = *a;
    *a = *b;
    *b = t;
    return;
}
void pairwiseswap(struct node* head)
{
    struct node* current = head;
    while(current!=NULL && current->next!=NULL)
    {
        swap(&(current->data),&(current->next->data));
        current = current->next->next;
    }
}
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
    struct node* head = NULL;
    push(&head,4);
    push(&head,3);
    push(&head,2);
    push(&head,1);
    pairwiseswap(head);
    printlist(head);
    return(0);

}
