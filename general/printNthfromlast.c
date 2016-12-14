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
void printNthfromlast(struct node* head, int n)
{
    static int i=0;
    if(head==NULL)
        return;
    printNthfromlast(head->next,n);
    if(++i == n)
    {
        printf("%d",head->data);
    }
    return;
}
int main()
{
    struct node* head = NULL;
    push(&head,1);
    push(&head,2);
    push(&head,3);
    printNthfromlast(head,1);
    return(0);

}

