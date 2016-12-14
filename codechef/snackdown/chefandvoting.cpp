#include <bits/stdc++.h>
using namespace std;
struct item
{
    int a,b,c;
};
bool myfunction1(struct item p, struct item q)
{
    return p.b>q.b;
}
bool myfunction2(struct item p, struct item q)
{
    return p.a<q.a;
}
int main()
{
    ios_base::sync_with_stdio(false);
    vector<struct item> v;
    int t,n,i,sum,flag,temp;
    cin>>t;
    while(t--)
    {
        cin>>n;
        v.clear();
        flag=0;
        for(i=1;i<=n;i++)
        {
            cin>>temp;
            struct item p;
            p.a = i;
            p.b = temp;
            p.c = -1;
            v.push_back(p);
        }
        sum = 0;
        for(i=0;i<n;i++)
        {
            if(v[i].b>=n){flag=1;break;}
            sum = sum + v[i].b;
        }
        if(sum!=n)flag=1;
        if(flag)
        {
            cout<<-1<<endl;
            continue;
        }
        sort(v.begin(),v.end(),myfunction1);
        /*for(i=0;i<n;i++)
        {
            cout<<v[i].a<<' '<<v[i].b<<' '<<v[i].c<<endl;
        }*/
        int j=1;
        i=0;
        sum = 0;
        while(sum!=n)
        {
            temp = v[i].b;
            while(temp--)
            {
                v[j].c = v[i].a;
                j++;
                if(j>=n)j=j%n;
                sum++;
            }
            i++;
        }
        sort(v.begin(),v.end(),myfunction2);
        for(i=0;i<n;i++)
        {
            if(i!=n-1)cout<<v[i].c<<' ';
            else cout<<v[i].c<<endl;
        }

    }
    return 0;
}
