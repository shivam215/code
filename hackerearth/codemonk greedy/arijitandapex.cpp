#include <bits/stdc++.h>
#define pii pair<int,int>
using namespace std;
pair<int,int> x[100005];
pair<int,int> y[100005];
bool comp(pii a, pii b)
{
    if(a.first<b.first)return true;
    else if(a.first==b.first)return a.second<b.second;
    else return false;
}
int main()
{
    ios_base::sync_with_stdio(false);
    int t,i,j,n,m;
    cin>>t;
    while(t--)
    {
        cin>>m>>n;
        for(i=0;i<m;i++) cin>>y[i].first>>y[i].second;
        for(i=0;i<n;i++) cin>>x[i].first>>x[i].second;

        int gin,hin;
        cin>>gin>>hin;
        sort(x,x+n,comp);
        sort(y,y+m,comp);
        i=0;j=0;
        int g=0,h=0;
        int flag=0;
        while(i<n && j<m)
        {
            if(x[i].first==y[j].first)
            {
                if(x[i].second==y[j].second){i++;j++;g++;h++;}
                else
                {
                    if(x[i].second<y[j].second)
                    {
                        flag=1;
                        i++;
                    }
                    else
                    {
                        flag=1;
                        j++;
                    }
                }

            }
            else
            {
                if(flag){g++;flag=0;}
                if(x[i].first<y[j].first)
                {
                    i++;
                }
                else if(x[i].first>y[j].first)
                {
                    j++;
                }
            }
        }
        if(flag)g++;
        if(g>=gin && h>=hin)printf("Great\n");
        else if(g>=gin)printf("Good\n");
        else printf(":(\n");
    }
    return 0;
}
