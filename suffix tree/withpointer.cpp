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
char s[1010],pat[1010];
struct trie
{
    struct trie* next[200];
};
void insert_trie(char *s)
{
    struct trie* cur = head;
    for(int i=0;s[i];i++)
    {
        if(!cur->next[s[i]])
        {
            cur->next[s[i]] = new trie;
        }
        cur = cur->next[s[i]];
    }
}
int search_trie(char *s)
{
    struct trie* cur = head;
    int flag=0;
    for(int i=0;s[i];i++)
    {
        if(cur->next[s[i]])
        {
            cur = cur->next[s[i]];
        }
        else
        {
            flag=1;
            break;
        }
    }
    if(flag)return 0;
    return 1;
}
int main()
{
    scanf("%s",pat);

    freopen("file.in","r",stdin);
    freopen("file.out","w",stdout);
    scanf("%s",s);

    head = new trie;
    for(int i=0;s[i]; i++)
    {
        insert_trie(s+i);
    }
    if(search_trie(pat))printf("pattern found\n");
    else printf("pattern not found");
    return 0;
}
