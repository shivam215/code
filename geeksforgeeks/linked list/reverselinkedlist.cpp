#include <bits/stdc++.h>
using namespace std;
struct node
{
    int data;
    struct node* next;
};
void push(struct node** headref,int val)
{
    struct node* newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = val;
    newnode->next = *headref;
    *headref = newnode;
    return;
}
struct node* rever(struct node* rev)
{
    struct node* temp;
    if(rev->next==NULL)
    {
       return rev;
    }
    temp = rever(rev->next);
    rev->next->next = rev;
    rev->next = NULL;
    return temp;

};
int main()
{
    struct node* head=NULL;
    push(&head,20);
    push(&head,4);
    push(&head,15);
    push(&head,85);
    head = rever(head);
    while(head!=NULL)
    {
        cout<<head->data<<' ';
        head = head->next;
    }
    return 0;


}
