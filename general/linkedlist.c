#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next;
};
void push(struct node** headref,int key)
{
    struct node* new_node = (struct node*)malloc(sizeof(struct node));
    new_node->data = key;
    new_node->next = *headref;
    *headref = new_node;
};
void append(struct node** headref, int key)
{
    struct node* new_node = (struct node*)malloc(sizeof(struct node));
    struct node* temp;
    new_node->data = key;
    new_node->next = NULL;
    if(*headref==NULL)
    {
        *headref = new_node;
        return;
    }
    temp = *headref;
    while(temp->next!=NULL)
    {
        temp = temp->next;
    }
    temp->next =  new_node;
    return;

}
void insertafter(struct node* prev_node, int key)
{
    struct node* new_node = (struct node*)malloc(sizeof(struct node));
    new_node->data = key;
    new_node->next = prev_node->next;
    prev_node->next = new_node;
    return;
}
void printlist(struct node* headref)
{   struct node* temp = headref;
    while(temp!=NULL)
    {
        printf("%d\t",temp->data);
        temp = temp->next;
    }
}
int main()
{
    struct node* head = NULL;
    append(&head,1);
    append(&head,2);
    push(&head,3);
    insertafter(head->next,4);
    printlist(head);
    getchar();
    return(0);
}
