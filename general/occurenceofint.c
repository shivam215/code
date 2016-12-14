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
int occurenceofint(struct node* head,int key)
{
    int count=0;
    while(head!=NULL)
    {
        if(head->data == key){count++;}
        head = head->next;
    }
    return count;
}
int main()
{
    struct node* head = NULL;
    push(&head,1);
    push(&head,2);
    push(&head,3);
    push(&head,3);
    push(&head,1);
    push(&head,4);
    printf("%d",occurenceofint(head,5));
    return(0);

}
