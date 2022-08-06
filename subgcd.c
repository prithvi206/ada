//Euclid modified agorithm based on subtraction
#include<stdio.h>

int main()
{
    int m,n,gcd,count=0;
    printf("Enter 2 numbers:\n");
    scanf("%d %d",&m,&n);
    while(m!=n)
    {
        if(m>n)
        {
            m=m-n;
        }
        else
        {
        n=n-m;
        }
        count++;
    }
    gcd=m;
    printf("The gcd is %d\n",gcd);
    printf("Te count is %d\n",count);
    return 0;

}