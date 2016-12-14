#include <bits/stdc++.h>
using namespace std;
#define MAXN 200006

int N, gap;
string s;
int SA[MAXN], pos[MAXN], tmp[MAXN], lcp[MAXN];

bool sufCmp(int i, int j)
{
    if (pos[i] != pos[j])
        return pos[i] < pos[j];
    i += gap;
    j += gap;
    return (i <= N && j <= N) ? pos[i] < pos[j] : i > j;
}

void create_SA()
{
    for(int i=1; i<=N; ++i) SA[i] = i, pos[i] = s[i-1]-'a'+1;
    tmp[1]=1;
    for (gap = 1;; gap *= 2)
    {
        sort(SA+1, SA + N +1, sufCmp);
        for(int i=1; i<=N-1; ++i) tmp[i + 1] = tmp[i] + sufCmp(SA[i], SA[i + 1]);
        for(int i=1; i<=N; ++i) pos[SA[i]] = tmp[i];
        if (tmp[N] == N) break;
    }
}

void buildLCP()
{
    for (int i = 1, k = 0; i <= N; ++i) if (pos[i] != N)
        {
            for (int j = SA[pos[i] + 1]; s[i + k -1] == s[j + k -1];)
                ++k;
            lcp[pos[i]+1] = k;
            if (k)--k;
        }
}
int main()
{

    cin>>s;
    N =s.size();
    create_SA();
    buildLCP();
    //for(int i=1;i<=N;i++)cout<<SA[i]<<endl;
    for(int i=1;i<=N;i++)cout<<lcp[i]<<endl;
    return 0;
}

