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
int seg[400005];
pair<int,int> a[100005],b[100005];
bool comp(pii c,pii d)
{
    if(c.fe!=d.fe)return c.fe<d.fe;
    return c.se>d.se;
}
void update(int i,int si,int sj,int qi,int val)
{
    if(qi<si||qi>sj)return;
    if(si==sj)
    {
        seg[i]=val;
        return;
    }
    int mid = (si+sj)/2;
    if(qi<=mid)update(2*i,si,mid,qi,val);
    else if(qi>=mid+1)update(2*i+1,mid+1,sj,qi,val);
    seg[i] = max(seg[2*i],seg[2*i+1]);
}
ll query(int i,int si,int sj,int qi,int qj){
	if(si==qi and sj==qj){
		return seg[i];
	}
	int mid = (si+sj)/2;
	if(qj<=mid) return query(2*i,si,mid,qi,qj);
	else if(mid+1<=qi) return query(2*i+1,mid+1,sj,qi,qj);
	else return max(query(2*i,si,mid,qi,mid),query(2*i+1,mid+1,sj,mid+1,qj));
}
int main()
{
    int n;
    cin>>n;
    rep(i,1,n+1)cin>>a[i].fe>>a[i].se;
    sort(a+1,a+n+1,comp);
    rep(i,1,n+1)
    {
        b[i].fe = a[i].se;
        b[i].se = i;
    }
    sort(b+1,b+n+1,comp);
    rep(i,1,n+1)
    {
        ll temp = query(1,1,n,1,b[i].se);
        update(1,1,n,b[i].se,temp+1);
    }
    cout<<seg[1]<<endl;
    return 0;

}
