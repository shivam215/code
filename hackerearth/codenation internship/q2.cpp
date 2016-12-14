#include<bits/stdc++.h>
using namespace std;

typedef long long  ll;
typedef unsigned long long  ull;

ll mod= 1000000007;

#define fast      ios_base::sync_with_stdio(false);
#define frmlty     int test_case;cin>>test_case;while(test_case--)

#define vi        vector<int>
#define vs        vector<string>
#define vll       vector<ll>
#define pii       pair<int,int>

#define msi       map<string,int>
#define msit      map<string,int>::iterator
#define pb        push_back
#define mp        make_pair

#define loop(i,a,b)      for(ll i=a;i<b;i++)
#define rloop(i,a,b)     for(int i=b-1;i>=a;i--)

#define gcd(a,b)  __gcd(a,b)
#define maX(a,b)                     ( (a) > (b) ? (a) : (b))
#define miN(a,b)                     ( (a) < (b) ? (a) : (b))

#define le(x) scanf("%d",&x);
#define le2(x,y) scanf("%d%d",&x,&y);
#define lell(x) scanf("%lld",&x);
#define le2ll(x,y) scanf("%lld%lld",&x,&y);

struct node
{
    int ifend;//1 means its ending point
    int prefixcount;//for finding number of string having this prefix
    node *child[26];//we are storing only lower case letter
};

node *head=NULL;

node *newnode()
{
    node *n=new node();
    n->ifend=0;
    n->prefixcount=0;
    loop(i,0,26)
    n->child[i]=NULL;
    return n;
}

void insert1(string s)
{
    node *current=head;
    current->prefixcount++;//it count total number of strings in trie

    loop(i,0,s.length())
    {
        if(current->child[s[i]-97]==NULL)
            current->child[s[i]-97]=newnode();
        current->child[s[i]-97]->prefixcount++;//this string s having prefix this one so add
        current=current->child[s[i]-97];//now current point to newly node
    }
    current->ifend=1;
}

int search1(string s)
{
    node *current=head;


    loop(i,0,s.length())
    {
        if(current->child[s[i]-97]==NULL)
            return 0;
        current=current->child[s[i]-97];
    }
    return (current->ifend==1);

}

int prefixc(string prefix)
{
    node *current=head;
    loop(i,0,prefix.length())
    {
        if(current->child[prefix[i]-97]==NULL)
            return 0;
        current=current->child[prefix[i]-97];

    }
    return current->prefixcount;
}



int main()
{
    //making trie
    head=newnode();

    //head node formed means empty trie gwt formed
    while(true)
    {
        string s,s1;
        cin>>s;
        if(s=="insert")
        {
            cin>>s1;
            insert1(s1);
        }
        if(s=="search")
        {
            cin>>s1;
            cout<<search1(s1)<<endl;
        }

        if(s=="count")
        {
            cin>>s1;
            cout<<prefixc(s1)<<endl;

        }
    }


    return 0;
}
