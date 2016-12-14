#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <string.h>
struct stack
{
    int top;
    unsigned capacity;
    int* array;
};
struct stack* createstack(unsigned capacity)
{
    struct stack* s = (struct stack*)malloc(sizeof(struct stack));
    s->top = -1;
    s->capacity = capacity;
    s->array = (int*)malloc(sizeof(s->capacity*sizeof(int)));
    return s;
};
int isfull(struct stack* s)
{
    return(s->top == s->capacity-1);
}
int isempty(struct stack* s)
{
    return(s->top == -1);
}
void push(struct stack* s, char item)
{
    if(isfull(s))
        return;
    s->top = s->top + 1;
    s->array[s->top] = item;
    printf("%c pushed to stack\n", item);
}
int pop(struct stack* s)
{
    if(isempty(s))
    {
        return INT_MIN;
    }
    return(s->array[s->top--]);

}
int peek(struct stack* s)
{
    if(isempty(s))
        return INT_MIN;
    return(s->array[s->top]);
}
int isoperand(char ch)
{
    return (ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z');
}
int prec(char ch)
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
void infixtopostfix(char exp[])
{   struct stack* s = createstack(strlen(exp));
    int i = 0,k;
    for(i=0,k=-1;exp[i];i++)
    {
        if(isoperand(exp[i]))
            exp[++k] = exp[i];
        else if(exp[i]=='(')
                push(s,exp[i]);
        else if(exp[i]==')')
        {
            while((!isempty(s))&& peek(s)!=exp[i])
            {
                exp[++k] = pop(s);
            }
            if (!isempty(s) && peek(s) != '(')
                return -1; // invalid expression
            else
                pop(s);
        }
        else
        {
            while(!isempty(s) && prec(peek(s))>=prec(exp[i]))
                exp[++k] = pop(s);
            push(s,exp[i]);
        }
        }
        while(!isempty(s))
            exp[++k]=pop(s);
        exp[++k]='\0';
        printf("%s",exp);
}
int main()
{
    char exp[] = "a+b*(c^d-e)^(f+g*h)-i";
    infixtopostfix(exp);
    return 0;
}

