#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n,m,type,l,r,p,d,i;
    set<int> s[6];
    cin>>n;
    int a[n];
    for(i=0;i<n;i++)
        {cin>>a[i];
        if((a[i]%2)==0)s[2].insert(i);
        if((a[i]%3)==0)s[3].insert(i);
        if((a[i]%5)==0)s[5].insert(i);}
    cin>>m;
    while(m--)
    {
        cin>>type;
        if(type==2)
        {
            cin>>l>>d;
            l--;
            if(a[l]%2==0) s[2].erase(l);
            if(a[l]%3==0) s[3].erase(l);
            if(a[5]%5==0) s[5].erase(l);
            if(d%2==0) s[2].insert(l);
            if(d%3==0) s[3].insert(l);
            if(d%5==0) s[5].insert(l);
            a[l]=d;
        }
        else
        {
            cin>>l>>r>>p;
            l--;r--;
            vector<int> del;
            set<int>::iterator b = lower_bound(s[p].begin(),s[p].end(),l);
            for(set<int>::iterator it =b;it!=s[p].end();it++)
            {
                if(*it>r)
                    break;
                a[*it]/=p;
                if(a[*it]%p)
                    del.push_back(*it);
            }
            for(i=0;i<del.size();i++)
            {
                s[p].erase(del[i]);
            }

        }
    }
    for(i=0;i<n;i++)
        cout<<a[i]<<" ";
    cout<<endl;
    return(0);

}
