#include <iostream>
#include <string>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <queue>
#include <list>
#include <stack>
#include <map>
#include <set>
#include <cmath>
#include <cstdlib>
#define MP make_pair
#define X first
#define Y second
using namespace std;
#define getcx getchar
inline void inp( int &n )//fast input function
{
        n=0;
        int ch=getcx();
        while(  ch >= '0' && ch <= '9' )
                n = (n<<3)+(n<<1) + ch-'0', ch=getcx();
}
typedef struct forest_node_t {
    int value;
    struct forest_node_t* parent;
    int rank;
} forest_node;

forest_node* makeset(int val) {
    forest_node* node = (forest_node *)malloc(sizeof(forest_node));
    node->value = val;
    node->parent = node;
    node->rank = 0;
    return node;
}
forest_node* find(forest_node* node);
void Union(forest_node* node1, forest_node* node2) {
    if (node1->rank > node2->rank) {
        node2->parent = find(node1);
    } else if (node2->rank > node1->rank) {
        node1->parent = find(node2);
    } else {
        node2->parent = find(node1);
        node1->rank++;
    }
}

forest_node* find(forest_node* node) {
	if(node!=node->parent)
		node->parent=find(node->parent);
	return node->parent;
}
bool removed[300000];
pair< int,pair<int,int> > G[300000];
int main()
{
	int V,E,a,b,c,i,j;
	inp(V),inp(E);
	forest_node *S[V+5];
	for(i=0;i<V+2;i++)
	{
		S[i]=makeset(i);
	}
	for(i=0;i<E;i++)
	{
		inp(a),inp(b),inp(c);
		G[i] = MP(c, MP(a,b) );
	}
	sort(G,G+E);
	bool amb=0;
	for(i=0;i<E;i++)
	{
		if(amb)
			break;
		for(j=i;j<E && G[j].X == G[i].X;j++)
		{
			if( find(S[G[j].Y.X]) == find(S[G[j].Y.Y]) )
				removed[j] = 1;
		}
		for(j=i;j<E && G[j].X == G[i].X;j++)
		{
			if(removed[j] == 1)
				continue;
			if( find(S[G[j].Y.X]) == find(S[G[j].Y.Y]) )
			{
				amb=1;
				break;
			}
			else
				Union(S[G[j].Y.X], S[G[j].Y.Y]);
		}
		i=j-1;
	}
	if(amb)
		cout<<"NO\n";
	else
		cout<<"YES\n";
	return 0;
}
