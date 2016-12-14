#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    int N,i,x1,y1,x2,y2,x3,y3,x4,y4,j,coun;
    set< pair<int,int> > points;
    cin>>N;
    int x[N+1],y[N+1];
    for(i=0;i<N;i++)
    {
        cin>>x[i]>>y[i];
        points.insert(make_pair(x[i],y[i]));
    }
    if(N==0||N==1||N==2)
    {
        cout<<(4-N)<<endl;
    }
    else
    {   coun=0;
        for(i=0;i<N-1;i++)
        {
            for(j=i+1;j<N;j++)
            {
                pair<int,int>p1,p2,p3,p4;
                p1.first = x[i]-(y[j]-x[j]);
                p1.second = y[i]+(x[j]-x[i]);
                p2.first = x[j]-(y[j]-x[j]);
                p2.second = y[j]+(x[j]-x[i]);
                p3.first = x[i]+(y[j]-x[j]);
                p3.second = y[i]-(x[j]-x[i]);
                p4.first = x[j]+(y[j]-x[j]);
                p4.second = y[j]-(x[j]-x[i]);
                if((points.find(p1)!=points.end()&&points.find(p2)!=points.end())||(points.find(p3)!=points.end()&&points.find(p4)!=points.end()))
                {
                    cout<<"0"<<endl;
                    return(0);
                }
                else if(points.find(p1)!=points.end()||points.find(p2)!=points.end()||points.find(p3)!=points.end()||points.find(p4)!=points.end())
                {
                    coun = 1;
                }

            }
        }
        cout<<(2-coun)<<endl;
    }
    return(0);

}
