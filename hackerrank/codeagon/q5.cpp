#include <bits/stdc++.h>
#define lld unsigned long long
#define pii pair<int,int>
using namespace std;

lld k,n;
lld tree[600000],arr[200005];
lld mulmod(lld a, lld b)
{
    if(a<=1000000000ULL && b<=1000000000ULL)
        return (a*b)%k;
    lld res=0;
    a = a%k;
    while(b>0)
    {
        if(b&1)
        {
            res = res + a;
        if(res>=k)res=res-k;
        }
        a = (a<<1);
        if(a>=k)a=a-k;
        b>>=1;
    }
    return res%k;

}
void build_tree(int node, int a, int b) {
    if(a > b) return; // Out of range

  	if(a == b) { // Leaf node
    		tree[node] = arr[a]; // Init value
		return;
	}

	build_tree(node*2, a, (a+b)/2); // Init left child
	build_tree(node*2+1, 1+(a+b)/2, b); // Init right child

	tree[node] = mulmod(tree[node*2],tree[node*2+1]); // Init root value
}

lld query_tree(int i,int si,int sj,int qi,int qj){
	if(si==qi and sj==qj){
		return tree[i];
	}
	int mid = (si+sj)/2;
	if(qj<=mid)
		return query_tree(2*i,si,mid,qi,qj);
	else
		if(mid+1<=qi)
			return query_tree(2*i+1,mid+1,sj,qi,qj);
	else
		return mulmod(query_tree(2*i,si,mid,qi,mid),query_tree(2*i+1,mid+1,sj,mid+1,qj));
}

int main()
{
    scanf("%lld%lld",&k,&n);
    lld x;
    for(int i=0;i<n;i++)
    {
        scanf("%lld",&x);
        arr[i] = __gcd(x,k)%k;
    }
    build_tree(1,0,n-1);
    int low=1,high=n,flag,mid;
    while(low<high)
    {
        mid = (low+high)/2;
        flag=0;
        for(int i=0;i<=n-mid;i++)
        {
            lld temp = query_tree(1,0,n-1,i,i+mid-1);
            if(temp==0)
            {
                flag=1;break;
            }

        }
        if(flag)high=mid;
        else low = mid+1;
    }
    flag=0;
    vector< pii > ans;
    for(int i=0;i<=n-high;i++)
        {
            lld temp = query_tree(1,0,n-1,i,i+high-1);

            if(temp==0)
            {
                flag=1;
                ans.push_back(pii(i,i+high-1));
            }

        }
        if(flag)
        {
            printf("Minimum interval length: %d\n",high);
            printf("Found intervals:\n");
            for(int i=0;i<ans.size();i++)
            {
                printf("[%d, %d]\n",ans[i].first+1,ans[i].second+1);
            }
        }
        else
        {
            printf("NONE\n");
        }
        return 0;
}
