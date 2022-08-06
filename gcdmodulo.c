//EUCLIDs algorithm based on modulo operation to find Gcd of 2 non-negative numbers.

#include<stdio.h>

int main()
{
    int m,n,rem,count=0,gcd;
    printf("Enter 2 non-negative numbers\n");
    scanf("%d %d",&m,&n);
    while(n!=0)
    {
        rem=m%n;
        count++;
        m=n;
        n=rem;
    }
    gcd=m;
    printf("The gcd of the 2 numbers is %d\n",gcd);
    printf("The count is %d\n",count);
    return 0;
}
