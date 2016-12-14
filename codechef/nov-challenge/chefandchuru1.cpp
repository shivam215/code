#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(false);cin.tie(0);
#define ll unsigned long long
#define MAX 100005
using namespace std;
long long val[320],tree[MAX];
int n,a[MAX],l[MAX],r[MAX],bucket,totalbucket,cnt[320][MAX];
//BIT START
void update(int pos, int delta)
{
    while(pos<n)
    {
        tree[pos]+= delta;
        pos = (pos|pos+1);
    }
}
long long query(int pos)
{
    long long sum = 0;
    while(pos>=0)
    {
        sum += tree[pos];
        pos = (pos&(pos+1))-1;
    }
    return sum;
}
long long query(int x, int y)
{
    return query(y)-query(x-1);
}
//BIT END
void update_sqrt(int pos, int delta)
{
    for(int i=0;i<totalbucket;++i)
    {
        val[i]+= (long long)cnt[i][pos]*delta;
    }
}
ll query_general(int x, int y)
{
    ll res = 0;
    for(int i=0;i<totalbucket;i++)
    {
        int ini = i*bucket,end = (ini+bucket-1);
        if(x<=ini && y>=end)
            res+=val[i];
        else
        {
            for(int k=max(x,ini);k<=min(y,end);k++)
            {
                res+=query(l[k],r[k]);
            }
        }
    }
    return res;
}
void update_general(int pos, int delta)
{
    update(pos,delta-a[pos]);
    update_sqrt(pos,delta-a[pos]);
    a[pos] = delta;
}


int main()
{
    cin>>n;
    bucket = sqrt(n);
    totalbucket = (n+bucket-1)/bucket;
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
        update(i,a[i]);
    }
    for(int i=0;i<n;i++)
    {
        cin>>l[i]>>r[i];
        l[i]--;r[i]--;
        cnt[i/bucket][l[i]]++;
        cnt[i/bucket][r[i]+1]--;
    }
    for(int i=0;i<totalbucket;i++)
    {
        val[i] = (long long)cnt[i][0]*a[0];
        for(int pos=1;pos<n;pos++)
        {
            cnt[i][pos]+=cnt[i][pos-1];
            val[i]+=(long long)cnt[i][pos]*a[pos];
        }
    }
    int q,typo,x,y;
    cin>>q;
    while(q--)
    {
        cin>>typo>>x>>y;
        x--;
        if(typo==1)
        {
            update_general(x,y);
        }
        else
        {
            y--;
            cout<<query_general(x,y)<<endl;
        }
    }

    return(0);

}
