#include <bits/stdc++.h>
using namespace std;
string s;
string alpha = " abcdefghijklmnopqrstuvwxyz";
struct node
{
    string datastr;
    struct node* left;
    struct node* right;
};
struct node* newnode(string str)
{
    struct node* nn = (struct node*)malloc(sizeof(struct node));
    nn->left = NULL;
    nn->right = NULL;
    nn->datastr = str;
    return nn;
};
struct node* build(int i,string parent,int data)
{
    if(data>26)return NULL;
    string str = parent + alpha[data];
    struct node* root = newnode(str);
    if(i<s.size())
    {
        root->left = build(i+1,str,s[i]-'0');
        if(i<s.size()-1)
        {
            int d = 10*(s[i]-'0') + s[i+1]-'0';
            root->right = build(i+2,str,d);
        }
    }
    return root;
};
void print(struct node* root)
{
    if(root==NULL)return;
    cout<<root->datastr<<endl;
    print(root->left);
    print(root->right);
}
int main()
{
    cin>>s;
    struct node* root = build(0,"",0);
    print(root);
    return 0;
}
