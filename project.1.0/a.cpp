#include<stdio.h>
#include<iostream>
int main(void)
{
    int dividor_sum=0;
    int sum=0;

    for(int n=1;n<=1000;++n)
    {
        int i=0;
        for(int d=1;d<n;++d)
        {
            if(n%d==0)
                dividor_sum+=d;
        }
        if(dividor_sum==n)
        printf("%d\n",n);
    }
    return 0;
}