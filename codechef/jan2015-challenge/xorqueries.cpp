#include <bits/stdc++.h>
using namespace std;
int main()
{
    int m,x,type,l,r,i,temp,j;
    vector<int> v;
    cin>>m;
    while(m--)
    {
        cin>>type;
        if(type==0 || type==2)
        {
            cin>>x;
            if(type==0)
                v.push_back(x);
            else
                v.erase(v.end()-x,v.end());
        }
        else
        {
            cin>>l>>r>>x;
            l--;r--;
            if(type==1)
            {
                temp = v[l]^x;
                j=l;

                for(i=l+1;i<=r;i++)
                {
                    if((v[i]^x)>temp)
                    {
                        temp = v[i]^x;
                        j = i;
                    }
                }
                cout<<v[j]<<endl;
            }
            else if(type==3)
            {
                int coun=0;
                for(i=l;i<=r;i++)
                {
                    if(v[i]<=x)
                        coun++;
                }
                cout<<coun<<endl;
            }
            else
            {
                vector<int> a;
                for(i=l;i<=r;i++)
                {
                    a.push_back(v[i]);
                }
                sort(a.begin(),a.end());
                x--;
                cout<<a[x]<<endl;
            }

        }
    }
    return(0);
}
