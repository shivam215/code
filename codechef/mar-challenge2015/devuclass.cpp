#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    int t,type,i,res1,res2,res;
    string s;
    cin>>t;
    while(t--)
    {
        cin>>type;
        cin>>s;
        int a=0,b=0;
        for(i=0;i<s.size();i++)
        {
            if(s[i]=='B')a++;
            else b++;
        }
        if(abs(a-b)>1)
        {
            cout<<"-1"<<endl;
            continue;
        }
        if(type==0)
        {
            res1=0,res2=0,res;
            if(a>=b)
            {
                for(i=0;i<s.size();i++)
                {
                    if(i&1)
                    {
                        if(s[i]!='G')res1++;
                    }
                    else
                    {
                        if(s[i]!='B')res1++;
                    }
                }
                res1=res1/2;
                if(a>b)res=res1;
            }
            if(a<=b)
            {
                for(i=0;i<s.size();i++)
                {
                    if(i&1)
                    {
                        if(s[i]!='B')res2++;
                    }
                    else
                    {
                        if(s[i]!='G')res2++;
                    }
                }
                res2=res2/2;
                if(a<b)res=res2;
            }
            if(a==b)res=min(res1,res2);
            cout<<res<<endl;
        }
        if(type==1||type==2)
        {
           set<int> s1,s2;
           set<int>::iterator it1,it2;
           s1.clear();s2.clear();
           res1=0;res2=0;
           if(a>=b)
            {
                for(i=0;i<s.size();i++)
                {
                    if(i&1)
                    {
                        if(s[i]!='G')s1.insert(i);
                    }
                    else
                    {
                        if(s[i]!='B')s2.insert(i);
                    }
                }
                for(it1=s1.begin(),it2=s2.begin();it1!=s1.end(),it2!=s2.end();++it1,++it2)
                {
                    res1 = res1 + abs(*it1-*it2);
                }
                if(a>b)res=res1;
            }
            s1.clear();s2.clear();
            if(a<=b)
            {
                for(i=0;i<s.size();i++)
                {
                    if(i&1)
                    {
                        if(s[i]!='B')s1.insert(i);
                    }
                    else
                    {
                        if(s[i]!='G')s2.insert(i);
                    }
                }
                for(it1=s1.begin(),it2=s2.begin();it1!=s1.end(),it2!=s2.end();++it1,++it2)
                {
                    //cout<<*it1<<' '<<*it2<<endl;
                    res2 = res2 + abs(*it1-*it2);
                }

                if(a<b)res=res2;
            }
            if(a==b)res=min(res1,res2);
            cout<<res<<endl;
        }

    }
    return 0;
}
