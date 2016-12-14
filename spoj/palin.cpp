#include <bits/stdc++.h>
#define scanint(x) scanf("%d",&x)
#define scanll(x) scanf("%lld",&x)
#define pb push_back
#define mp make_pair
#define ll long long
#define vi vector<int>
#define pii pair<int,int>
#define vpii vector< pii >
#define rep(i,a,b) for(int i=a;i<b;i++)
using namespace std;
string num;
int n;
int AreAll9s()
{
    int i;
    for( i = 0; i<n; ++i )
        if( num[i] != '9' )
            return 0;
    return 1;
}
void generateNextPalindromeUtil ()
{
    int mid = n/2;
    bool leftsmaller = false;
    int i = mid - 1;
    int j = (n % 2)? mid + 1 : mid;
    while (i >= 0 && num[i] == num[j])
        i--,j++;
    if ( i < 0 || (int)(num[i]) < (int)(num[j]))
        leftsmaller = true;
    while (i >= 0)
    {
        num[j] = num[i];
        j++;
        i--;
    }
    if (leftsmaller == true)
    {
        int carry = 1;
        i = mid - 1;
        if (n%2 == 1)
        {
            num[mid] = (char)((int)num[mid]+carry);
            carry = (num[mid]-'0')/ 10;
            int temp = num[mid]-'0';
            temp%=10;
            num[mid] = (char)(temp+'0');
            j = mid + 1;
        }
        else
            j = mid;
        while (i >= 0)
        {
            num[i] = (char)((int)num[i]+carry);
            carry = (num[i]-'0')/ 10;
            int temp = num[i]-'0';
            temp%=10;
            num[i] = (char)(temp+'0');
            num[j++] = num[i--]; // copy mirror to right
        }
    }
}
void generateNextPalindrome()
{
    int i;
    if( AreAll9s() )
    {
        printf( "1");
        for( i = 1; i < n; i++ )
            printf( "0" );
        printf( "1\n" );
    }
    else
    {
        generateNextPalindromeUtil ();
        cout<<num<<"\n";
    }
}
int main()
{
    int t;
    scanint(t);
    while(t--)
    {
        cin>>num;
        n = num.size();
        generateNextPalindrome();
    }
    return 0;
}
