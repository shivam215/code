#include <stdio.h>
struct node
{
    int data;
    struct node* next;
};
struct node* newNode(int key)
{
    struct node* new_node = (struct node*)malloc(sizeof(struct node));
    new_node->data = key;
    new_node->next = NULL;
    return new_node;
};
void sortedInsert(struct node** headref, struct node* new_node)
{
    struct node* temp = *headref;
    struct node* prev;
    if(temp==NULL)
    {
        *headref = new_node;
        return;
    }
    if(new_node->data<= temp->data)
    {
        new_node->next = temp;
        *headref = new_node;
        return;
    }
    while(temp!=NULL && temp->data<new_node->data)
    {   prev = temp;
        temp = temp->next;
    }
    prev->next = new_node;
    new_node->next = temp;
    return;

}
void printList(struct node *head)
{
    struct node *temp = head;
    while(temp != NULL)
    {
        printf("%d  ", temp->data);
        temp = temp->next;
    }
}
int main()
{
    /* Start with the empty list */
    struct node* head = NULL;
    struct node *new_node = newNode(5);
    sortedInsert(&head, new_node);
    new_node = newNode(10);
    sortedInsert(&head, new_node);
    new_node = newNode(7);
    sortedInsert(&head, new_node);
    new_node = newNode(3);
    sortedInsert(&head, new_node);
    new_node = newNode(1);
    sortedInsert(&head, new_node);
    new_node = newNode(9);
    sortedInsert(&head, new_node);
    printf("\n Created Linked List\n");
    printList(head);

    getchar();
    return 0;
}
