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
void split(struct node* source, struct node** front, struct node** back)
{
    if(source==NULL || source->next == NULL)
    {
        *front = source;
        *back = NULL;
        return;
    }
    struct node* slowptr = source;
    struct node* fastptr = source->next;
    while(fastptr!=NULL && fastptr->next!=NULL)
    {
        slowptr = slowptr->next;
        fastptr = fastptr->next->next;
    }
    *front = source;
    *back = slowptr->next;
    slowptr->next = NULL;

}
struct node* sortedmerge(struct node* a, struct node* b)
{   struct node* result = NULL;
    if(a==NULL)
        return b;
    else if(b==NULL)
        return a;
    if(a->data <= b->data)
    {
        result = a;
        result->next = sortedmerge(a->next,b);
    }
    else
    {
        result = b;
        result->next = sortedmerge(a,b->next);

    }
    return result;
};
void mergesort(struct node** headref)
{
    struct node* temp = *headref;
    if(temp==NULL || temp->next==NULL)
        return;
    struct node* a = NULL;
    struct node* b = NULL;
    split(temp,&a,&b);
    mergesort(&a);
    mergesort(&b);
    *headref = sortedmerge(a,b);
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
    push(&head,4);
    mergesort(&head);
    printlist(head);
    return(0);

}
