#include <bits/stdc++.h>
using namespace std;
struct node
{
    int data;
    struct node* left;
    struct node* right;
    node(int x):data(x),left(NULL),right(NULL){};
};
void print(struct node* root)
{
    stack<struct node*> st;
    struct node* cur = root;
    while(1)
    {
        while(cur!=NULL)
        {
            cout<<cur->data<<' ';
            st.push(cur);
            cur = cur->left;
        }
        if(st.empty())break;
        cur = st.top();
        //cout<<cur->data<<' ';
        st.pop();
        cur = cur->right;
    }
}
int main()
{
    struct node* root = new node(4);
    root->left = new node(5);
    root->right = new node(6);
    root->left->left = new node(7);
    root->left->right = new node(8);
    root->right->left = new node(9);
    root->right->right = new node(10);
    print(root);
    return 0;
}
