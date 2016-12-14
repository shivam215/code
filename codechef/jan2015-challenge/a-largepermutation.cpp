#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t,n,k,i,flag;
    long long sum,temp;
    cin>>t;
    while(t--)
    {
        cin>>n>>k;
        sum = (n*(n+1))/2;
        long long a[k];
        for(i=0;i<k;i++)
        {
            cin>>a[i];
        }
        if(k==0)
        {
            if(sum&1)
                cout<<"Mom"<<endl;
            else
                cout<<"Chef"<<endl;
            continue;
        }
        sort(a,a+k);
        temp = (a[0]*(a[0]-1))/2;
        flag=0;
        if(a[0]>temp)
        {
            if(a[0]&1)
                cout<<"Chef"<<endl;
            else
                cout<<"Mom"<<endl;
            continue;
        }
        for(i=1;i<k;i++)
        {
            //cout<<a[i]<<'\t'<<temp<<endl;
            if(a[i]==a[i-1]+1)
            {
                if(a[i]>temp)
                {
                    if(a[i]&1)
                        cout<<"Chef"<<endl;
                    else
                        cout<<"Mom"<<endl;
                    //cout<<temp;
                    flag=1;
                    break;
                }
            }
            else
            {
                temp = ((a[i]*(a[i]-1))/2)-((a[i-1]*(a[i-1]+1))/2)+temp;
                //cout<<temp<<a[i];
                if(a[i]>temp)
                {
                    if(a[i]&1)
                        cout<<"Chef"<<endl;
                    else
                        cout<<"Mom"<<endl;
                    cout<<temp;
                    flag=1;
                    break;
                }
            }
        }
        if(flag==1)
            continue;
        else
        {
            i--;
            if(a[i]!=n)
            {
                temp = temp + sum - (a[i]*(a[i]+1))/2;
            }
            //cout<<temp<<endl;
            if(temp&1)
                cout<<"Mom"<<endl;
            else
                cout<<"Chef"<<endl;
            continue;
        }
    }
    return(0);
}
