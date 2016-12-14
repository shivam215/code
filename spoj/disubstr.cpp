#include <bits/stdc++.h>
#define scano(x) scanf("%d",&x)
#define scant(x,y) scanf("%d%d",&x,&y)
#define pb push_back
#define mp make_pair
#define ll long long
#define vi vector<int>
#define pii pair<int,int>
#define vpii vector< pii >
#define rep(i,a,b) for(int i=a;i<b;i++)
using namespace std;
int ans;
struct trie* head;
char s[1010];
struct trie
{
    struct trie* next[26];
};
void insert_trie(char *s)
{
    struct trie* cur = head;
    for(int i=0;s[i];i++)
    {
        if(!cur->next[s[i]-'A'])
        {
            ans++;
            cur->next[s[i]-'A'] = new trie;
        }
        cur = cur->next[s[i]-'A'];
    }
}
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%s",s);
        ans=0;
        head = new trie;
        for(int i=0;s[i];i++)
        {
            insert_trie(s+i);
        }
        printf("%d\n",ans);
    }
    return 0;
}
