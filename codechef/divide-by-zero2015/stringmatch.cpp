#include<bits/stdc++.h>
using namespace std;

// concept of z function algorithm to obtain O(n) time

int z[1000005]={0} ;
int n;// string length
int k ;
int coun[1000005]={0};

char s[1000005] ;

void  z_function () {


	for (int i=1, l=0, r=0; i<n; ++i) {

		 if (i <= r)  z[i] = min (r-i+1, z[i-l]);

		while ( i+z[i] < n && s[z[i]] == s[i+z[i]] ) ++z[i];


		if (i+z[i]-1 > r) 	l = i,  r = i+z[i]-1;

	}

}


int main()
{ int i ;

     cin >> n ;
	scanf("%s",s);
cin >> k;

	z_function();

	if(k==1)
	{   cout<<n<<endl;
		printf("%s",s);
		return 0;
	}

	for(i=0;i<n;i++)  coun[z[i]] ++ ;

	//for(i=1;i<n;i++) cout<<z[i]<<" " ;
	//cout<<endl;
	// coun[i] stores I WON`T TELL :p

	int len = 0 , value = 0;
       k--;

	for(len=n;len>=0;len--)
	{

		value += coun[len];
	 if(value>=k) break;
	}

	cout<<len<<endl;
	s[len]='\0';
	printf("%s\n",s);




	return 0;

}
