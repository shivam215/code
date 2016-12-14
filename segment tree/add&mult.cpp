#include <bits/stdc++.h>
#define MAX 300000
#define ll long long
#define mod 1000000007
using namespace std;
ll arr[100005],tree[MAX],lazy[MAX],lazy1[MAX],lazy2[MAX];
void build_tree(int node, int a, int b) {
  if(a > b) return;

  if(a == b) {
    tree[node] = arr[a];
    return;
  }

  build_tree(node*2, a, (a+b)/2); // Init left child
  build_tree(node*2+1, 1+(a+b)/2, b); // Init right child

  tree[node] = (tree[node*2] + tree[node*2+1]); // Init root value
  if(tree[node]>=mod)tree[node]%=mod;
}

void update_tree(int node, int a, int b, int i, int j, ll value) {

  if(lazy2[node]!=0)
  {
    tree[node] = ((b-a+1)*lazy2[node]);
    if(tree[node]>=mod)tree[node]%=mod;

    if(a!=b)
    {
      lazy2[node*2] = lazy2[node];
      lazy[node*2]=0;lazy1[node*2]=1;
      lazy2[node*2+1] = lazy2[node];
      lazy[node*2+1]=0;lazy1[node*2+1]=1;

    }
    lazy2[node]=0;

  }

  if(lazy[node] != 0 || lazy1[node]!=1) { // This node needs to be updated
    tree[node] = (tree[node]*lazy1[node]);
    if(tree[node]>=mod)tree[node]%=mod;
    tree[node] = (tree[node] + (b-a+1)*lazy[node]);
    if(tree[node]>=mod)tree[node]%=mod;

    if(a != b) {

      lazy1[node*2] = (lazy1[node*2] * lazy1[node]);
      if(lazy1[node*2]>=mod)lazy1[node*2]%=mod;

      lazy[node*2] = (lazy[node*2]*lazy1[node]);
      if(lazy[node*2]>=mod)lazy[node*2]%=mod;

      lazy[node*2] = (lazy[node*2] + lazy[node]);
      if(lazy[node*2]>=mod)lazy[node*2]%=mod;

      lazy1[node*2+1] = (lazy1[node*2+1] * lazy1[node]);
      if(lazy1[node*2+1]>=mod)lazy1[node*2+1]%=mod;

      lazy[node*2+1] = (lazy[node*2+1]*lazy1[node]);
      if(lazy[node*2+1]>=mod)lazy[node*2+1]%=mod;// Mark child as lazy

      lazy[node*2+1] = (lazy[node*2+1] + lazy[node]);
      if(lazy[node*2+1]>=mod)lazy[node*2+1]%=mod;// Mark child as lazy

    }

    lazy[node] = 0; // Reset it
    lazy1[node]=1;
  }

  if(a > b || a > j || b < i) // Current segment is not within range [i, j]
    return;

  if(a >= i && b <= j) { // Segment is fully within range
    tree[node] = (tree[node] + (b-a+1)*value);
    if(tree[node]>=mod)tree[node]%=mod;

    if(a != b) { // Not leaf node
      lazy[node*2] = (lazy[node*2] + value);
      if(lazy[node*2]>=mod)lazy[node*2]%=mod;
      lazy[node*2+1] = (lazy[node*2+1] + value);
      if(lazy[node*2+1]>=mod)lazy[node*2+1]%=mod;
    }

    return;
  }

  update_tree(node*2, a, (a+b)/2, i, j, value); // Updating left child
  update_tree(1+node*2, 1+(a+b)/2, b, i, j, value); // Updating right child

  tree[node] = (tree[node*2] + tree[node*2+1]);
  if(tree[node]>=mod)tree[node]%=mod; // Updating root with max value
}
void update_multiply(int node, int a, int b, int i, int j, ll value) {

  if(lazy2[node]!=0)
  {
    tree[node] = ((b-a+1)*lazy2[node]);
    if(tree[node]>=mod)tree[node]%=mod;
    if(a!=b)
    {
      lazy2[node*2] = lazy2[node];
       lazy[node*2]=0;lazy1[node*2]=1;
     lazy2[node*2+1] = lazy2[node];
    lazy[node*2+1]=0;lazy1[node*2+1]=1;

    }
    lazy2[node]=0;
  }

  if(lazy[node] != 0 || lazy1[node]!=1) {
    tree[node] = (tree[node]*lazy1[node]);
    if(tree[node]>=mod)tree[node]%=mod;
    tree[node] = (tree[node] + (b-a+1)*lazy[node]);
    if(tree[node]>=mod)tree[node]%=mod;

    if(a != b) {
      lazy1[node*2] = (lazy1[node*2] * lazy1[node]);
      if(lazy1[node*2]>=mod)lazy1[node*2]%=mod;

      lazy[node*2] = (lazy[node*2]*lazy1[node]);
      if(lazy[node*2]>=mod)lazy[node*2]%=mod;

      lazy[node*2] = (lazy[node*2] + lazy[node]);
      if(lazy[node*2]>=mod)lazy[node*2]%=mod;

      lazy1[node*2+1] = (lazy1[node*2+1] * lazy1[node]);
      if(lazy1[node*2+1]>=mod)lazy1[node*2+1]%=mod;

      lazy[node*2+1] = (lazy[node*2+1]*lazy1[node]);
      if(lazy[node*2+1]>=mod)lazy[node*2+1]%=mod;// Mark child as lazy

      lazy[node*2+1] = (lazy[node*2+1] + lazy[node]);
      if(lazy[node*2+1]>=mod)lazy[node*2+1]%=mod;// Mark child as lazy

    }

    lazy[node] = 0;
    lazy1[node]=1;
  }

  if(a > b || a > j || b < i)
    return;

  if(a >= i && b <= j) {
    tree[node] = (tree[node]*value);
    if(tree[node]>=mod)tree[node]%=mod;

    if(a != b) {
      lazy1[node*2] = (lazy1[node*2]*value);
      if(lazy1[node*2]>=mod)lazy1[node*2]%=mod;

      lazy1[node*2+1] = (lazy1[node*2+1]*value);
      if(lazy1[node*2+1]>=mod)lazy1[node*2+1]%=mod;

      lazy[node*2] = (lazy[node*2]*value);
      if(lazy[node*2]>=mod)lazy[node*2]%=mod;

      lazy[node*2+1] = (lazy[node*2+1]*value);
      if(lazy[node*2+1]>=mod)lazy[node*2+1]%=mod;// Mark child as lazy
    }

    return;
  }

  update_multiply(node*2, a, (a+b)/2, i, j, value); // Updating left child
  update_multiply(1+node*2, 1+(a+b)/2, b, i, j, value); // Updating right child

  tree[node] = (tree[node*2] + tree[node*2+1]); // Updating root with max value
  if(tree[node]>=mod)tree[node]%=mod;
}
void update_equal(int node, int a, int b, int i, int j, ll value) {

  if(lazy2[node]!=0)
  {
    tree[node] = ((b-a+1)*lazy2[node]);
    if(tree[node]>=mod)tree[node]%=mod;
    if(a!=b)
    {
      lazy2[node*2] = lazy2[node];
       lazy[node*2]=0;lazy1[node*2]=1;
        lazy2[node*2+1] = lazy2[node];
    lazy[node*2+1]=0;lazy1[node*2+1]=1;

    }
    lazy2[node]=0;
  }

  if(lazy[node] != 0 || lazy1[node]!=1) { // This node needs to be updated
    tree[node] = (tree[node]*lazy1[node]);
    if(tree[node]>=mod)tree[node]%=mod;
    tree[node] = (tree[node] + (b-a+1)*lazy[node]);
    if(tree[node]>=mod)tree[node]%=mod;

    if(a != b) {
      lazy1[node*2] = (lazy1[node*2] * lazy1[node]);
      if(lazy1[node*2]>=mod)lazy1[node*2]%=mod;

      lazy[node*2] = (lazy[node*2]*lazy1[node]);
      if(lazy[node*2]>=mod)lazy[node*2]%=mod;

      lazy[node*2] = (lazy[node*2] + lazy[node]);
      if(lazy[node*2]>=mod)lazy[node*2]%=mod;

      lazy1[node*2+1] = (lazy1[node*2+1] * lazy1[node]);
      if(lazy1[node*2+1]>=mod)lazy1[node*2+1]%=mod;

      lazy[node*2+1] = (lazy[node*2+1]*lazy1[node]);
      if(lazy[node*2+1]>=mod)lazy[node*2+1]%=mod;// Mark child as lazy

      lazy[node*2+1] = (lazy[node*2+1] + lazy[node]);
      if(lazy[node*2+1]>=mod)lazy[node*2+1]%=mod;// Mark child as lazy

    }

    lazy[node] = 0; // Reset it
    lazy1[node]=1;
  }

  if(a > b || a > j || b < i) // Current segment is not within range [i, j]
    return;

  if(a >= i && b <= j) { // Segment is fully within range
    tree[node] = ((b-a+1)*value);
    if(tree[node]>=mod)tree[node]%=mod;
    lazy[node]=0;lazy1[node]=1;

    if(a != b) { // Not leaf node
      lazy2[node*2] = value;
      if(lazy2[node*2]>=mod)lazy2[node*2]%=mod;
      lazy[node*2]=0;lazy1[node*2]=1;
      lazy2[node*2+1] = value;
      if(lazy2[node*2+1]>=mod)lazy2[node*2+1]%=mod;
      lazy[node*2+1]=0;lazy1[node*2+1]=1;
    }

    return;
  }

  update_equal(node*2, a, (a+b)/2, i, j, value); // Updating left child
  update_equal(1+node*2, 1+(a+b)/2, b, i, j, value); // Updating right child

  tree[node] = (tree[node*2] + tree[node*2+1]); // Updating root with max value
  if(tree[node]>=mod)tree[node]%=mod;
}
ll query_tree(int node, int a, int b, int i, int j) {

  if(a > b || a > j || b < i) return 0; // Out of range

  if(lazy2[node]!=0)
  {
    tree[node] = ((b-a+1)*lazy2[node]);
    if(tree[node]>=mod)tree[node]%=mod;
    if(a!=b)
    {
        lazy2[node*2] = lazy2[node];
         lazy[node*2]=0;lazy1[node*2]=1;
        lazy2[node*2+1] = lazy2[node];
        lazy[node*2+1]=0;lazy1[node*2+1]=1;

    }
    lazy2[node]=0;
  }

  if(lazy[node] != 0 || lazy1[node]!=1) { // This node needs to be updated
    tree[node] = (tree[node]*lazy1[node]);
    if(tree[node]>=mod)tree[node]%=mod;
    tree[node] = (tree[node] + (b-a+1)*lazy[node]);
    if(tree[node]>=mod)tree[node]%=mod;

    if(a != b) {
      lazy1[node*2] = (lazy1[node*2] * lazy1[node]);
      if(lazy1[node*2]>=mod)lazy1[node*2]%=mod;

      lazy[node*2] = (lazy[node*2]*lazy1[node]);
      if(lazy[node*2]>=mod)lazy[node*2]%=mod;

      lazy[node*2] = (lazy[node*2] + lazy[node]);
      if(lazy[node*2]>=mod)lazy[node*2]%=mod;

      lazy1[node*2+1] = (lazy1[node*2+1] * lazy1[node]);
      if(lazy1[node*2+1]>=mod)lazy1[node*2+1]%=mod;

      lazy[node*2+1] = (lazy[node*2+1]*lazy1[node]);
      if(lazy[node*2+1]>=mod)lazy[node*2+1]%=mod;// Mark child as lazy

      lazy[node*2+1] = (lazy[node*2+1] + lazy[node]);
      if(lazy[node*2+1]>=mod)lazy[node*2+1]%=mod;// Mark child as lazy
    }

    lazy[node] = 0; // Reset it
    lazy1[node]=1;
  }

  if(a >= i && b <= j) // Current segment is totally within range [i, j]
    return tree[node];

  ll q1 = query_tree(node*2, a, (a+b)/2, i, j); // Query left child
  ll q2 = query_tree(1+node*2, 1+(a+b)/2, b, i, j); // Query right child

  ll res = (q1 + q2);
  if(res>=mod)res%=mod; // Return final result

  return res;
}

int main() {
  ios_base::sync_with_stdio(false);
  int n,q,type,x,y;
  ll v;
  cin>>n>>q;
  for(int i = 0; i < n; i++) cin>>arr[i];

  build_tree(1, 0, n-1);
  for(int i=0;i<MAX;i++)lazy1[i]=1;
  while(q--)
  {
    cin>>type>>x>>y;
    x--;y--;
    if(type==1){cin>>v;update_tree(1,0,n-1,x,y,v);}
    else if(type==2){cin>>v;update_multiply(1,0,n-1,x,y,v);}
    else if(type==3){cin>>v;update_equal(1,0,n-1,x,y,v);}
    else
    {
      ll res = query_tree(1,0,n-1,x,y);
      printf("%lld\n",res);
    }
  }
  return 0;
}
