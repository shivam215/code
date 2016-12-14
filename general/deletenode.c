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
void deletenode(struct node** headref, int key)
{
    struct node* temp = *headref, *prev;
    if(temp==NULL)
    {
        return;
    }
    if(temp->data == key)
    {
        *headref = temp->next;
        free(temp);
        return;
    }
    while(temp!=NULL && temp->data!=key)
    {
        prev = temp;
        temp = temp->next;
    }
    prev->next = temp->next;
    free(temp);
    return;
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
    push(&head,1);
    push(&head,2);
    push(&head,3);
    deletenode(&head,3);
    printlist(head);
    return(0);

}
