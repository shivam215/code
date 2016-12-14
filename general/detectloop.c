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
void detectloop(struct node* head)
{
    struct node* slow_ptr = head;
    struct node* fast_ptr = head;
    while(slow_ptr&&fast_ptr&&fast_ptr->next)
    {
        slow_ptr = slow_ptr->next;
        fast_ptr = fast_ptr->next->next;
        if(slow_ptr==fast_ptr)
        {
            printf("found loop");
            return;
        }
    }
}
int main()
{
    struct node* head = NULL;
    push(&head,1);
    push(&head,2);
    push(&head,3);
    head->next->next->next = head->next;
    detectloop(head);
    return(0);

}
