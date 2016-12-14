    #include <bits/stdc++.h>
    #define mod 1000000007
    using namespace std;
    int main()
    {
        ios_base::sync_with_stdio(false);cin.tie(0);
        int N;
        unsigned long long t = (720*mod),res,temp;
        cin>>N;
        if(N<13)
        {
            cout<<"0"<<endl;
            return(0);
        }
        N = N-13;
        N = N/2+6;
        int pow2 = 4;
	int pow3 = 2;
	int pow5 = 1;

	long long P = 1;
	int i = 0;
	long long n;
	for (i = 0; i < 6; ++i)					//Calculating (N+6)C6
	{
		n = N--;
		while(pow2 && (n&1)==0)
		{
			n = n>>1;	// =n/2
			--pow2;
		}
		while(pow3 && n%3==0)
		{
			n /= 3;
			--pow3;
		}
		if(pow5 && n%5==0)
		{
			n/=5;
			pow5=0;
		}
		P = (P*n) % mod;
	}
	cout<<P<<endl;
        return(0);

    }
