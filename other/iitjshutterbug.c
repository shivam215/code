#include <stdio.h>
int main()
{
    int T,i,p,j,k,l;
    char a[10000],b[10000],c[10000];
    scanf("%d",&T);
    for(i=1;i<=T;i++)
    {   j=0;k=0;l=0;
        scanf("%s",a);
        scanf("%s",b);
        while(a[j]!='\0' && b[k]!='\0')
        {
            if(a[j]=='m'&&b[k]=='m')
                {c[l]='m';
                }
            else if(a[j]=='b'&&b[k]=='b')
            {
                c[l]='b';
            }
            else if(a[j]=='b'&&b[k]=='w')
            {
                c[l] = 'w';
            }
            else if(a[j]=='w'&&b[k]=='b')
            {
                c[l]='w';
            }
            else
            {
                c[l]='w';
            }
            j++;
            k++;
            l++;
        }
        c[l]='\0';
        p=1;
        if(c[p]=='\0')
        {
            printf("%c",c[p-1]);
            printf("\n");
            continue;
        }
        while(c[p+1]!='\0')
        {
            if(c[p]!=c[p+1])
                break;
            p++;
        }
        if(c[p+1]=='\0')
        {
            printf("%c",c[p]);
            printf("\n");
            continue;
        }
        p=0;


        while(c[p]!='\0')
        {
            printf("%c",c[p]);
            p++;
        }
        printf("\n");

    }
    return(0);
}
