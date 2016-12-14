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
void deletelinkedlist(struct node** head)
{   struct node* temp = *head;
    if(temp==NULL)
        return;
    deletelinkedlist(&(temp->next));
    free(temp);
    *head = NULL;

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
    deletelinkedlist(&head);
    printlist(head);
    return(0);

}
