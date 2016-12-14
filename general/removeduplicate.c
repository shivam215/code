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
void removeduplicate(struct node* head)
{
    if(head==NULL)
        return;
    struct node* current = head;
    struct node* forward;
    while(current!=NULL && current->next!=NULL)
    {
        forward = current->next;
        if(current->data == forward->data)
        {
            current->next = forward->next;
            free(forward);
        }
        else
        {
            current = current->next;
        }

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
    push(&head,4);
    push(&head,3);
    push(&head,3);
    push(&head,2);
    removeduplicate(head);
    printlist(head);
    return(0);

}

