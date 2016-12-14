#include <bits/stdc++.h>
using namespace std;
struct item
{
    long long c,h,e,f;
};
int main()
{
    ios_base::sync_with_stdio(false);
    struct item *a = (struct item*)malloc(1000001*sizeof(struct item));
    struct item **b = (struct item**)malloc(1000001*sizeof(struct item*));
    string s;
    long long res;
    char x,y;
    long long q,l,r,i,j;
    for(i=0;i<1000001;i++)
    {
       b[i] = (struct item*)malloc(3*sizeof(struct item));
    }
    cin>>s;
    cin>>q;
    a[0].c=0;a[0].h=0;a[0].e=0;a[0].f=0;
    for(i=0;i<s.size();i++)
    {
        a[i+1].c=a[i].c;
        a[i+1].h=a[i].h;
        a[i+1].e=a[i].e;
        a[i+1].f=a[i].f;
        if(s[i]=='c')
            a[i+1].c = a[i+1].c + 1;
        else if(s[i]=='h')
            a[i+1].h = a[i+1].h + 1;
        else if(s[i]=='e')
            a[i+1].e = a[i+1].e + 1;
        else
            a[i+1].f = a[i+1].f + 1;
    }
    /*for(i=0;i<=s.size();i++)
    {
        cout<<a[i].c<<" "<<a[i].h<<" "<<a[i].e<<" "<<a[i].f<<endl;
    }*/
    for(i=0;i<3;i++)
    {
        b[0][i].c=0;b[0][i].h=0;b[0][i].e=0;b[0][i].f=0;
    }

    for(i=0;i<s.size();i++)
    {
        for(j=0;j<3;j++)
        {
            b[i+1][j].c=b[i][j].c;b[i+1][j].h=b[i][j].h;b[i+1][j].e=b[i][j].e;b[i+1][j].f=b[i][j].f;
        }
        if(s[i]=='c' && i>0)
        {
            b[i+1][0].c = b[i][0].c+a[i].h-a[0].h;
            b[i+1][1].c = b[i][1].c+a[i].e-a[0].e;
            b[i+1][2].c = b[i][2].c+a[i].f-a[0].f;
        }
        else if(s[i]=='h' && i>0)
        {
            b[i+1][0].h = b[i][0].h+a[i].c-a[0].c;
            b[i+1][1].h = b[i][1].h+a[i].e-a[0].e;
            b[i+1][2].h = b[i][2].h+a[i].f-a[0].f;
        }
        else if(s[i]=='e' && i>0)
        {
            b[i+1][0].e = b[i][0].e+a[i].c-a[0].c;
            b[i+1][1].e = b[i][1].e+a[i].h-a[0].h;
            b[i+1][2].e = b[i][2].e+a[i].f-a[0].f;
        }
        else if(s[i]=='f' && i>0)
        {
            b[i+1][0].f = b[i][0].f+a[i].c-a[0].c;
            b[i+1][1].f = b[i][1].f+a[i].h-a[0].h;
            b[i+1][2].f = b[i][2].f+a[i].e-a[0].e;
        }
    }
    /*for(i=0;i<=s.size();i++)
    {
        cout<<b[i][0].f<<endl;
    }*/
    while(q--)
    {

        cin>>x>>y>>l>>r;
        res=0;
        //cout<<x<<endl<<y<<endl<<l<<endl<<r<<endl;
        if(y=='c')
        {
            if(x=='h')
            {
                res = b[r][0].c-b[l-1][0].c;
                if(l>1)
                    res = res - ((a[l-1].h-a[0].h)*(a[r].c-a[l-1].c));
            }
            else if(x=='e')
            {
                res = b[r][1].c-b[l-1][1].c;
                if(l>1)
                    res = res - ((a[l-1].e-a[0].e)*(a[r].c-a[l-1].c));
            }
            else if(x=='f')
            {
                res = b[r][2].c-b[l-1][2].c;
                if(l>1)
                    res = res - ((a[l-1].f-a[0].f)*(a[r].c-a[l-1].c));
            }
        }
        else if(y=='h')
        {
            if(x=='c')
            {
                res = b[r][0].h-b[l-1][0].h;
                if(l>1)
                    res = res - ((a[l-1].c-a[0].c)*(a[r].h-a[l-1].h));
            }
            else if(x=='e')
            {
                res = b[r][1].h-b[l-1][1].h;
                if(l>1)
                    res = res - ((a[l-1].e-a[0].e)*(a[r].h-a[l-1].h));
            }
            else if(x=='f')
            {
                res = b[r][2].h-b[l-1][2].h;
                if(l>1)
                    res = res - ((a[l-1].f-a[0].f)*(a[r].h-a[l-1].h));
            }
        }
        else if(y=='e')
        {
            if(x=='c')
            {
                res = b[r][0].e-b[l-1][0].e;
                if(l>1)
                    res = res - ((a[l-1].c-a[0].c)*(a[r].e-a[l-1].e));
            }
            else if(x=='h')
            {
                res = b[r][1].e-b[l-1][1].e;
                if(l>1)
                    res = res - ((a[l-1].h-a[0].h)*(a[r].e-a[l-1].e));
            }
            else if(x=='f')
            {
                res = b[r][2].e-b[l-1][2].e;
                if(l>1)
                    res = res - ((a[l-1].f-a[0].f)*(a[r].e-a[l-1].e));
            }
        }
        else if(y=='f')
        {

            if(x=='c')
            {
                res = b[r][0].f-b[l-1][0].f;
                if(l>1)
                    res = res - ((a[l-1].c-a[0].c)*(a[r].f-a[l-1].f));
            }
            else if(x=='h')
            {
                res = b[r][1].f-b[l-1][1].f;
                if(l>1)
                    res = res - ((a[l-1].h-a[0].h)*(a[r].f-a[l-1].f));
            }
            else if(x=='e')
            {
                res = b[r][2].f-b[l-1][2].f;
                if(l>1)
                    res = res - ((a[l-1].e-a[0].e)*(a[r].f-a[l-1].f));
            }
        }
        printf("%lld\n",res);
    }
return(0);
}
