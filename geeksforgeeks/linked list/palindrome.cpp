#include <bits/stdc++.h>
#define inf 1000000000
#define mod 1000000007
#define scano(x) scanf("%d",&x)
#define scanll(x) scanf("%lld",&x)
#define scant(x,y) scanf("%d%d",&x,&y)
#define pb push_back
#define mp make_pair
#define ll long long
#define vi vector<int>
#define pii pair<int,int>
#define vpii vector< pii >
#define rep(i,a,b) for(int i=a;i<b;i++)
#define fe first
#define se second
using namespace std;
struct node
{
    int data;
    node* next;
    node(int d):data(d),next(NULL){};
};
node* head;
int ispalin(node* root)
{
    if(root==NULL)return 1;
    int res = ispalin(root->next)&&(head->data==root->data);
    head = head->next;
    return res;
}
int main()
{
    struct node* root = new node(2);
    root->next = new node(2);
    root->next->next = new node(2);
    root->next->next->next = new node(1);
    head = root;
    cout<<ispalin(root)<<endl;
    return 0;
}
