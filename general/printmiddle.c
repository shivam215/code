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
void printmiddle(struct node* head)
{
    struct node* slow_ptr = head;
    struct node* fast_ptr = head;
    if(head==NULL)return;
    while(fast_ptr!=NULL && fast_ptr->next!=NULL && slow_ptr!=NULL)
    {
        slow_ptr = slow_ptr->next;
        fast_ptr = fast_ptr->next->next;
    }
    printf("%d",slow_ptr->data);
    return;
}
int main()
{
    struct node* head = NULL;
    push(&head,1);
    push(&head,2);
    push(&head,3);
    push(&head,4);


    printmiddle(head);
    return(0);

}
