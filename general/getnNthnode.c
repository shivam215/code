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
void getnthnode(struct node* headref,int index)
{
    struct node* temp = headref;
    int i =1;
    if(temp==NULL)
    {
        return;
    }
    while(i!=index&&temp!=NULL)
    {   temp = temp->next;
        i=i+1;
    }
    printf("%d",temp->data);

}
int main()
{
    struct node* head = NULL;
    push(&head,1);
    push(&head,2);
    push(&head,3);
    getnthnode(head,3);
    return(0);

}

