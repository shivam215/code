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
int isOperand(char ch)
{
    return (ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z');
}

int Prec(char ch)
{
    switch (ch)
    {
    case '+':
    case '-':
        return 1;

    case '*':
    case '/':
        return 2;

    case '^':
        return 3;
    }
    return -1;
}
int infixToPostfix(char* exp)
{
    int i, k;

    // Create a stack of capacity equal to expression size
    stack<char> st;
    for (i = 0, k = -1; exp[i]; ++i)
    {
         // If the scanned character is an operand, add it to output.
        if (isOperand(exp[i]))
            exp[++k] = exp[i];

        // If the scanned character is an ‘(‘, push it to the stack.
        else if (exp[i] == '(')
            st.push(exp[i]);

        //  If the scanned character is an ‘)’, pop and output from the stack
        // until an ‘(‘ is encountered.
        else if (exp[i] == ')')
        {
            while (!st.empty() && st.top()!= '(')
                {exp[++k] = st.top();st.pop();}
            if (!st.empty() && st.top() != '(')
                return -1; // invalid expression
            else
                st.pop();
        }
        else // an operator is encountered
        {
            while (!st.empty() && Prec(exp[i]) <= Prec(st.top()))
                {exp[++k] = st.top();st.pop();}
            st.push(exp[i]);
        }

    }

    // pop all the operators from the stack
    while (!st.empty())
        {exp[++k] = st.top();st.pop();}

    exp[++k] = '\0';
    printf( "%s\n", exp );
}

int main()
{
    int t;
    char s[1000];
    cin>>t;
    while(t--)
    {
        cin>>s;
        infixToPostfix(s);
    }
    return 0;
}
