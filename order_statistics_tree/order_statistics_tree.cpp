/*
http://codeforces.com/contest/785/problem/E
In this order_statistics_tree(augmented set) is used
because in normal set distance between two iterators is
O(n) in worst case
*/

#include <bits/stdc++.h>
#define inf 1000000009
#define mod 1000000007
#define scano(x) scanf("%d",&x)
#define scanll(x) scanf("%lld",&x)
#define scant(x,y) scanf("%d%d",&x,&y)
#define pb push_back
#define mp make_pair
#define ll long long int
#define vi vector<int>
#define pii pair<int,int>
#define vpii vector< pii >
#define rep(i,a,b) for(int i=a;i<b;i++)
#define fe first
#define se second
#define MAX 100005
using namespace std;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#define T int
#define ordered_set tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>
ordered_set seg[800005];
int arr[200005];

void update(int i,int si,int sj,int qi,int val)
{
    if(qi<si||qi>sj)return;
    if(si==sj)
    {
        seg[i].insert(val);
        return;
    }
    int mid = (si+sj)/2;
    if(qi<=mid)update(2*i,si,mid,qi,val);
    else if(qi>=mid+1)update(2*i+1,mid+1,sj,qi,val);
    seg[i].insert(val);
}
void removeseg(int i,int si,int sj,int qi)
{
    if(qi<si||qi>sj)return;
    if(si==sj)
    {
        seg[i].clear();
        return;
    }
    int mid = (si+sj)/2;
    if(qi<=mid)removeseg(2*i,si,mid,qi);
    else if(qi>=mid+1)removeseg(2*i+1,mid+1,sj,qi);
    seg[i].erase(arr[qi]);
    return;
}
int query1(int i,int si,int sj,int qi,int qj,int val){
	if(si==qi and sj==qj){
            return seg[i].order_of_key(val);
	}
	int mid = (si+sj)/2;
	if(qj<=mid) return query1(2*i,si,mid,qi,qj,val);
	else if(mid+1<=qi) return query1(2*i+1,mid+1,sj,qi,qj,val);
	else
    {
        return query1(2*i,si,mid,qi,mid,val)+query1(2*i+1,mid+1,sj,mid+1,qj,val);
    }
}
int query2(int i,int si,int sj,int qi,int qj,int val){
	if(si==qi and sj==qj){
		return sj-si+1-seg[i].order_of_key(val);
	}
	int mid = (si+sj)/2;
	if(qj<=mid) return query2(2*i,si,mid,qi,qj,val);
	else if(mid+1<=qi) return query2(2*i+1,mid+1,sj,qi,qj,val);
	else
    {
        return query2(2*i,si,mid,qi,mid,val)+query2(2*i+1,mid+1,sj,mid+1,qj,val);
    }
}
int main()
{
    //ios_base::sync_with_stdio(false);cin.tie(0);
    int n,q;
    scant(n,q);

    rep(i,1,n+1)arr[i]=i;
    rep(i,1,n+1)update(1,1,n,i,i);
    ll ans=0;
    while(q--)
    {
        int l,r;
        scant(l,r);
        if(l>r)
        {
            int temp = l;
            l = r;
            r = temp;
        }
        if(l==r)
        {
            printf("%lld\n",ans);
            continue;
        }
        if(r==l+1)
        {
            if(arr[l]>arr[r])ans--;
            else ans++;
        }
        else
        {
            int k = query2(1,1,n,l+1,r-1,arr[l]);
            ans += k;
            k = query1(1,1,n,l+1,r-1,arr[l]);
            ans-=k;
            k = query2(1,1,n,l+1,r-1,arr[r]);
            ans -=k;
            k = query1(1,1,n,l+1,r-1,arr[r]);
            ans+=k;
            if(arr[l]>arr[r])ans--;
            else ans++;

        }
        removeseg(1,1,n,l);
        removeseg(1,1,n,r);
        update(1,1,n,l,arr[r]);
        update(1,1,n,r,arr[l]);
        printf("%lld\n",ans);
        int temp = arr[l];
        arr[l] = arr[r];
        arr[r] = temp;
    }
    return 0;

}
