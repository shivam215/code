#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);
    int t,n,f,s,i;
    long long bomb,fir,sec;
    vector < pair<long long,long long> > v;
    cin>>t;
    while(t--)
    {
        cin>>n;
        v.clear();
        for(i=0;i<n;i++)
        {
            cin>>f>>s;
            v.push_back(make_pair(f,s));
        }
        sort(v.begin(),v.end());
        fir = v[0].first;
        sec = v[0].second;
        bomb = 1;
        for(i=1;i<n;i++)
        {
            if(v[i].first<=sec)
            {
                fir = max(fir,v[i].first);
                sec = min(sec,v[i].second);
            }
            else
            {
                bomb++;
                fir = v[i].first;
                sec = v[i].second;
            }
        }
        cout<<bomb<<endl;

    }
    return(0);
}
